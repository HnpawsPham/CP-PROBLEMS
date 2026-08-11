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
#define taskname "GAME"

int n;
const int maxn = 105;
const int oo = 1e9 + 5;
int a[3][maxn];

namespace sub1{
    int res = -oo;

    void backtrack(int d){
        if(d == 9) return;
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[0][i] * a[1][i];
        res = max(sum, res);
        
        for(int j = 0; j < 3; j++)
            for(int x = 0; x < n - 1; x++)
                if((a[j][x] == 0) != (a[j][x + 1] == 0)){
                    swap(a[j][x], a[j][x + 1]);
                    backtrack(d + 1);
                    swap(a[j][x], a[j][x + 1]);
            }
    }

    void sol(){
        backtrack(0);
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < 3; i++)
        for(int j = 0 ; j < n; j++) cin>>a[i][j];

    if(n <= 10)
        sub1::sol();
    else cout<<oo;
    return 0;
}
