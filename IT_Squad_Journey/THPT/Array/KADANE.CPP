#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i = 0;
    cin>>n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum = a[0], res = a[0];
    for(int i = 1; i < n; i++){
        sum = max(a[i], sum + a[i]);
        res = max(res, sum);
    }
    cout<<res;
    return 0;
}