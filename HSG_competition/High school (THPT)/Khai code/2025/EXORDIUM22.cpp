#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    ll a[n + 5][m + 5];
    for(int i = 1; i <= n; i++)
        for(int j= 1; j<=m; j++) cin>>a[i][j];

    cin>>q;
    
    while(q--){
        int i, j; ll x;
        cin>>i>>j>>x;
        a[i][j] = x;
    }
    for(int i = 1; i <= n; i++){
        for(int j= 1; j<=m; j++) cout<<a[i][j]<<" ";
        cout<<el;
    }

    return 0;
}