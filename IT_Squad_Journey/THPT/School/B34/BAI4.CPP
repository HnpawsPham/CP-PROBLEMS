#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el '\n'


int main(){
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    // x % 2 = y % 2 => even
    ll odd = 0, even = 1, len = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum % 2){
            len += odd;
            odd++; 
        }
        else{
            len += even;
            even++;
        }
    }
    cout<<len;
    return 0;
}