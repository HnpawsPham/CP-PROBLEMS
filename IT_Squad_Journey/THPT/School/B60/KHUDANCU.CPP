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
#define taskname "KHUDANCU"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, d, k;
    cin>>n>>m>>d>>k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> p(n + 2, vi(m + 2, 0));
    for(int i = 1; i <= n ; i++)
        for(int j = 1; j <= m; j++)
            if(a[i - 1][j - 1] == 'M'){
                int i1 = max(1, i - d);
                int j1 = max(1, j - d);
                int i2 = min(n, i + d);
                int j2 = min(m, j + d);
                p[i1][j1]++;
                p[i1][j2 + 1]--;
                p[i2 + 1][j1]--;
                p[i2 + 1][j2 + 1]++;
            }

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];

            if(a[i - 1][j - 1] == 'P' && p[i][j] >= k)
                res++;
        }
    cout<<res;
    return 0;
}