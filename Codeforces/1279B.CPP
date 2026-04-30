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
const int maxn = 1e5 + 15;
int n;
ll s;
int a[maxn];
ll p[maxn];

int check(int t){
    for(int i = 1; i <= t; i++)
        if(p[t] - a[i] <= s) return i;
    return -1;
}

int sol(){
    cin>>n>>s;
    for(int i = 1; i <= n; i++) cin>>a[i];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    if(p[n] <= s) return 0;
    p[n + 1] = p[n];

    int l = 1, r = n, mid, res = 1;
    while(l <= r){
        mid = (l + r) / 2;
        int t = check(mid);

        if(t != -1){
            l = mid + 1;
            res = t;
        }
        else r = mid - 1;
    }
    return res;
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

// 1
// 10 90
// 10 11 10 10 10 10 10 10 10 10

// 1
// 10 90
// 10 10 10 10 10 10 10 10 10 11