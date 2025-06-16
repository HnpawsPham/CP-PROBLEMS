#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0, minn = a[0];

    for(int i = 1; i < n; i++){
        res = max(res, a[i] - minn);
        minn = min(minn, a[i]);
    }
    cout<<res;

    return 0;
}