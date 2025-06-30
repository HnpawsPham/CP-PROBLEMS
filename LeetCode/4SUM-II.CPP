#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n;

void inp(vi& a){
    for(int i = 0; i < n; i++) cin>>a[i];
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n), b(n), c(n), d(n);
    inp(a); inp(b); inp(c); inp(d);

    unordered_map<int, int> mp;
    for(const int& x : c)
        for(const int& y : d)
            mp[x + y]++;

    int cnt = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int target = 0 - a[i] - b[j];
            if(mp[target]) cnt+= mp[target];
        }

    cout<<cnt;
    return 0;
}