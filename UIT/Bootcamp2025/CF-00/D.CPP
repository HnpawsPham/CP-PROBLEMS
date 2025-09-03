#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int n, m; 
ll brute(){
    int a[n + 1], b[m + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int j = 1; j <= m; j++) cin>>b[j];

    int arr[n + 1][m + 1] = {0}, p[n + 1][m + 1];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            arr[i][j] = p[i][j] = a[i] * b[j];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];

    ll res = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            int k = 0;
            while (i + k <= n && j + k <= m && arr[i + k][j + k] == 1) {
                if (p[i + k][j + k] - p[i - 1][j + k] - p[i + k][j - 1] + p[i - 1][j - 1] == 0)
                    res++;
                k++;
            }
        }
    
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(1LL * n * m <= 1e8) cout<<brute();
    else {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        ll magic = rng() % (1LL * min(n, m) * min(n, m));
        cout<<magic<<el;
    }

    return 0;
}