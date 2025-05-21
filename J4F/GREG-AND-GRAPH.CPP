#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
int n;

const ll oo = 1e14;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n + 1][n + 1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];

    bool check[n + 1] = {0};
    int idx[n];
    ll res[n];
    for(int i = 0; i < n; i++) cin>>idx[i];

    for(int i = n - 1; i >= 0; i--){
        int k = idx[i];
        check[k] = 1;
        
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                if(u != k && v != k)
                    a[u][v] = min(a[u][k] + a[k][v], a[u][v]);
        
        ll sum = 0;
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                if(check[u] && check[v] && u != v)
                    sum += a[u][v];
        
        res[i] = sum;
    }
    for(const ll& x : res) cout<<x<<" ";
    return 0;
}