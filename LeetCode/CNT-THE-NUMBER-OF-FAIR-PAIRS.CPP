#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, l, r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    ll cnt = 0;

    for(int i = 0; i < n; i++)
        cnt += upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - lower_bound(a.begin() + i + 1, a.end(), l - a[i]);
    
    cout<<cnt;
    return 0;
}