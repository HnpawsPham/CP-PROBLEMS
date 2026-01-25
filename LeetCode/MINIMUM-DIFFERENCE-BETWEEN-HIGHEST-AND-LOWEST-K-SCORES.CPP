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

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    int minn = INT_MAX;
    for(int i = 0; i + k - 1 < n; i++)
        minn = min(minn, a[i + k - 1] - a[i]);
    cout<<minn;
    return 0;
}

// 1 1
// 90

// 4 2
// 9 4 1 7