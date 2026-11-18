#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 1e6 + 6;
const int oo = 1e9 + 5;

int dy[] = {0, 0, 1, -1, 1, -1, 1, -1},
    dx[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool topright(int i, int j){
    return i == 0 || j == m - 1;
}

bool botleft(int i, int j){
    return i == n - 1 || j == 0;
}

int sol(){
    vector<vc> a(n, vc(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    if(a[n - 1][m - 1] == '#' || a[0][0] == '#')
        return 0;

    if(a[n - 1][m - 2] == '#' && a[n - 2][m - 1] == '#')
        return 0;

    deque<pii> dq;
    vector<vi> dis(n, vi(m, oo));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(topright(i, j) && a[i][j] != '@'){
                int w = a[i][j] == '.';

                if(w) dq.push_back({i, j});
                else dq.push_front({i, j});
                dis[i][j] = w;
            }

    int cnt = oo;
    while(!dq.empty()){
        auto [i, j] = dq.front();
        dq.pop_front();

        if(botleft(i, j)){
            cnt = min(cnt, dis[i][j]);
            continue;
        }

        for(int x = 0; x < 8; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];
            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i1][j1] == '@')
                continue;
            
            int w = a[i1][j1] == '.';
            if(dis[i1][j1] > dis[i][j] + w){
                dis[i1][j1] = dis[i][j] + w;

                if(w) dq.push_back({i1, j1});
                else dq.push_front({i1, j1});
            }
        }
    }
    return (cnt == oo ? -1 : cnt);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin>>n>>m;
        if(n == 0 && m == 0) break;
        cout<<sol()<<el;
    }
    return 0;
}