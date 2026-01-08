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
// #define taskname "DUONGDI"

int n, st, en;
ll res = 0;
const int maxn = 55;
int a[maxn][maxn];
bool check[maxn] = {0};

void dfs(int u){
    if(u == en){
        res++;
        return;
    }

    for(int v = 1; v <= n; v++)
        if(a[u][v] && !check[v]){
            check[v] = 0;
            dfs(v);
            check[v] = 1;
        }
    return;
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
    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    cin>>st>>en;

    check[st] = 1;
    dfs(st);
    cout<<res;
    return 0;
}

// 5 
// 0 1 0 1 1
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// 1 1 0 1 0
// 1 5

// 10
// 1 0 1 0 1 1 1 1 0 1
// 1 0 0 0 1 0 1 1 1 0
// 0 0 1 0 0 1 1 0 0 1
// 1 1 1 0 1 0 1 0 0 1
// 1 1 0 0 0 0 1 0 0 0
// 0 0 1 0 0 1 1 0 1 0
// 0 1 0 0 0 1 1 0 1 0
// 1 1 1 1 1 1 1 0 0 1
// 0 1 1 1 0 0 0 1 1 1
// 0 0 1 1 1 1 0 1 1 0
// 1 7
