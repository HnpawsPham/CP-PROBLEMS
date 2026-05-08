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

const int maxn = 1e5 + 5;
int spf[maxn];

void sieve(){
    for(int i = 0; i < maxn; i++)
        spf[i] = i;
    spf[0] = spf[1] = -1;

    for(int i = 2; i * i < maxn; i++)
        if(spf[i] == i)
            for(int j = i * i; j < maxn; j+=i)
                spf[j] = i;
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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];   

    sieve();
    unordered_map<int, vi> mp;
    for(int i = 0; i < n; i++){
        int x = a[i];
        while(x > 1){
            int p = spf[x];
            mp[p].push_back(i);
    
            while(x % p == 0) 
                x /= p;
        }
    }

    queue<pii> q;
    vi dis(n, maxn);
    dis[0] = 0;
    q.push({0, 0});

    while(!q.empty()){
        auto [w, u] = q.front();
        q.pop();

        if(w > dis[u]) continue;

        // normal jump
        for(int v : {u - 1, u + 1}){
            if(v < 0 || v == n) continue;

            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push({dis[v], v});
            }
        }

        // prime jump
        if(spf[a[u]] == a[u]){
            for(int v : mp[a[u]])
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push({dis[v], v});
                }
            mp[a[u]].clear();
        }
    }
    cout<<dis[n - 1];
    return 0;
}

// 4
// 1 2 4 6

// 5
// 2 3 4 7 9