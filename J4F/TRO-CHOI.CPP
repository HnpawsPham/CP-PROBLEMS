#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    sort(a, a + n);
    
    ll n1 = 0, n2 = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) n1 += a[i];
        else n2 += a[i];
    }
    cout<<abs(n1 - n2);

    return 0;
}