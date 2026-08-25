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
#define taskname "CAYTAO"

int n, k, q;
const int maxn = 1e5 + 5;
int val[maxn];
vi a[maxn];

bool dfs(int u, int en, int parent, vi& sub){
    sub.push_back(val[u]);

    if(u == en) return 1;

    for(int v : a[u]){
        if(v == parent) continue;
        if(dfs(v, en, u, sub))
            return 1;
    }

    sub.pop_back();
    return 0;
}

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>q;
    for(int i = 1; i <= n; i++) cin>>val[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    while(q--){
        int u, v;
        cin>>u>>v;
        vi sub;
        dfs(u, v, 0, sub);

        int cnt = 0, sz = sub.size();
        for(int i = 0; i < sz - 1; i++)
            for(int j = i + 1; j < sz; j++){
                ll mul = 1LL * sub[i] * 1LL * sub[j];
                ll tmp = round(pow(mul, 1.0 / k));

                if(ppow(tmp, k) == mul) 
                    cnt++;
            }
        cout<<cnt<<el;
    }
    return 0;
}