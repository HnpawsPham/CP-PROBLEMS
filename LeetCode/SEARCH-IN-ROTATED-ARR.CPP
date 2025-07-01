#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int sol(int l, int r, int x, vector<int>& a){
    while(l <= r){
        int mid = (l + r) / 2;
        cout<<a[mid]<<el;

        if(a[mid] == x) return mid;
        
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n - 1, mid;
    while(l < r){
        mid = (l + r) / 2;

        if(a[mid] > a[r])
            l = mid + 1;

        else r = mid;
    }

    int res = sol(l, n - 1, k, a);
    if(res == -1) res = sol(0, l - 1, k, a);
    cout<<res;
    return 0;
}