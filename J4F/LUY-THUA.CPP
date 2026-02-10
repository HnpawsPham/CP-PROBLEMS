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
ll st, en;

ll ppow(ll a, int b){
    ll res = 1;
    for(int i = 0; i < b; i++){
        if(res > en / a) return en + 1;
        res *= a;
    }
    return res;
}

int sol(){
    cin>>st>>en;

    int res = 1;
    for(int k = 41; k >= 2; k--){
        ll l = 2, r = 1e12 + 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            ll tmp = ppow(mid, k);

            if(tmp <= en){
                l = mid + 1;
                if(tmp >= st) return k;
            }
            else r = mid - 1;
        }
    }
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

    cin>>tc;
    for(int i = 1; i <= tc; i++){
        cout<<"Case #"<<i<<": "<<sol()<<el;
    }
    return 0;
}