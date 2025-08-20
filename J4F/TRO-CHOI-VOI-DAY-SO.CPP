#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    sort(b, b + n);

    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(b, b + n, -a[i]) - b;
        if(pos < n) res = min(res, abs(a[i] + b[pos]));
        if(pos > 0) res = min(res, abs(a[i] + b[pos - 1]));
    }
    cout<<res;
    return 0;
}