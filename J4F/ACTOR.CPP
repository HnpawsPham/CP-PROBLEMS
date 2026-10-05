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

int tc = 1, type;

int sol(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;

    if(type == 1){
        int bad = n - a + n - b + n - c;
        return max(0, n - bad);
    }
    return min(min(a, b), min(b, c));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>type>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}