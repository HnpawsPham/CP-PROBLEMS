#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, x;

int main(){
    freopen("TINHTONG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll sum = 0;

    for(int i = 0; i < n; i++){
        cin>>x;
        if(x % 10 > x / 10 % 10) sum += x;
    }
    cout<<sum;

    return 0;
}