#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    for(int x : a) mp[x]++;
    
    int cnt = 0;
    for(pii x : mp){
        int same_color = x.fi, same_ans = x.se;
        cnt += ((same_ans + same_color) / (same_color + 1)) * (same_color + 1);
    }

    cout<<cnt;
    return 0;
}