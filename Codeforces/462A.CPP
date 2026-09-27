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
const int maxn = 105;
char a[maxn][maxn];

int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)  
            cin>>a[i][j];
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int x = 0;x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];
                
                if(i1 < 0 || j1 < 0 || i1 == n || j1 == n || a[i1][j1] == 'x')
                    continue;
                cnt++;
            }
            if(cnt % 2) return cout<<"NO", 0;
        }
    cout<<"YES";
    return 0;
}