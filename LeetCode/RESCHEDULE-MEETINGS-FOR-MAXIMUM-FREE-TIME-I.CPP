#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int t, k, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t>>k>>n;
    vi l(n), r(n);
    for(int i = 0; i < n; i++) cin>>l[i];
    for(int i = 0; i < n; i++) cin>>r[i];
    
    int last = 0;
    vi a;
    for(int i = 0; i < n; i++){
        a.push_back(l[i] - last);
        last = r[i];
    }
    a.push_back(t - r[n - 1]);

    int sum = 0, res = 0, sz = n - k + 1;

    for(int i = 0; i < n; i++){
        sum += a[i];

        if(i >= sz) sum -= a[i - sz];
        res = max(res, sum);
    }
    cout<<res;
    return 0;
}

// 5 1 2
// 1 3
// 2 5

// 21 1 3
// 7 10 16
// 10 14 18