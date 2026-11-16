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

int n;
const int maxn = 1e5 + 5;
vi a[maxn];
int res = 0;

int dfs(int u, int parent, const string& s){
    int max1 = 0, max2 = 0;

    for(int v : a[u]){
        if(v == parent) continue;
        int len = dfs(v, u, s);

        if(s[v] != s[u]){
            if(len > max1){
                max2 = max1;
                max1 = len;
            }
            else if(len > max2)
                max2 = len;
        }
    }
    res = max(res, max1 + max2 + 1);
    return max1 + 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>n>>s;
    int p[n];
    for(int i = 0; i < n; i++) cin>>p[i];
    
    for(int i = 1; i < n; i++){
        a[p[i]].push_back(i);
        a[i].push_back(p[i]);
    }
    dfs(0, -1, s);
    cout<<res;
    return 0;
}

// 6 abacbe
// -1 0 0 1 1 2