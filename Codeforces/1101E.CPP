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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int maxx = -1, maxy = -1;
    while(n--){
        char opt;
        int x, y;
        cin>>opt>>x>>y;
        if(opt == '+'){
            maxx = max(maxx, min(x, y));
            maxy = max(maxy, max(x, y));
        }
        else cout<<((maxx <= min(x, y) && maxy <= max(x, y)) ? "YES" : "NO")<<el;
    }
    return 0;
}