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

int n, m;

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

//   x 
// x x x
//   x
int dy[5] = {0, 1, 0, 0, -1},
    dx[5] = {0, 0, -1, 1, 0};

void flip(int i, int j, vector<vi>& a){
    for(int x = 0; x < 5; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];
        if(valid(i1, j1))
            a[i1][j1] = !a[i1][j1];
    }
}

int res = 1005;
void check(int i, int j, int cnt, vector<vi>& a){
    if(i == n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j]) return;

        res = min(res, cnt);
        return;
    }

    if(j == m){
        check(i + 1, 0, cnt, a);
        return;
    }

    check(i, j + 1, cnt, a);

    flip(i, j, a);
    check(i, j + 1, cnt + 1, a);
    flip(i, j, a);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    check(0, 0, 0, a);
    cout<<(res == 1005 ? -1 : res);
    return 0;
}

// 2 2
// 0 0
// 0 1