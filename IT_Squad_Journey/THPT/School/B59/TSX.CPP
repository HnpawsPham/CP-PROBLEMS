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
#define taskname "TSX"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    int p[n + 1] = {0};

    int fi[26], se[26];
    memset(fi, -1, sizeof fi);
    for(int i = 0; i < n; i++){
        if(fi[s[i] - 'a'] == -1)
            fi[s[i] - 'a'] = i;
        se[s[i] - 'a'] = i;
    }

    int res = 0;
    for(int j = 0; j < 26; j++){
        if(fi[j] == -1) continue;

        p[0] = 0;
        for(int i = 1; i <= n; i++)
            p[i] = p[i - 1]+ abs(s[i - 1] - 'a' - j);
    
        res = max(res, p[se[j] + 1] - p[fi[j]]);
    }
    cout<<res;
    return 0;
}