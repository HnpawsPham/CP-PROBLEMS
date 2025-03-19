#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int n;
const int maxn = (int)1e6 + 5;
ll a[maxn], b[maxn];
vector<vector<int>> gr(maxn);

int main(){
    freopen(".\\txt\\TSTD.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n;i++) cin>>a[i];
    for(int i = 1; i<=n; i++) cin>>b[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        gr[u].push_back(v);
    }

    return 0;
}