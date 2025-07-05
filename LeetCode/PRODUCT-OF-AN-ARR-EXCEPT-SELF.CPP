#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<int> l(n, 1), r(n, 1);
    for(int i = 0; i < n - 1; i++)
        l[i + 1] = l[i] * a[i];

    for(int i = n - 1; i > 0; i--)
        r[i - 1] = r[i] * a[i];

    // for(int i = 0; i < n; i++) cout<<r[i]<<" ";
    vector<int> res(n);
    for(int i = 0; i < n; i++)
        res[i] = l[i] * r[i];
    
    for(int x : res) cout<<x<<" ";
    return 0;
}