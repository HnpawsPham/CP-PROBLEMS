#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second

int n, m, k;
const int maxn = 1e3 + 5;
int a[maxn][maxn];
bool check[maxn][maxn];
vector<pii> q_sorted;
int q[10005];

int dy[4] = {0, -1, 1, 0},
    dx[4] = {-1, 0, 0, 1};

void bfs(int x, int y){
    int point = 0;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({a[0][0], {0, 0}});
    check[0][0] = 1;

    for(pii elm : q_sorted){
        while(!pq.empty() && pq.top().fi < elm.fi){
            piii cur = pq.top();
            pq.pop();

            int i = cur.se.fi, j = cur.se.se;

            point++;

            for(int d = 0; d < 4; d++){
                int i1 = i + dy[d];
                int j1 = j + dx[d];

                if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m || check[i1][j1]) continue;
                pq.push({a[i1][j1], {i1, j1}});
                check[i1][j1] = 1;
            }
        }
        q[elm.se] = point;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = 0; i < k; i++) cin>>q[i];
    for(int i = 0; i < k; i++) q_sorted.push_back({q[i], i});
    sort(q_sorted.begin(), q_sorted.end());

    bfs(0, 0);
    for(int i = 0; i < k; i++) cout<<q[i]<<" ";
    return 0;
}