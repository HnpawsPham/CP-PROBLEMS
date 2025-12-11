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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][2];
    for(int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];

    vi l(m + 1, m + 2), r(m + 1, 0), bot(m + 1, 0), top(m + 1, m + 2);
    for(auto [x, y] : a){
        l[y] = min(l[y], x);
        r[y] = max(r[y], x);
        bot[x] = max(y, bot[x]);
        top[x] = min(y, top[x]);
    }

    int res = 0;
    for(auto [x, y] : a)
        if(x != l[y] && x != r[y] && y != bot[x] && y != top[x]) res++;
    cout<<res;
    return 0;
}

// 5 3
// 1 2
// 2 2
// 3 2
// 2 1
// 2 3

// 4 3
// 1 1 
// 1 2
// 2 1
// 2 2