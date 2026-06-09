#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
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

    int n, m, k;
    cin>>n>>m>>k;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for(int i = 0; i < m; i++)
        pq.push({a[0] + b[i], {0, i}});

    vector<vi> res;
    while(k--){
        auto [i, j] = pq.top().se;
        pq.pop();
        res.push_back({a[i], b[j]});

        if(i + 1 < n)
            pq.push({a[i + 1] + b[j], {i + 1, j}});
    }
    
    for(const vi& v : res)
        cout<<v[0]<<" "<<v[1]<<el;
    return 0;
}

// 3 3 3
// 1 7 11
// 2 4 6

// 3 3 2
// 1 1 2
// 1 2 3