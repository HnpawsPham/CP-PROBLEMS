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
#define vb vector<bool>
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    int m;
    cin>>s>>t>>m;
    vector<char> from(m), to(m);
    vi w(m);
    for(int i = 0; i < m; i++) cin>>from[i];
    for(int i = 0; i < m; i++) cin>>to[i];
    for(int i = 0; i < m; i++) cin>>w[i];

    int n = s.length();
    const ll oo = 1e12;
    vector<vll> d(26, vll(26, oo));

    for(int i = 0; i < m; i++){
        d[u][v] = min(1LL * w[i], d[u][v]);
        d[u][u] = d[v][v] = 0;
    }

    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    ll res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        ll inc = d[s[i] - 'a'][t[i] - 'a'];

        if(inc >= oo) return cout<<-1, 0;
        res += inc
    }
    cout<<res;
    return 0;
}

// abcd
// acbe
// 6
// a b c c e d
// b c b e b e
// 2 5 5 1 2 20