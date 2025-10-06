#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 55;
int a[maxn][maxn];
int dy[4] = {-1, 1, 0 ,0},
    dx[4] = {0, 0, -1, 1};
bool vis[maxn][maxn];

bool check(int t){
    queue<pii> q;
    memset(vis, 0, sizeof vis);
    q.push({0, 0});
    
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(i == n - 1 && j == i) return 1;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];
            
            if(i1 < 0 || j1 < 0 || i1 == n || j1 == n || vis[i1][j1] || a[i1][j1] > t) continue;
            q.push({i1, j1});
            vis[i1][j1] = 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int l = a[0][0], r = 2505, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}

// 2
// 0 2
// 1 3

// 5
// 0 1 2 3 4
// 24 23 22 21 5
// 12 13 14 15 16
// 11 17 18 19 20
// 10 9 8 7 6