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

const int maxsz = (1 << 15) + 5;
const int maxn = 18;
vi a[maxn];
bool sub[maxn];

int subsz(int u, int parent){
    int res = 1;
    for(int v : a[u]){
        if(v == parent || !sub[v]) continue;
        res += subsz(v, u);
    }
    return res;
}
int mid = -1;

void dfs(int u, int d, int& maxx, int parent){
    if(d > maxx){
        maxx = d;
        mid = u;
    }
    for(int v : a[u]){
        if(v == parent || !sub[v]) continue;
        dfs(v, d + 1, maxx, u);
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> ed(n, vi(2));
    for(int i = 0; i < n - 1; i++)
        cin>>ed[i][0]>>ed[i][1];

    for(int i = 1; i <= n; i++)
        a[i].clear();

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    int res[n];
    memset(res, 0, sizeof res);

    for(int mask = 0; mask < (1 << n); mask++){
        if(!__builtin_popcount(mask)) continue;
        int cnt = 0;
        memset(sub, 0, sizeof sub);

        int st;
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1){
                sub[i + 1] = 1;
                st = i + 1;
                cnt++;
            }
        if(cnt == 1) continue;
        if(subsz(st, 0) != cnt) continue;
        
        int maxx = -1;
        dfs(st, 0, maxx, 0);
        int d = 0;
        dfs(mid, 0, d, 0);
        res[d]++;
    }

    for(int i = 1; i < n; i++)
        cout<<res[i]<<" ";
    return 0;
}

// 4 
// 1 2
// 2 3
// 2 4