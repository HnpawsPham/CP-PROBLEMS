#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll w;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>w;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = *min_element(a, a + n);
    ll r = *max_element(a, a + n) + w;

    ll res;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll sum = 0;

        for(int x : a)
            if(x < mid)
                sum += mid - x;
        
        if(sum <= w){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}