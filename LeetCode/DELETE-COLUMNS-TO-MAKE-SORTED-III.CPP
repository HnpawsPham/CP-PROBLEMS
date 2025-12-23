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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    int m = a[0].size();
    vi dp(m, 1);
    
    for(int j = 0; j < m - 1; j++)
        for(int c = j + 1; c < m; c++){
            bool ok = 1;
            for(int i = 0; i < n; i++)
                if(a[i][c] < a[i][j]){
                    ok = 0;
                    break;
                }
            if(ok) dp[c] = max(dp[c], dp[j] + 1);
        }
    cout<<m - *max_element(dp.begin(), dp.end());
    return 0;
}

// 2
// babca 
// bbazb

// 1
// edcba

// 3
// ghi
// def
// abc
