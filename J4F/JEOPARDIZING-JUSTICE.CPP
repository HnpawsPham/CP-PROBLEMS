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

int tc = 1;

int sol(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int u = -1;
    for(int i = 0; i < n; i++){
        int in = 0;
        for(int j = 0; j < n; j++)
            in += a[i][j];
        
        if(in > 0){
            u = i;
            break;
        }
    }

    vector<pii> res;
    for(int i = 0, j = 0; i < n && j < 50; i++)
        if(a[u][i]){
            res.push_back({u, i});
            j++;
        }

    if(res.empty()) return cout<<-1<<el, 0;

    cout<<res.size()<<el;
    for(const auto& x : res) 
        cout<<x.fi<<" "<<x.se<<el;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
    }
    return 0;
}