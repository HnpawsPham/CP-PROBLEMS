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
const int maxn = 5e4 + 5;
int a[maxn][5];

bool better(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 5; i++)
        if(a[x][i] < a[y][i])
            cnt++;
    return cnt >= 3;
}

int sol(){
    int n;
    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
            cin>>a[i][j];

    int res = 0;
    for(int i = 1; i < n; i++)
        if(better(i, res))
            res = i;

    for(int i = 0; i < n; i++)
        if(i != res && !better(res, i)) 
            return -1;

    return res + 1;
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