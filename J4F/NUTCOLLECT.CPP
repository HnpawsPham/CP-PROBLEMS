#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define fi first
#define se second

struct pos{
    int i, j, k, d;
};

int n, m, sx, sy;
const int maxn = 305;
string s, a[maxn];
bool check[maxn][maxn][maxn] = {0};
int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>sx>>sy;
    for(int i = 0; i < n; i++) cin>>a[i];
    cin>>s;

    int sz = s.length();
    sx--; sy--;

    queue<pos> q;
    q.push({sx, sy, 0, 0});
    check[sx][sy][0] = 1;

    while(!q.empty()){
        auto [i, j, k, d] = q.front();
        q.pop();

        if(k == sz) return cout<<d, 0;

        if(a[i][j] == s[k] && !check[i][j][k + 1]){
            check[i][j][k + 1] = 1;
            q.push({i, j, k + 1, d});
        }

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];
            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1][k]) continue;
            check[i1][j1][k] = 1;
            q.push({i1, j1, k, d + 1});
        }
    }
    return 0;
}

// 2 26
// 1 1
// abcdefghijklmnopqrstuvwxyz
// abtxyzutalkhfdyutxzbzhhawj
// nut