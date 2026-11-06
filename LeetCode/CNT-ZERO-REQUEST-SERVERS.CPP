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

bool comp(vi&a , vi& b){
    return a[1] < b[1];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, k;
    cin>>n>>m>>x>>k;
    vector<vi> log(m, vi(2));
    for(int i = 0; i < m; i++)
        cin>>log[i][0]>>log[i][1];

    vi que(k);
    for(int i = 0; i < k; i++)
        cin>>que[i];

    vector<pii> q(k);
    for(int i = 0; i < k; i++)
        q[i] = {que[i], i};
    
    sort(q.begin(), q.end());
    sort(log.begin(), log.end(), comp);

    vi res(k);
    int cnt[n + 1];
    memset(cnt, 0, sizeof cnt);
    int onl = 0;

    int l = 0, r = 0;
    for(int i = 0; i < k; i++){
        while(r < m && log[r][1] <= q[i].fi){
            if(!cnt[log[r][0]]) onl++;
            cnt[log[r][0]]++;
            r++;
        }

        while(l < m && log[l][1] < q[i].fi - x){
            cnt[log[l][0]]--;
            if(!cnt[log[l][0]]) onl--;
            l++;
        }
        res[q[i].se] = n - onl;
    }

    for(const int& x : res) cout<<x<<" ";
    return 0;
}

// 3 3 5 2
// 1 3
// 2 6
// 1 5
// 10 11