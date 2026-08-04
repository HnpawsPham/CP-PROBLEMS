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
#define taskname "keyboard"

int n, m;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s;

    char fi = s[0];
    bool ok = 1;
    for(int i = 1; i < n && ok; i++)
        if(fi != s[i]) ok = 0;

    if(ok) return cout<<0, 0;

    string t;
    for(int i = 0; i < m; i++)
        t.push_back(i + 'a');

    int res = m * m;
    do{
        int pos[m] = {0};
        for(int i = 0; i < m; i++)
            pos[t[i] - 'a'] = i;

        int cnt = 0;
        for(int i = 1; i < n; i++)
            cnt += abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']);    
        res = min(res, cnt);
    }
    while(next_permutation(t.begin(), t.end()));

    cout<<res;
    return 0;
}