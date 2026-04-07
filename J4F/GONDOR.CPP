#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<db, int>
#define fi first
#define se second
//#define taskname ""

struct tower{
    int x, y, s;
    tower(int x1, int y1, int s1) : x(x1), y(y1), s(s1) {};
    tower() {};
};

int n;
const int maxn = 105;
const db oo = 1e9 + 5;
vector<tower> pos;
vi a[maxn];

db d(const tower& a, const tower& b){
    return (db)sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<db> t(n + 1, oo);
    t[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > t[u]) continue;

        int cnt = 0;
        for(int v : a[u]){
            if(cnt == pos[u].s) break;
            if(t[v] > t[u]){
                cnt++;
                if(t[v] > t[u] + d(pos[u], pos[v])){
                    t[v] = t[u] + d(pos[u], pos[v]);
                    pq.push({t[v], v});
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout<<fixed<<setprecision(6)<<t[i]<<el;
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pos.push_back({-1, -1, -1});
    for(int i = 1; i <= n; i++){
        int x, y, s;
        cin>>x>>y>>s;
        pos.push_back({x, y, s});
      
        for(int j = 1; j < n; j++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }

    dijkstra(1);    
    return 0;
}