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

    string s;
    cin>>s;
    int prev[26];
    memset(prev, -1, sizeof prev);

    int n = s.length();
    int minn[26] = {0};

    for(int i = 0; i < n; i++){
        if(prev[s[i] - 'a'] != -1)
            minn[s[i] - 'a'] = max(minn[s[i] - 'a'], i - prev[s[i] - 'a']);
        else minn[s[i] - 'a'] = i + 1;
        prev[s[i] - 'a'] = i;
    }

    int res = n;
    for(int i = 0; i < 26; i++)
        if(minn[i]) res = min(res, max(minn[i], n - prev[i]));
    cout<<min(n / 2 + 1, res);
    return 0;
}