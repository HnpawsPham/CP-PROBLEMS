#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c, tmax;
    cin>>n>>a>>b>>c>>tmax;
    int t[n];
    for(int i = 0; i < n; i++) cin>>t[i];

    ll res = 0;
    for(int i = 0; i < n; i++)
        res += tmax - t[i];

    res = 1LL * n * a + 1LL * max(0, c - b) * res;
    cout<<res;
    return 0;
}