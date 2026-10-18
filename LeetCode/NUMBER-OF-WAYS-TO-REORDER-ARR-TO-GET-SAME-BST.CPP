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

const int MOD = 1e9 + 7;
int c[1005][1005];

int dfs(const vi& a){
    int n = a.size();
    if(n <= 2) return 1;

    vi l, r;
    for(int i = 1; i < n; i++){
        if(a[i] < a[0]) l.push_back(a[i]);
        else r.push_back(a[i]);
    }

    int cnt = c[l.size()][r.size() + l.size()];
    cnt = cnt * dfs(l) % MOD;
    cnt = cnt * dfs(r) % MOD;
    return cnt;
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
    vi a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];

    for(int i = 0; i <= n; i++){
        c[0][i] = 1;
        for(int j = 1; j <= i; j++)
            c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % MOD;
    }
    cout<<(dfs(a) - 1 + MOD) % MOD;
    return 0;
}