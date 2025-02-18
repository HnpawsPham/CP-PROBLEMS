#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    cout<<a[k - 1]<<" "<<a[n - k];

    return 0;
}