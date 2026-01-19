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
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    vi tmp = {a, b, c, d};
    sort(tmp.begin(), tmp.end(), greater<int>());

    if((max(a, b) == tmp[0] || max(a, b) == tmp[1])
     && max(c, d) == tmp[0] || max(c, d) == tmp[1])
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