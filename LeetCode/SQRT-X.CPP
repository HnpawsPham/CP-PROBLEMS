#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>x;
    int l = 0, r = x, mid, res;
    ll sqr;

    while(l <= r){
        mid = (l + r) / 2;
        sqr = (ll)mid * mid;
        if(sqr == x) return cout<<mid, 0;
        else if(sqr < x){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}