#include <bits/stdc++.h>
using namespace std;
using ll = long int;
#define el "\n"

int n;

int main(){
    freopen(".\\txt\\DAY-CON.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n];
    for(int i = 0;i<n;i++) cin>>a[i];

    vector<ll> dp;
    for(int i = 0;i<n;i++){
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

        if(pos == dp.size()) dp.push_back(a[i]);
        else dp[pos] = a[i];
    }
    cout<<dp.size()<<el;

    return 0;
}