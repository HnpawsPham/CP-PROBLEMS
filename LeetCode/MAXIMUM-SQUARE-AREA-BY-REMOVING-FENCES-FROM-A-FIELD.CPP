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

int r, c, n, m;
const int MOD = 1e9 + 7;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c>>n>>m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0; j < m; j++) cin>>b[j];

    a.push_back(1);
    a.push_back(r);
    b.push_back(1);
    b.push_back(c);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    n = a.size();
    m = b.size();

    unordered_set<int> sa, sb;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            sa.insert(a[j] - a[i]);

    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            sb.insert(b[j] - b[i]);

    ll res = 0;
    for(const int& x : sa)
        if(sb.find(x) != sb.end())
            res = max(res, 1LL * x * x);
    
    if(res) cout<<res;
    else cout<<-1;
    return 0;
}

// 4 3
// 2 1
// 2 3
// 2

// 6 7
// 1 1
// 2 4