#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin>>n>>k;
    ll cnt_even = n / 2, cnt_odd = n - cnt_even;
    ll lim_odd = n - 1 + (n % 2), lim_even = n - (n % 2);

    if(k <= cnt_odd) cout<<lim_odd - (cnt_odd - k) * 2;
    else cout<<lim_even - (n - k) * 2;
    return 0;
}