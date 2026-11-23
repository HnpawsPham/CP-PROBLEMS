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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    vi res;
    for(int i = n; i > 0; i -= 2)
        res.push_back(a[i]);
    for(int i = 1 + (n & 1); i <= n; i+=2)
        res.push_back(a[i]);

    for(const int& x: res) cout<<x<<" ";
    return 0;
}