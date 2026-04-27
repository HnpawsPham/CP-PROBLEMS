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

// u r d l
int open[7][4] = {
    {},
    {0, 1, 0, 1}, 
    {1, 0, 1, 0},
    {0, 1, 1, 0}, 
    {0, 0, 1, 1}, 
    {1, 1, 0, 0},
    {1, 0, 0, 1}
};

int dy[4] = {-1, 0, 1, 0},
    dx[4] = {0, -1, 0, 1};
const int maxn = 305;
bool check[maxn][maxn];

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
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    queue<pair<int, int>> q;
    q.push({0, 0});
    memset(check, 0, sizeof check);
    check[0][0] = 1;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == n - 1 && j == m - 1)
            return cout<<1, 0;

        for(int x = 0; x < 4; x++){
            if(!open[a[i][j]][x]) continue;

            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1]) continue;

            if(open[a[i1][j1]][(x + 2) % 4]){
                q.push({i1, j1});
                check[i1][j1] = 1;
            }
        }
    }
    cout<<0;
    return 0;
}

// 2 3
// 2 4 3
// 6 5 2

// 2 3
// 1 2 1
// 1 2 1