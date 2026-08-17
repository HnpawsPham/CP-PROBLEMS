#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "NAME_ENAM"

int n;
ll k;
const int maxn = 1e6;
const ll oo = 1e16 + 5;
ll a[maxn];
int b[maxn];
ll minn = oo;

namespace sub2{
    vll div(ll x){
        vll res = {1, x};

        for(ll i = 2; i * i <= x; i++){
            if(x % i) continue;

            res.push_back(i);
            if(i != x / i)
                res.push_back(x / i);
        }
        return res;
    }

    void sol(){
        vll divn[n];
        for(int i = 0; i < n; i++)
            divn[i] = div(a[i]);

        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++){
                bool ok = 0;

                for(const ll& x : divn[i]){
                    for(const ll& y : divn[j]){
                        if(a[i] / x <= k && a[j] / y <= k && __gcd(x, y) == 1){
                            ok = 1;
                            break;
                        }
                    }
                    if(ok) break;
                }
                if(ok) minn = min(minn, 2LL * (b[i] + b[j]));
            }
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    // ll maxx = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] <= k) 
            minn = min(minn, 1LL * b[i]);
        // maxx = max(maxx, a[i]);
    }

    if(n <= 1000)
        sub2::sol();
    cout<<(minn == oo ? -1 : minn);
    return 0;
}

