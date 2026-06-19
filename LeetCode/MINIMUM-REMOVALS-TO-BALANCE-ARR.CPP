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

    int l = 0, res = 0;
    for(int r = 0; r < n; r++){
        while(1LL * a[r] > 1LL * a[l] * k)
            l++;

        res = max(res, r - l + 1);
    }
    cout<<n - res;
    return 0;
}

// 3 2
// 2 1 5

// 4 3
// 1 6 2 9