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

const int maxn = 40;
int q;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

vi base3(ll x){
    vi res;
    while(x > 0){
        res.push_back(x % 3);
        x /= 3;
    }
    // reverse(res.begin(), res.end());
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        vi a = base3(n);
        
        int pos2 = -1, sz = a.size();
        bool rem = 0;
        for(int i = 0; i < sz; i++)
            if(a[i] == 2){
                pos2 = i;
                rem = 1;
            }
        
        for(int i = 0; i <= pos2; i++)
            a[i] = 0;

        for(int i = pos2 + 1; i < sz; i++){
            if(rem){
                a[i]++;
                rem = 0;
            }
            if(a[i] == 2){
                a[i] = 0;
                rem = 1;
            }
        }
        if(rem){
            a.push_back(1);
            sz++;
        }
        // reverse(a.begin(), a.end());
        // for(int x : a) cout<<x<<" ";
        // cout<<el;
        ll res = 0;
        for(int i = 0; i < sz; i++)
            res += ppow(3, i) * a[i];
        cout<<res<<el;
    }
    return 0;
}