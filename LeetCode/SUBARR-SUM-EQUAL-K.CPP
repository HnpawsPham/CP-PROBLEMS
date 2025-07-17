#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum = 0, cnt = 0;
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        sum += a[i]; 
        if(sum == k) cnt++;
        cnt += mp[sum - k];
        mp[sum]++;
    }
    cout<<cnt;
    return 0;
}