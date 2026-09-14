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

int n, m, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>x;
        
    cout<<m * (m - 1) / 2<<el;
    for(int i = 1; i <= m; i++)
        for(int j = i + 1; j <= m; j++){
            if(!k) cout<<i<<" "<<j<<el;
            else cout<<j<<" "<<i<<el;
        }
    return 0;
}