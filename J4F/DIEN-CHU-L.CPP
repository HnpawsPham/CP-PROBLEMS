#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vb vector<bool>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 17;
char a[maxn][maxn];

bool valid(int i, int j, const vector<vb>& check){
    return (i >= 0 && j >= 0 && i < n && j < m && !check[i][j]);
}

bool sol(vector<vb>& check){
    int i = -1, j = -1;

    for(int x = 0; x < n && i == -1; x++)
        for(int y = 0; y < m && i == -1; y++)
            if(!check[x][y]){
                i = x;
                j = y;
            }
    if(i == -1) return 1;

    // *
    // * *
    if(valid(i, j, check) && valid(i + 1, j, check) && valid(i + 1, j + 1, check)){
        check[i][j] = check[i + 1][j] = check[i + 1][j + 1] = 1;
        if(sol(check)) return 1;
        check[i][j] = check[i + 1][j] = check[i + 1][j + 1] = 0;
    }

    //   *
    // * *
    if(valid(i, j, check) && valid(i + 1, j - 1, check) && valid(i + 1, j, check)){
        check[i][j] = check[i + 1][j - 1] = check[i + 1][j] = 1;
        if(sol(check)) return 1;
        check[i][j] = check[i + 1][j - 1] = check[i + 1][j] = 0;
    }
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

    cin>>n>>m;

    vector<vb> check(n, vb(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] == '#')
                check[i][j] = 1;
        }

    cout<<(sol(check) ? "YES" : "NO");
    return 0;
}