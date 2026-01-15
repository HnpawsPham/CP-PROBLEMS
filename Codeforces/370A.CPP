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

int x, y, u, v;

bool same(int x, int u){
    return x == u;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>x>>y>>u>>v;
    if(same(x, u) || same(y, v)) 
        cout<<1<<" ";
    else cout<<2<<" ";

    if((x + y) % 2 != (u + v) % 2)  
        cout<<0<<" ";
    else if(abs(x - u) == abs(y - v))
        cout<<1<<" ";
    else cout<<2<<" ";
    
    cout<<max(abs(x - u), abs(y - v));
    return 0;
}