#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 0;
    int l = -1, r = -1, st = -1;
    
    for(int i = 0; i < n; i++){
        if(a[i] < mink || a[i] > maxk)
            st = i;
        
        if(a[i] == mink) l = i;
        if(a[i] == maxk) r = i;

        res += max(0, min(l, r) - st);
    }
    cout<<res;
    return 0;
}