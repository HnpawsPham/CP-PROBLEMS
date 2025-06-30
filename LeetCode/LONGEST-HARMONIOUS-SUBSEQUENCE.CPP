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

    map<int, int> mp;
    for(const int& x : a) mp[x]++;

    int res = 0, tmp = INT_MAX, prev = 0;
    for(const auto& [x, cnt] : mp){
        if(x - tmp <= 1)
            res = max(res, cnt + prev);

        tmp = x;
        prev = cnt;
    }
    cout<<res;

    return 0;
}