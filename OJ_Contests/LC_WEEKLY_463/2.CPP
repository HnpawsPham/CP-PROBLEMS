#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vi a(n);
    vector<vi> que(m, vi(4));
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>que[i][0]>>que[i][1]>>que[i][2]>>que[i][3];

    for(auto q : que){
        int l = q[0], r = q[1], k = q[2], v = q[3];
        for(int i = l; i <= r; i+=k)
            a[i] = (a[i] * v) % MOD;
    }

    int res = 0;
    for(int x : a) res ^= x;
    cout<<res;
    return 0;
}