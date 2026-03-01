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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1], b[n + 1];
    pii q[m], pos[n + 2];

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        pos[i].se = i;
    }
    
    for(int i = 0; i < m; i++){
        cin>>q[i].fi>>q[i].se;
        pos[q[i].fi].fi++;
        pos[q[i].se + 1].fi--;
    }
    
    for(int i = 1; i <= n; i++)
        pos[i].fi += pos[i - 1].fi;

    sort(a + 1, a + n + 1, greater<int>());
    sort(pos + 1, pos + n + 1, greater<pii>());
    
    for(int i = 1; i <= n; i++)
        b[pos[i].se] = a[i];
    
    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + b[i];

    ll sum = 0;
    for(const pii& x : q)
        sum += p[x.se] - p[x.fi - 1];
    cout<<sum;
    return 0;
}