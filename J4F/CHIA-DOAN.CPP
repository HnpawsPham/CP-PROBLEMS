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

int n, q, m;
const int maxn = 1e5 + 5;
const int LOG = 17;
int a[maxn], nextp[maxn][LOG + 1];
ll p[maxn];

bool check(int l, int r, int k){
    if(k >= n) return 1;
    
    int pos = l;
    for(int j = LOG; j >= 0; j--){
        if((1LL * k >> j) & 1) 
            pos = nextp[pos][j];
        if(pos > r) return 1;
    }
    return pos > r;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>q>>m;
    memset(a, 0, sizeof a);

    p[0] = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        p[i + 1] = p[i] + a[i];
    }

    int r = 1;
    for(int i = 1; i <= n; i++){
        while(r <= n && p[r] - p[i - 1] <= m)
            r++;
        nextp[i][0] = r;
    }

    for(int j = 0; j <= LOG; j++)
        nextp[n + 1][j] = n + 1;

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            nextp[i][j] = nextp[nextp[i][j - 1]][j - 1];

    while(q--){
        int lim, k;
        cin>>lim>>k;

        int l = 1, r = lim, mid, res;
        while(l <= r){
            mid = (l + r) / 2;
            if(check(mid, lim, k)){ 
                r = mid - 1;
                res = mid;
            }
            else l = mid + 1;
        }
        cout<<res<<el;
    }
    return 0;
}