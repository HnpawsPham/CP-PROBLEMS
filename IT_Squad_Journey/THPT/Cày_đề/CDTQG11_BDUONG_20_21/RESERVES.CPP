#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

struct block{
    int h, i, j;
    block(int h1, int i1, int j1) : h(h1), i(i1), j(j1) {};

    bool operator>(const block& other) const {
        return this-> h > other.h;
    }
};

int n;
const int maxn = 105;
int a[maxn][maxn];
bool check[maxn][maxn];

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

void bfs(){
    ll res = 0;
    priority_queue<block, vector<block>, greater<block>> pq;

    for(int i = 1; i <= n; i++){
        pq.push(block(a[1][i], 1, i));
        pq.push(block(a[i][1], i, 1));
        pq.push(block(a[i][n], i, n));
        pq.push(block(a[n][i], n, i));
        check[1][i] = check[i][1] = check[i][n] = check[n][i] = 1;
    }

    while(!pq.empty()){
        block cur = pq.top();
        pq.pop();

        for(int x = 0; x < 4; x++){
            int i1 = cur.i + dy[x];
            int j1 = cur.j + dx[x];

            if(i1 < 1 || j1 < 1 || i1 > n || j1 > n || check[i1][j1]) continue;
            check[i1][j1] = 1;

            int h1 = max(cur.h, a[i1][j1]);
            res += max(0, h1 - a[i1][j1]);

            pq.push(block(h1, i1, j1));
        }
    }
    cout<<res;
    return;
}

int main(){
    freopen("RESERVES.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    bfs();
    return 0;
}