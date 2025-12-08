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
#define vb vector<bool> 
//#define taskname ""

int tc = 1, n, m;
const int sz = 8;
int dy[sz] = {0, 0, -1, -1, -1, 1, 1, 1},
    dx[sz] = {-1, 1, -1, 1, 0, 0, -1, 1};

int tryto(vector<vb>& a){
    for(int i : {1, n})
        for(int j = 1; j <= m; j++){
            bool ok = 1;
            for(int x = 0; x < sz && ok; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];
                if(i1 < 0 || j1 < 0 || i1 > n || j1 > m) continue;
                if(a[i1][j1]) ok = 0;
            }
            if(ok) a[i][j] = 1;
            else a[i][j] = 0;
        }
    
    for(int i = 1; i <= n; i++)
        for(int j : {1, m}){
            bool ok = 1;
            for(int x = 0; x < sz && ok; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];
                if(i1 < 0 || j1 < 0 || i1 > n || j1 > m) continue;
                if(a[i1][j1]) ok = 0;
            }
            if(ok) a[i][j] = 1;
            else a[i][j] = 0;
        }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cnt += a[i][j];
    return cnt;
}

void print(const vector<vb>& a){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout<<a[i][j];
        cout<<el;
    }
    return;
}

int sol(){
    cin>>n>>m;
    vector<vb> a(n + 1, vb(m + 1, 0)), b;
    b = a;
    a[1][(m + 1) / 2] = 1;
    b[1][m / 2] = 1;

    if(tryto(a) > tryto(b)) print(a);
    else print(b);
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}