#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll x = 0, maxx = 0, minn = 0;
    for(int num : a){
        x += num;
        minn = min(minn, x);
        maxx = max(maxx, x);
    }

    cout<<max(0LL, (r - l + 1) - (maxx - minn));
    return 0;
}