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
#define taskname "minmaxrec"

int n, m;
const int maxn = 2005;
int a[maxn][maxn];

bool check(ll t){
    bitset<maxn> bit[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] <= t) 
                bit[i].set(j);

    for(int i = 0; i < n - 1; i++){
        if(bit[i].count() < 2) continue;
        for(int j = i + 1; j < n; j++)
            if((bit[i] & bit[j]).count() >= 2) return 1;
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    int l = 0, r = 1e9 + 3, mid, res = 1e9;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}