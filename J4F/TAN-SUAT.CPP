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
#define taskname "rate"

int n, k;
const int maxn = 3e5 + 5;
const db oo = 3e12;
int a[maxn];
db p[maxn];

bool check(db t){
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1] - t;

    db minn = 0;
    for(int i = k; i <= n; i++){
        minn = min(minn, p[i - k]);
        if(p[i] - minn >= 0) return 1;
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

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    db l = k, r = oo, mid;
    for(int i = 0; i < 100; i++){
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(6)<<l;
    return 0;
}

// 4 1
// 1 0 4 3

// 5 2
// 2 4 3 4 1