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

    int n, t, k, d;
    cin>>n>>t>>k>>d;
    int solo = (d / t) * k;
            //no build             build
    cout<<((n + k - 1) / k * t <= ((max(0, n - solo) + 2 * k - 1) / (2 * k)) * t + d ? "NO" : "YES");
    return 0;
}