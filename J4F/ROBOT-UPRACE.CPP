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

int tc = 1;
int n;
const int oo = 5e6 + 6;
const int maxn = 2005;
int a[maxn][maxn];
int check[maxn][maxn];
vector<pii> pos[maxn * maxn];

int dy[8] = {-1 ,1, 0, 0, -1, 1, -1, 1},
    dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};

bool touchBotLeft(int i, int j){
    return (i == n - 1 && j < n - 1) || (j == 0 && i > 0);
}

bool touchTopRight(int i, int j){
    return (i == 0 && j > 0) || (j == n - 1 && i < n - 1);
}

int sol(){
    cin>>n;
    for(int i = 1; i < n * n; i++)
        pos[i].clear();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            pos[a[i][j]].push_back({i, j});
            check[i][j] = 0;
        }

    for(int t = 1; t <= n * n; t++){
        if(a[0][0] == t || a[n - 1][n - 1] == t) continue;
        if(pos[t].empty()) return t;

        bool ok = 1;
        for(const auto[x, y] : pos[t]){
            if(check[x][y] == t) continue;
            
            queue<pii> q;
            q.push({x, y});
            check[x][y] = t;

            bool checkTopRight = 0, checkBotLeft = 0;
            while(!q.empty()){
                auto [i, j] = q.front();
                q.pop();

                checkTopRight |= touchTopRight(i, j);
                checkBotLeft |= touchBotLeft(i, j);

                if(checkTopRight && checkBotLeft){
                    ok = 0;
                    break;
                }

                for(int x = 0; x < 8; x++){
                    int i1 = i + dy[x];
                    int j1 = j + dx[x];

                    if(i1 < 0 || j1 < 0 || i1 == n || j1 == n || check[i1][j1] == t || a[i1][j1] != t) 
                        continue;

                    check[i1][j1] = t;
                    q.push({i1, j1});
                }
            }   
            if(!ok) break;
        }
        if(ok) return t;
    }
    return n * n;
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
        cout<<sol()<<el;
    }
    return 0;
}