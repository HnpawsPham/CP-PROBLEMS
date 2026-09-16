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
#define taskname "VOLIMPIC"

int n, m;
const int maxn = 1e3 + 5;
const ll oo = 1e14 + 5;
int a[maxn][20];
ll maxx[1 << 16];

bool check(int mask1, int mask2){
    for(int i = 0; i < 16; i++)
        if((mask1 & (1 << i)) && (mask2 & (1 << i)))
            return 0;
    return 1;
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
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    int sz = (1 << m);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < sz; j++){
            ll sum = 0;
            for(int x = 0; x < m; x++)
                if(j & (1 << x)) 
                    sum += a[i][x];
            maxx[j] = max(maxx[j], sum);
        }

    ll res = 0;
    for(int mask1 = 0; mask1 < sz; mask1++){
        int left = (sz - 1) ^ mask1;
        for(int mask2 = left; ; mask2 = (mask2 - 1) & left){
            int mask3 = left ^ mask2;
            res = max(res, maxx[mask1] + maxx[mask2] + maxx[mask3]);
            if(!mask2) break;
        }
    }
    cout<<res;
    return 0;
}