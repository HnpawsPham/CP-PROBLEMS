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
//#define taskname ""

int tc = 1;

db sol(){
    db res = 1.0;
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    pair<int, db> b[m];
    for(int i = 0; i < m; i++) 
        cin>>b[i].fi>>b[i].se;

    int last = n;
    while(last > 0 && a[last - 1] == last)
        last--;
    
    if(last == 0) return 1.0;

    for(const auto& x : b){
        if(x.fi >= last)
            res *= (1.0 - x.se);
    } 
    return (1.0 - res);
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
    while(tc--){
        cout<<fixed<<setprecision(6)<<sol()<<el;
    }
    return 0;
}