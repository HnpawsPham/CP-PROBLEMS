#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] == ax) return cout<<mid, 0;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    cout<<(x > a[mid] ? mid + 1 : mid);
    return 0;
}