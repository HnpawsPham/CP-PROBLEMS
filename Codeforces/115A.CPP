#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2005;
int a[maxn], d[maxn];

int dfs(int u){
    if(d[u] != -1) return d[u];
    if(a[u] == -1) return d[u] = 1;
    return d[u] = dfs(a[u]) + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];

    memset(d, -1, sizeof d);
    for(int i = 1; i <= n; i++) d[i] = dfs(i);
    cout<<*max_element(d + 1, d + n + 1);
    return 0;
}

// 12
// -1
// -1
// 1
// -1
// 1
// 1
// 5
// 11
// 8
// 6
// 6
// 4