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

    unordered_map<int, int> mp;
    for(int x : a) mp[x]++;

    vector<int> res;
    for(int i = 100; i < 999; i+=2){
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;

        mp[a]--; mp[b]--; mp[c]--;

        if(mp[a] >= 0 && mp[b] >= 0 && mp[c] >= 0)
            res.push_back(i);

        mp[a]++; mp[b]++; mp[c]++;
    }
    
    for(int x : res) cout<<x<<" ";
    return 0;
}