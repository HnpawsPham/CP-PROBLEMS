#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 505;
int a[maxn][maxn];

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

bool bfs(int k){
    queue<pii> q;
    vector<vb> check(n + 1, vb(n + 1, 0));
    q.push({1, 1});
    check[1][1] = 1;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == n && j == n) return 1;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 1 || j1 < 1 || i1 > n || j1 > n || check[i1][j1]) continue;
            int d = abs(a[i][j] - a[i1][j1]);
            if(d <= k) {
                q.push({i1, j1});
                check[i1][j1] = 1;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    int l = 0, r = (int)1e6 + 5;
    while(l <= r){
        int mid = (l + r) / 2;
        if(bfs(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}