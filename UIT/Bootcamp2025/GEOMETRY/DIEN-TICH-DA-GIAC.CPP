#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    ll x[n], y[n];
    for (int i = 0; i < n; i++) cin>>x[i]>>y[i];
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        res += x[i] * y[j] - y[i] * x[j];
    }
    cout<<abs(res);
    return 0;
}