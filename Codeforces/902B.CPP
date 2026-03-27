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

int n, cnt = 1;
const int maxn = 1e4 + 4;
vi a[maxn];
int b[maxn];

void dfs(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        if(b[v] != b[u]) cnt++;    
        dfs(v, u);
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
    for(int i = 2; i <= n; i++){
        int x;
        cin>>x;
        a[i].push_back(x);
        a[x].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin>>b[i];

    dfs(1, 0);
    cout<<cnt;
    return 0;
}