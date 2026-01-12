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
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];

    int t = 0;
    for(int i = 1; i < n; i++){
        int d = abs(a[i - 1][0] - a[i][0]);
        int r = abs(a[i - 1][1] - a[i][1]);
        t += max(d, r);
    }
    cout<<t;
    return 0;
}

// 3
// 1 1
// 3 4
// -1 0

// 2
// 3 2
// -2 2