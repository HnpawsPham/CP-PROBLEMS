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

int n, m;
const int maxn = 1e3 + 5;
int a[maxn][maxn];
bool check[maxn][maxn] = {0};
vi res;

int dy[4]= {-1, 0, 1, 0},
    dx[4] = {0, 1, 0, -1},
    dir[4] = {8, 4, 2, 1};

int dfs(int i, int j){
    int sum = 1;
    check[i][j] = 1;

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];

        if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1]) continue;
        if(!(a[i][j] & dir[x]) && !(a[i1][j1] & dir[(x + 2) % 4]))
            sum += dfs(i1, j1);
    }
    return sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++) cin>>a[i][j];


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!check[i][j])
                res.push_back(dfs(i, j));
                
    sort(res.rbegin(), res.rend());
    for(int x : res) cout<<x<<" ";
    return 0;
}