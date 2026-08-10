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

int n;
const int maxn = 105;
int a[maxn][maxn];
bool check[maxn][maxn];

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

bool dfs(int i, int j, int minn, int maxx){
    if(i == n - 1 && j == n - 1) return 1;

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];
        
        if(i1 < 0 || j1 < 0 || i1 == n || j1 == n
        || a[i1][j1] < minn || a[i1][j1] > maxx || check[i1][j1])
            continue;

        check[i1][j1] = 1;
        if(dfs(i1, j1, minn, maxx)) 
            return 1;
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int lim = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            lim = max(lim, a[i][j]);
        }

    int res = lim;
    for(int i = 0; i <= a[0][0]; i++){
        int l = a[0][0], r = lim, mid, d = lim;
        while(l <= r){
            mid = (l + r) / 2;

            memset(check, 0, sizeof check);
            check[0][0] = 1;

            if(dfs(0, 0, i, mid)){
                r = mid - 1;
                d = mid - i;
            }
            else l = mid + 1;
        }

        res = min(res, d);
    }
    cout<<res;
    return 0;
}