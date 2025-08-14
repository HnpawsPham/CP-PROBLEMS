#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second 

int n;
const int maxn = 102;
int color[maxn];
vector<vi> a(maxn);

bool dfs(int u, vector<vi>& a){
    for(const int& v : a[u]){
        if(color[v] == -1){
            color[v] = 1 - color[u];
            if(!dfs(v, a)) return 0;
        }

        else if(color[v] == color[u]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        int m, x; cin>>m;
        while(m--){
            cin>>x;
            a[i].push_back(x);
        }
    }

    memset(color, -1, sizeof(color));

    for(int i = 0; i < n; i++)
        if(color[i] == -1){
            color[i] = 0;
            if(!dfs(i, a)) return cout<<0, 0;
        }

    cout<<1;
    return 0;
}
