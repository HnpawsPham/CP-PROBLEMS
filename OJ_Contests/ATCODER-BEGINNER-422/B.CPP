#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.') continue;
            int cnt = 0;
            for(int x = 0; x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];
                if(i1 < 0 || j1 < 0 || i1 == n || j1 == m) continue;
                if(a[i1][j1] == '#') cnt++;
            }
            if(!(cnt == 2 || cnt == 4)) return cout<<"No", 0;
        }
    cout<<"Yes";
    return 0;
}