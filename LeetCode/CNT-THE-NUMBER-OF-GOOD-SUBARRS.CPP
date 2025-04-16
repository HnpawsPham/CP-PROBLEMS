#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pli pair<ll, int>
#define fi first
#define se second

int n;
ll k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll a[n];
    
    for(int i = 0; i < n; i++) cin>>a[n - i - 1];

    unordered_map<ll, int> mp;
    
    int l = 0, cnt = 0;
    ll res = 0;

    for(int r = 0; r < n; r++){
        cnt += mp[a[r]];
        mp[a[r]]++;

        while(cnt >= k){
            res += n - r;

            mp[a[l]]--;
            cnt -= mp[a[l]];
            l++;
        }
    }    
    cout<<res;

    return 0;
}