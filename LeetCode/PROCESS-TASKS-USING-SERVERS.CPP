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

    int n, m;
    cin>>n>>m;
    vi server(n), task(m);
    for(int i = 0; i < n; i++)
        cin>>server[i];
    for(int i = 0; i < m; i++)
        cin>>task[i];

    vi res(m);
    priority_queue<pii, vector<pii>, greater<pii>> free;
    priority_queue<pli, vector<pli>, greater<pli>> busy;
    for(int i = 0; i < n; i++)
        free.push({server[i], i});

    ll t = 0;
    for(int i = 0; i < m; i++){
        t = max(t, i);
        if(free.empty())
            t = busy.top().fi;
        
        while(!busy.empty() && busy.top().fi <= t){
            free.push({server[busy.top().se], busy.top().se});
            busy.pop();
        }

        res[i] = free.top().se;
        busy.push({1LL * t + task[i], free.top().se});
        free.pop();        
    }
    for(const int& x : res) cout<<x<<" ";
    return 0;
}

// 3 6
// 3 3 2
// 1 2 3 2 1 2