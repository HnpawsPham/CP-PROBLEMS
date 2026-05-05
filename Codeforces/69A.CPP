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
    int x = 0, y = 0, z = 0;
    while(n--){
        int a, b, c;
        cin>>a>>b>>c;
        x += a;
        y += b;
        z += c;
    }
    if(x == y && y == z && z == 0) return "YES";
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

    // cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}