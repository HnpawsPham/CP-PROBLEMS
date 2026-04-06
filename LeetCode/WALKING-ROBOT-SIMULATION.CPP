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

    int n, m;
    cin>>n>>m;
    int a[n];
    vector<vi> b(m, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i][0]>>b[i][1];

    multiset<pii> s;
    for(const vi& v : b)
        s.insert({v[0], v[1]});

    int dir = 0; //0123 DLUR
    int dx[4] = {0, -1, 0, 1},
        dy[4] = {1, 0, -1, 0};

    int x = 0, y = 0, maxx = 0;
    bool first = 1;

    for(int q : a){
        if(q > 0)
            while(q--){
                if(s.find({x + dx[dir], y + dy[dir]}) != s.end()) break;
                x += dx[dir];
                y += dy[dir];
                maxx = max(maxx, x * x + y * y);
            }
        else if(q == -2) dir = (dir + 1) % 4;
        else dir = (dir - 1 + 4) % 4; 
    }
    cout<<max(maxx, x * x + y * y);
    return 0;
}

// 3 0
// 4 -1 3

// 5 1
// 4 -1 4 -2 4
// 2 4