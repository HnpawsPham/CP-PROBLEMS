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
#define taskname "BOARD"

int n, m;
char x;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    bool a[n][m], b[n][m];
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++){
            cin>>x;
            a[i][j] = (x == 'B' ? 0 : 1);
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>x;
            b[i][j] = (x == 'B' ? 0 : 1);
        }

    vector<pii> res;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m - 1; j++)
            if(a[i][j] != b[i][j]){
                a[i][j] ^= 1;
                a[i][j + 1] ^= 1;
                a[i + 1][j] ^= 1;
                a[i + 1][j + 1] ^= 1;
                res.push_back({i + 1, j + 1});
            }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] != b[i][j])
                return cout<<"NO", 0;

    cout<<"YES"<<el<<res.size()<<el;
    for(const pii& x : res) 
        cout<<x.fi<<" "<<x.se<<el;
    return 0;
}