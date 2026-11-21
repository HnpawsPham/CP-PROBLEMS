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
const int maxn = 1e5 + 5;
vi a[maxn];
int last[maxn], subsz[maxn];

void change(int u, vi& p, const string& s){
    int tmp = last[s[u] - 'a'];
    if(last[s[u] - 'a'] != -1)
        p[u] = last[s[u] - 'a'];

    last[s[u] - 'a'] = u;
    for(int v : a[u])
        change(v, p, s);
    last[s[u] - 'a'] = tmp;
}

void dfs(int u, int parent){
    subsz[u] = 1;

    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);
        subsz[u] += subsz[v];
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

    string s;
    cin>>n>>s;
    vi p(n);
    for(int i = 0; i < n; i++) cin>>p[i];

    for(int i = 1; i < n; i++)
        a[p[i]].push_back(i);

    memset(last, -1, sizeof last);
    change(0, p, s);

    for(int i = 0; i < n; i++){
        a[i].clear();
        a[p[i]].push_back(i);
    }
    
    dfs(0, -1);
    for(int i = 0; i < n; i++)
        cout<<subsz[i]<<" ";
    return 0;
}

// 6 abaabc
// -1 0 0 1 1 1