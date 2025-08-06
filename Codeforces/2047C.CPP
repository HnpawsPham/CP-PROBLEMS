#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; i++) cin>>a[i];
        for(int i = 1; i <= n; i++) cin>>b[i];

        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += max(a[i], b[i]);

        int res = INT_MIN;
        for(int i = 1; i <= n; i++)
            res = max(res, sum + a[i] + b[i] - max(a[i], b[i]));

        cout<<res<<el;
    }  
    return 0;
}