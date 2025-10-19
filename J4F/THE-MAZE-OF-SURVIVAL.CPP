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

int n, m;
int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> hp(n, vi(m, -1));
    queue<piii> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'S'){
                q.push({{i, j}, 0});
                hp[i][j] = 3;
                break;
            }

    while(!q.empty()){
        auto [pos, t] = q.front();
        auto [i, j] = pos;
        q.pop();

        if(a[i][j] == 'D') return cout<<t, 0;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m) continue;

            int tmp = hp[i][j] - (a[i1][j1] == '+');
            if(tmp <= 0 || tmp <= hp[i1][j1]) continue;

            hp[i1][j1] = tmp;
            q.push({{i1, j1}, t + 1});
        }
    }       
    cout<<-1;
    return 0;
}

// 2 4
// S++D
// ----

// 2 5
// S+++D
// +-+--
