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

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

struct state{
    int i, j, w, mask, move;
    state(){};
    state(int i1, int j1, int w1, int mask1, int step1) : i(i1), j(j1), w(w1), mask(mask1), move(step1){};
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, h;
    cin>>n>>m>>h;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int stx, sty;
    vector<pii> litter;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'S'){
                stx = i;
                sty = j;
            }
            else if(a[i][j] == 'L')
                litter.push_back({i, j});
        }

    int sz = litter.size();
    int en = (1 << sz) - 1;

    queue<state> q;
    int dis[n][m][en + 1];   
    memset(dis, -1, sizeof dis);

    dis[stx][sty][0] = h; //energy at first
    q.push({stx, sty, h, 0, 0});
 
    while(!q.empty()){
        auto [i, j, w, mask, move] = q.front();
        q.pop();

        if(mask == en) 
            return cout<<move, 0;

        if(w == 0) continue;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i1][j1] == 'X')
                continue;

            int mask1 = mask, w1 = w - 1;
            if(a[i1][j1] == 'L'){
                for(int it = 0; it < sz; it++)
                    if(litter[it].fi == i1 && litter[it].se == j1)
                        mask1 |= (1 << it);
            }
            else if(a[i1][j1] == 'R')
                w1 = h;

            if(w1 > dis[i1][j1][mask1]){
                dis[i1][j1][mask1] = w1;
                q.push({i1, j1, w1, mask1, move + 1});
            }
        }
    }
    cout<<-1;
    return 0;
}

// 2 2 2
// S.
// XL