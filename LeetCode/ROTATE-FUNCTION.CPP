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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = -1224265354, sum = 0, d = 0;
    for(int i = 1; i < n; i++){
        sum += a[i] * i;
        d += a[i];
    }

    for(int i = 1; i <= n; i++){
        sum -= d;
        sum += a[(i + n - 1 + n) % n] * (n - 1);

        d -= a[i % n];
        d += a[(i + n - 1 + n) % n];

        maxx = max(maxx, sum);
    }
    cout<<maxx;
    return 0;
}

// 4
// 4 3 2 6