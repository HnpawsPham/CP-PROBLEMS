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
#define mask(i, j) ((i >> j) & 1)
//#define taskname ""

int tc = 1;
const int maxn = 2e5 + 5;
int p[maxn][20] = {0};

int sol(){
    int l, r;
    cin>>l>>r;

    int maxx = 0;
    for(int i = 0; i < 20; i++)
        maxx = max(maxx, p[r][i] - p[l - 1][i]);
    return r - l + 1 - maxx;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(p, 0, sizeof p);
    for(int i = 1; i < maxn; i++)
        for(int j = 0; j < 20; j++)
            p[i][j] = p[i - 1][j] + mask(i, j);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}