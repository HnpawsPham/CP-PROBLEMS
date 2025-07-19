#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int minn = 1, maxx = 1, res = INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) swap(minn, maxx);
        minn = min(minn * a[i], a[i]);
        maxx = max(maxx * a[i], a[i]);
        res = max(res, maxx);
    }
    cout<<res;
    return 0;
}