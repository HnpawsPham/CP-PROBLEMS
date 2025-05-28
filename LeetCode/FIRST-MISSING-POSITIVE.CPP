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

    vector<bool> mp(n + 1, 0);

    for(const int& x : a)
        if(x > 0 && x <= n) mp[x] = 1;

    for(int i = 1; i <= n; i++)
        if(!mp[i]) return cout<<i, 0;
    
    cout<<n + 1;
    return 0;
}