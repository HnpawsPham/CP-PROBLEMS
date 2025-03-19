#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll p;

int main(){
    freopen("JUMP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>p;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = 0;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(a + i + 1, a + n, 1LL * p + a[i]) - a;
        if(pos < n) maxx = max(maxx, pos - i);
    }
    cout<<maxx;

    return 0;
}