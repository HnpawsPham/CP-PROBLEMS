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

    int k, n, m;
    cin>>k>>n;
    int st[n], len[n];
    for(int i = 0; i < n; i++) cin>>st[i];
    for(int i = 0; i < n; i++) cin>>len[i];

    priority_queue<pii, vector<pii>, greater<pii>> busy;
    set<int> free;
    int cnt[k];
    memset(cnt, 0, sizeof cnt);

    for(int i =0 ; i < k; i++)
        free.insert(i);

    for(int i = 0; i < n; i++){
        while(!busy.empty() && busy.top().fi <= st[i]){
            free.insert(busy.top().se);
            busy.pop();
        }

        if(free.empty()) continue;

        int pos = i % k;
        auto it = free.lower_bound(pos);
        if(it == free.end()) it = free.begin();

        busy.push({st[i] + len[i], *it});
        cnt[*it]++;
        free.erase(*it);
    }

    vi res;
    int maxx = *max_element(cnt, cnt + k);
    for(int i = 0; i < k; i++)
        if(cnt[i] == maxx) res.push_back(i);
    for(const int& x : res) cout<<x<<" ";
    return 0;
}

// 3 5
// 1 2 3 4 5
// 5 2 3 3 3