#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    ll a[n];
    for(int i = 0; i < n;i++) cin>>a[i];
    
    sort(a, a + n);
    cout<<max(abs(a[0] + a[1]), abs(a[n - 2] + a[n - 1]));

    return 0;
}