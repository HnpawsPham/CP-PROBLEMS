#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int sum = 0;
    for(int x : a) 
        sum = (sum + x) % k;

    int r = sum % k;
    if(r == 0) return cout<<0, 0;

    unordered_map<int, int> mp;
    mp[0] = -1;
    int mod = 0, res = n + 5;

    for(int i = 0; i < n; i++){
        mod = (mod + a[i]) % k;
        int target = (mod - r + k) % k;
    
        if(mp.find(target) != mp.end())
            res = min(res, i - mp[target]);
        
        mp[mod] = i;
    }
    
    cout<<(res == n + 5 ? -1 : res);
    return 0;
}

// 4 6
// 3 1 4 2

// 4 9
// 6 3 5 2

// 3 3
// 1 2 3