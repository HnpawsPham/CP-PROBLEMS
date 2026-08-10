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
#define taskname "INCSEQ"

int n;
string s;

bool smaller(int l, int r, int i, int j){
    while(l <= r && s[l] == '0') l++;
    while(i <= j && s[i] == '0') i++;

    if(r - l < j - i) return 1;
    if(r - l > j - i) return 0;

    for(int d = 0; d < r - l + 1; d++)
        if(s[l + d] < s[i + d]) return 1; 
    return 0;
}

void brute(){
    int res = 0, sz = (1 << (n - 1));

    for(int i= 0; i < sz; i++){
        vector<pii> a;
        int prev = 0;
        
        for(int j = 0; j < n - 1; j++){
            if(1 & (i >> j)){
                a.push_back({prev, j});
                prev = j + 1;
            }
        }
        a.push_back({prev, n - 1});

        int m = a.size();
        int dp[m];
        for(int j = 0; j < m; j++)
            dp[j] = 1;

        for(int j = 1; j < m; j++)
            for(int k = 0; k < j; k++)
                if(smaller(a[k].fi, a[k].se, a[j].fi, a[j].se))
                    dp[j] = max(dp[j], dp[k] + 1);

        res = max(res, *max_element(dp, dp + m));
    }
    cout<<res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    if(n <= 23) brute();

    return 0;
}