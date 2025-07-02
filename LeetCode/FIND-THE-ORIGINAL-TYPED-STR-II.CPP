#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string s;
int k;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    int m = s.length();
    vector<int> gr;

    int cnt = 1;
    for(int i = 1; i < m; i++){
        if(s[i] == s[i - 1]) cnt++;
        else{
            gr.push_back(cnt);
            cnt = 1;
        }
    }
    gr.push_back(cnt);

    // for(auto x : gr)
    //     cout<<x<<el;
    ll all = 1;
    for(int x : gr) all = all * x % MOD;

    int n = gr.size();
    vector<ll> dp(k, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        vector<ll> tmp(k, 0);

        ll sum = 0;
        for(int j = 1; j < k; j++){
            sum = (sum + dp[j - 1]) % MOD;

            if(j - gr[i] > 0)
                sum = (sum - dp[j - gr[i] - 1] + MOD) % MOD;

            tmp[j] = sum;
        }

        dp = tmp;
    }
    
    ll sum = 0;
    for(int i = 0; i < k; i++)
        sum = (sum + dp[i]) % MOD;

    cout<<(all - sum + MOD) % MOD;
    return 0;
}