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
    ll n;
    cin>>n;
    ll delta = 1 - 4 * -2 * n;
    if(delta <= 0) return "NO";

    ll sq = sqrtl(delta);
    if(sq * sq != delta) return "NO";

    if((-sq - 1) / 2 > 0 || (sq - 1) / 2 > 0)
        return "YES";
    return "NO";
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