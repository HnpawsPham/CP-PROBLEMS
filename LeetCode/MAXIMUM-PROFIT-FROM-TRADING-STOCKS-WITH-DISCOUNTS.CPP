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

int n, s;
const int maxn = 165;
const int oo = 1e5 + 5;
vi a[maxn];
int need[maxn] = {0};
int dp[maxn][maxn][2];

void dfs(int u, int parent, const vi& w, const vi& val){
    for(int i = 0; i <= s; i++)
        dp[u][i][0] = dp[u][i][1] = 0;

    need[u] = w[u]; // need arr de optimize, k co cung dc
    vi split0(s + 1, 0), split1(s + 1, 0);

    for(auto v : a[u]){
        if(v == parent) continue;
        dfs(v, u, w, val);
        need[u] += need[v];

        vi tmp0(s + 1, 0), tmp1(s + 1, 0);

        for(int i = 0; i <= s; i++)
            for(int j = 0; j <= min(i, need[v]); j++){
                tmp0[i] = max(tmp0[i], split0[i - j] + dp[v][j][0]);
                tmp1[i] = max(tmp1[i], split1[i - j] + dp[v][j][1]);
            }
        split0 = tmp0;  
        split1 = tmp1;
    }

    int cost0 = w[u], cost1 = w[u] / 2;
    for(int i = 0; i <= s; i++){
        dp[u][i][1] = dp[u][i][0] = split0[i];

        if(i >= cost0)
            dp[u][i][0] = max(dp[u][i][0], split1[i - cost0] + val[u] - cost0);
        
        if(i >= cost1)
            dp[u][i][1] = max(dp[u][i][1], split1[i - cost1] + val[u] - cost1);
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

    cin>>n>>s;
    vi w(n + 1), val(n + 1);
    vector<vi> ed;
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        ed.push_back({u, v});
    }

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    dfs(1, 0, w, val);
    cout<<dp[1][s][0];
    return 0;
}

// 2 3
// 1 2
// 4 3
// 1 2

// 2 4
// 3 4
// 5 8
// 1 2

// 3 10
// 4 6 8
// 7 9 11
// 1 2
// 1 3

// 3 7
// 5 2 3
// 8 5 6
// 1 2
// 2 3
