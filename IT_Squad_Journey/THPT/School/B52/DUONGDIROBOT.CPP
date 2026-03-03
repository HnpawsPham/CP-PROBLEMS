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
#define taskname "DUONGDIROBOT"

const int MOD = 1e6;

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
    bool a[n][n];
    int cnt[n][n];
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            cnt[i][j] = 0;
        }

    cnt[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(a[i][j]) continue;

            if(i > 0) cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % MOD;
            if(j > 0) cnt[i][j] = (cnt[i][j] + cnt[i][j - 1]) % MOD;
        }
    
    if(cnt[n - 1][n - 1] == 0) 
        cout<<"khong tim thay duong di";
    else cout<<cnt[n - 1][n - 1];
    return 0;
}

// 5
// 0 0 0 0 0
// 1 0 0 1 0
// 1 0 0 1 0
// 0 0 0 1 0
// 0 0 0 0 0