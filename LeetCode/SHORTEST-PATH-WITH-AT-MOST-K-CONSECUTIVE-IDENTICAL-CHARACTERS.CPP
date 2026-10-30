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

const int maxn = 5e4 + 5;
const int oo = 1e9 + 5;
vector<pii> a[maxn];
int dis[maxn][55];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    string label;
    cin>>n>>m>>label>>k;
    vector<vi> ed(m, vi(3));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

    for(const vi& v : ed)
        a[v[0]].push_back({v[2], v[1]});

    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 51; j++)
            dis[i][j] = oo;

    pq.push({0, {0, 1}}); // w, u, cnt
    dis[0][1] = 0;

    while(!pq.empty()){
        auto [w, cur] = pq.top();
        auto [u, cnt] = cur;
        pq.pop();

        if(w > dis[u][cnt]) continue;
        if(u == n - 1) return cout<<w, 0;

        for(auto [w1, v] : a[u]){
            int cnt1 = (label[v] == label[u]) * cnt + 1;
            if(cnt1 <= k && dis[v][cnt1] > dis[u][cnt] + w1){
                dis[v][cnt1] = dis[u][cnt] + w1;
                pq.push({dis[v][cnt1], {v, cnt1}});
            }
        }
    }
    cout<<-1;
    return 0;
}

// 3 3 aab 1 
// 0 1 1
// 1 2 1
// 0 2 3