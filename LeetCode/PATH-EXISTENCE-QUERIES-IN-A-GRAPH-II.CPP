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

int n, d, k;
const int maxn = 1e5 + 5;
const int LOG = 17;
int p[maxn][LOG + 1];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> q(k, vi(2));
    for(int i = 0; i < k; i++)
        cin>>q[i][0]>>q[i][1];

    vector<pii> val;
    for(int i = 0; i < n; i++)
        val.push_back({a[i], i});
    sort(val.begin(), val.end());

    int r = 0;
    for(int l = 0; l < n; l++){
        while(r < n && val[r].fi - val[l].fi <= d) 
            r++;
        p[val[l].se][0] = val[--r].se;
    }

    for(int j = 1; j <= LOG; j++)
        for(int i = 0; i < n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];

    vi res;
    for(vi& v : q){
        if(v[0] == v[1]){
            res.push_back(0);
            continue;
        }

        if(a[v[0]] > a[v[1]]) swap(v[0], v[1]);

        int cnt = 0;
        for(int i = LOG; i >= 0; i--)
            if(a[p[v[0]][i]] < a[v[1]]){
                v[0] = p[v[0]][i];
                cnt += (1 << i);
            }

        if(a[p[v[0]][0]] >= a[v[1]]) 
            res.push_back(cnt + 1);
        else res.push_back(-1);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5 3 2
// 1 8 3 4 2
// 0 3
// 2 4