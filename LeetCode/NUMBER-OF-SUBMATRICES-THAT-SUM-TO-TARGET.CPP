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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, target;
    cin>>n>>m>>target;
    int a[n][m];
    for(int i =0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            a[i][j] += a[i][j - 1];
    
    int res = 0;
    for(int l = 0; l < m; l++)
        for(int r = l; r < m; r++){
            unordered_map<int, int> mp;
            int sum = 0;
            mp[0] = 1;

            for(int i = 0; i < n; i++){
                sum += a[i][r] - (l > 0 ? a[i][l - 1] : 0);
                if(mp.count(sum - target))
                    res += mp[sum - target];
                mp[sum]++;
            }
        }
    cout<<res;
    return 0;
}

// 3 3
// 0
// 0 1 0
// 1 1 1
// 0 1 0