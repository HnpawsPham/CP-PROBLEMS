#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, p, q;
const int maxn = 5e3 + 5;
int a[maxn][maxn] = {0};
bool check[maxn][maxn];

int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || a[i][j]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>p>>q;
    while(p--){
        int i, j;
        cin>>i>>j;
        a[i][j] = 1;
    }
    while(q--){
        int i, j;
        cin>>i>>j;
        a[i][j] = -1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 1)
                for(int x = 0; x < 4; x++){
                    int i1 = i + dy[x];
                    int j1 = j + dx[x];
                    while(valid(i1, j1)){
                        check[i1][j1] = 1;
                        i1 += dy[x];
                        j1 += dx[x];
                    }
                }
        
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 0 && !check[i][j]) cnt++;
    cout<<cnt;
    return 0;
}

// 4 6 3 3
// 0 0
// 1 1
// 2 3
// 0 1
// 2 2 
// 1 4

// 3 3 1 4
// 1 1
// 0 1
// 1 0
// 2 1
// 1 2