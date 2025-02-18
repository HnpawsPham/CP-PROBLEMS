#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += a[i - 1];
    }
    cin>>q;
    
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<a[r] - a[l - 1]<<el;
    }

    return 0;
}