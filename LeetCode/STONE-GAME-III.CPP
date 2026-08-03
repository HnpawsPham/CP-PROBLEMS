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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
   
    int dp[n + 1];
    dp[n] = 0;

    const int oo = 5e7 + 5;
    for(int i = n - 1; i >= 0; i--){
        int sum = 0;
        dp[i] = -oo;

        for(int j = 0; j < 3 && i + j < n; j++){
            sum += a[i + j];
            dp[i] = max(dp[i], sum - dp[i + j + 1]);
        }
    }

    if(dp[0] > 0) cout<<"Alice";
    else cout<<(dp[0] == 0 ? "Tie" : "Bob");
    return 0;
}

// 4
// 1 2 3 7

// 4
// 1 2 3 -9

// 4
// 1 2 3 6