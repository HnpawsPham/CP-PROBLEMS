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

    sort(a.begin(), a.end());
    int res = 0;
    for(int i = 0; i < n / 2; i++)
        res = max(res, a[i] + a[n - i - 1]);
    cout<<res;
    return 0;
}

// 4
// 3 5 2 3