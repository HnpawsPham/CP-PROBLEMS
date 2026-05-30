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
const int maxn = 405;
vi a[maxn];
int dp[maxn];

int dfs(int u){
    if(a[u].empty())
        return dp[u] = 1;

    vi child;
    for(int v : a[u])
        child.push_back(dfs(v));
    sort(child.rbegin(), child.rend());

    int m = child.size();
    int maxx = 0;
    for(int i = 0; i < m; i++)
        maxx = max(maxx, child[i] + i);

    return dp[u] = maxx;
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
    int u, sz, v;
    while(cin>>u>>sz){
        while(sz--){
            cin>>v;
            a[u].push_back(v);
        }
    }

    memset(dp, 0, sizeof dp);
    cout<<dfs(1);
    return 0;
}