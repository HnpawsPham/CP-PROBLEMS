#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int k, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++) 
        a[i] += a[i + 1];
    
    sort(a, a + n - 1);

    ll res = 0;
    for(int i = 0; i < k - 1; i++)
        res += 1LL * (a[n - i - 2] - a[i]);

    cout<<res;
    return 0;
}