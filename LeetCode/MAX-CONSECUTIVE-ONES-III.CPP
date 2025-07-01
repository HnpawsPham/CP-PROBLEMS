#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, res = 0, cnt = 0;
    for(int r = 0; r < n; r++){
        if(!a[r]) cnt++;

        while(cnt > k && l <= r)
            if(!a[l++]) cnt--;

        if(cnt <= k)
            res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}

// 11 2
// 1 1 1 0 0 0 1 1 1 1 1 0