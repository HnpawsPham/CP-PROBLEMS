#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
#define taskname "GREEN"

int n, m, k;
const int maxn = 1e5 + 5;
vector<pli> a[maxn];
bool ez[maxn];
int from[maxn], to[maxn]; 


int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    
    cin>>from[1]>>to[1];
    for(int i = 2; i <= k; i++)
        cin>>ez[i]>>from[i]>>to[i];
    return 0;
}