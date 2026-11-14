#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;
const int maxn = 4e6 + 5;
bitset<maxn> nprime;
vll p;
int m;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;

    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) p.push_back(i);
    m = p.size();
}

void sol(){
    ll n;
    int k;
    cin>>n>>k;
    for(int i = m - 1; i >= k - 1; i--){
        ll mul = 1;
        bool ok = 1;
        for(int j = 0; j < k && ok; j++){
            if(p[i - j] > n || p[i - j] > n / mul)
                ok = 0;
            mul *= p[i - j];
        }
        if(ok && mul <= n){
            cout<<mul;
            return;
        }
    }
    cout<<-1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    sieve();
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}