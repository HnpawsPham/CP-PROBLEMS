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
#define taskname "LCS"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;
    bool cnts[26] = {0}, cntt[26] = {0};

    for(const char& x : s)
        cnts[x - 'a'] = 1;

    for(const char& x : t)
        cntt[x - 'a'] = 1;

    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if((cnts[i] || cntt[i]) != (cnts[i] && cntt[i]))
            cnt++;
    cout<<cnt;
    return 0;
}