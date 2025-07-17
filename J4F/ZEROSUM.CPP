#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll sum = 0, cnt = 0;
    unordered_map<ll, ll> mp;
    mp[0] = 1;

    for(int i = 0; i < n; i++){
        sum += a[i];
        cnt += mp[sum];
        mp[sum]++;
    }
    cout<<cnt;
    return 0;
}
// 6
// -6 0 1 2 3 -6