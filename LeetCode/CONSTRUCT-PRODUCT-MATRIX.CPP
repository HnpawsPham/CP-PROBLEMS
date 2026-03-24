#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];
    
    vi b;
    const int MOD = 12345;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b.push_back(a[i][j]);

    int sz = n * m;
    vi p(sz + 1), s(sz + 1);
    p[0] = s[sz] = 1LL;

    for(int i = 1; i <= sz; i++)
        p[i] = (p[i - 1] % MOD) * (b[i - 1] % MOD) % MOD;
    
    for(int i = sz - 1; i >= 0; i--)
        s[i] = (s[i + 1] % MOD) * (b[i] % MOD) % MOD;

    vector<vi> res;
    vi row;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            row.push_back((p[i * m + j] % MOD) * (s[i * m + j + 1] % MOD) % MOD);
            // cout<<s[i * n + j + 1]<<" ";

        res.push_back(row);
        row.clear();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout<<res[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 2 2
// 1 2 
// 3 4

// 3 1
// 12345
// 2 
// 1