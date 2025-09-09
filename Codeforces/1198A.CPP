#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin>>n>>b;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int k = 1 << min(19, b * 8 / n);
    sort(a, a + n);

    unordered_map<int, int> mp;
    int l = 0, res = n;
    for(int r = 0; r < n; r++){
        mp[a[r]]++;

        while(l <= r && mp.size() > k){
            if(--mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }

        if(l <= r)
            res = min(res, n - r + l - 1);
    }
    cout<<res;
    return 0;
}