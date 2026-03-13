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

int n, q;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>n>>q>>s;

    int cnt[n + 1][26];
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i - 1][j] + (s[i - 1] - 'a' == j); 

    while(q--){
        int l, r;
        cin>>l>>r;
        
        int res = 0;
        for(int i = 0; i < 26; i++)
            res += (cnt[r][i] - cnt[l - 1][i]) * (i + 1);
        cout<<res<<el;
    }
    return 0;
}