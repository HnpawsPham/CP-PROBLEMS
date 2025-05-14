#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
#define el "\n"
#define se second

int n;

int main(){
    // freopen("CSBN.inp", "r", stdin);
    // freopen("CSBN.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unordered_map<ll, int> mp;
    while(n--){
        ll x; 
        cin>>x;
        mp[x]++;
    }    

    ll cnt = 0;
    for(auto x : mp)
        cnt += (1LL * x.se * (x.se - 1) / 2);

    cout<<cnt;
    return 0;
}