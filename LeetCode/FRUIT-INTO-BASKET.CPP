#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;

    int l = 0, res = 0;
    for(int r = 0; r < n; r++){
        mp[a[r]]++;

        while(mp.size() > 2){
            mp[a[l]]--;
            if(mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}