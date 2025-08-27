#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

vector<vi> rotate(vector<vi>& a){
    vector<vi> res(m, vi(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[j][i] = a[n - i - 1][j];

    swap(n, m);
    return res;
}

int getlen(int x, int y, int dir, const vector<vi>& a, bool take1){
    int next = 2 - a[x][y], len = 0;
    int di = (dir == -1 ? -1 : (take1 ? -1 : 1));
    int dj = (dir == -1 ? -1 : (take1 ? 1 : -1));
    int i = x + di, j = y + dj;
    bool has1 = 0;
    
    while(i >= 0 && i < n && j >= 0 && j < m){
        if(a[i][j] != next) {
            has1 = (a[i][j] == 1);
            break;
        }
        len++;
        i += di;
        j += dj;
        next = 2 - next;
    }

    if(take1){
        if(has1 && next == 0) return len + 1;
        return -1;
    }
    return len;
}

int sol(const vector<vi>& a){
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){  
            if(a[i][j] == 1) {
                res = max(res, 1);
                continue;
            }

            for(int take1 = 0; take1 < 2; take1++){
                int l = getlen(i, j, -1, a, take1);
                int r = getlen(i, j, 1, a, 1 - take1);

                if(l != -1 && r != -1) res = max(res, r + l + 1);
            }
        }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int res = 0;
    for(int i = 0; i < 4; i++){
        res = max(res, sol(a));
        a = rotate(a);
    }
    cout<<res;
    return 0;
}

// 5 5
// 2 2 1 2 2
// 2 0 2 2 0
// 2 0 1 1 0
// 1 0 2 2 2
// 2 0 0 2 2

// 5 5
// 2 2 2 2 2
// 2 0 2 2 0
// 2 0 1 1 0
// 1 0 2 2 2
// 2 0 0 2 2

// 5 5
// 1 2 2 2 2
// 2 2 2 2 0
// 2 0 0 0 0
// 0 0 2 2 2 
// 2 0 0 2 0