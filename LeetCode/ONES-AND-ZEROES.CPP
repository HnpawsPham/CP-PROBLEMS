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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, zero, one;
    cin>>n>>zero>>one;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> dp(zero + 1, vi(one + 1, 0));
    
    for(const string& s : a){
        int cnt0 = 0, cnt1 = 0;
        for(char x : s){
            cnt0 += x == '0';
            cnt1 += x == '1';
        }

        for(int i = zero; i >= cnt0; i--)
            for(int j = one; j >= cnt1; j--)
                dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
    }
    cout<<dp[zero][one];
    return 0;
}

// 5 5 3
// 10 0001 111001 1 0

// 3 1 1
// 10 0 1