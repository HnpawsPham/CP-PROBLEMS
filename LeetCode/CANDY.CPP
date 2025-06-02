#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int b[n];
    for(int i = 0; i < n ;i++) cin>>b[i];

    vi a(n, 1);
    for(int i = 1; i < n; i++)
        if(b[i] > b[i - 1]) a[i] = a[i - 1] + 1;
    
    for(int i = n - 2; i >= 0; i--)
        if(b[i] > b[i + 1]) a[i] = max(a[i], a[i + 1] + 1);

    // for(int x : a) cout<<x<<" ";
    int res = accumulate(a.begin(), a.end(), 0);
    cout<<res;
    return 0;
}