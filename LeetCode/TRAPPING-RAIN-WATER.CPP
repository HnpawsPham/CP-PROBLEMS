#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    // vector<int> l(n), r(n);
    // l[0] = a[0];
    // r[n - 1] = a[n - 1];

    // for(int i = 1; i < n; i++)
    //     l[i] = max(l[i - 1], a[i]);

    // for(int i = n - 2; i >= 0; i--)
    //     r[i] = max(r[i + 1], a[i]);

    // int res = 0;
    // for(int i = 1; i < n - 1; i++)
    //     if(l[i] > a[i] && r[i] > a[i])
    //         res += min(l[i], r[i]) - a[i];

    int res = 0;
    int maxl = 0, maxr = 0, l = 0, r = n - 1;

    while(l <= r){
        if(a[l] < a[r]){
            if(a[l] > maxl) maxl = a[l];
            else res += maxl - a[l];
            l++;
        }
        else{
            if(a[r] > maxr) maxr = a[r];
            else res += maxr - a[r];
            r--;
        }
    }
    cout<<res;
    return 0;
}

// 12
// 0 1 0 2 1 0 1 3 2 1 2 1