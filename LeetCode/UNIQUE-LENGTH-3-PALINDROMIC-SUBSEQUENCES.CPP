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

    string s;
    cin>>s;

    int n = s.length();
    int pre[n + 1][26], suf[n + 1][26];
    for(int i = 0; i < 26; i++)
        pre[0][i] = suf[n][i] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 26; j++)
            pre[i][j] = pre[i - 1][j] + (s[i - 1] - 'a' == j);

    for(int i = n - 1; i >= 0; i--)
        for(int j = 0; j < 26; j++)
            suf[i][j] = suf[i + 1][j] + (s[i] - 'a' == j);

    int res = 0;
    bool check[26][26] = {0};
    for(int i = 2; i < n; i++){
        for(int j = 0; j < 26; j++)
            if(check[s[i - 1] - 'a'][j]) continue;
            else if(pre[i - 1][j] && suf[i][j]){
                res += pre[i - 1][j] && suf[i][j] && check[s[i - 1][j]];
                check[s[i - 1] - 'a'][j] = 1;
            }
        }
    cout<<res;
    return 0;
}

// aabca
// adc
// bbcbaba