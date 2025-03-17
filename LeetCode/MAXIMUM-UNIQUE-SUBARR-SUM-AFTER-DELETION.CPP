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
    unordered_map<int, int> mp;
    
    int sum = 0, maxx = -INT_MAX;
    for(int x : a){
        maxx = max(x, maxx);
        if(x <= 0 || mp[x]) continue;
        sum += x; 
        mp[x]++;
    }
    if(sum == 0) sum = maxx;
    cout<<sum;
    return 0;
}