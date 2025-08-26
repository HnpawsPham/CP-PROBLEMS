#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define mask(i, j) (j & (1 << i))

int n;
const int maxn = 17;
int a[maxn][maxn];
const int oo = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int sz = (1 << n);
    vector<vi> dp(sz, vi(n, oo));
    
    for(int i = 0; i < n; i++)
        dp[1 << i][i] = 0;

    for(int j = 1; j < sz; j++){
        for(int i = 0; i < n; i++){
            if(!mask(i, j)) continue;
            int prev = j ^ (1 << i);
            if(!prev) continue;

            for(int x = 0; x < n; x++)
                if(mask(x, prev))
                    dp[j][i] = min(dp[j][i], dp[prev][x] + a[x][i]);
        }
    }
    cout<<*min_element(dp[sz - 1].begin(), dp[sz - 1].end());
    return 0;
}