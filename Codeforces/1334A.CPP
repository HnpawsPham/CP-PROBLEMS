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

string sol(){
    int n;
    cin>>n;
    int preva, prevb, a, b;
    bool ok = 1;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        if(b > a) ok = 0;
        
        if(i == 0){
            preva = a;
            prevb = b;
            continue;
        }
        
        if(a < preva || b < prevb) ok = 0;
        if(b - prevb > a - preva) ok = 0;

        preva = a;
        prevb = b;
    }
    return (ok ? "YES" : "NO");
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
        cout<<sol()<<el;
    }
    return 0;
}