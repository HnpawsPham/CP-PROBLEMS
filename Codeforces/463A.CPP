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

int n, s, x, y;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int maxx = -1;
    while(n--){
        cin>>x>>y;

        if(x < s && y > 0)
            maxx = max(maxx, 100 - y);

        else if(x <= s && y == 0)
            maxx = max(maxx, 0);
    }
    cout<<maxx;
    return 0;
}

// 1 10
// 10 10