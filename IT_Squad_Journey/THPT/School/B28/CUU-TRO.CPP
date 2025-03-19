#include <iostream>
using namespace std;
using ll = unsigned long long;
#define el "\n"

ll n;

void sol(){
    ll i = 1, t = 0;
    while(i <= n){
        t += i * i;
        if(n - t < 1LL * (i + 1) * (i + 1)){
            cout<<i<<el<<1LL * n - t;
            return;
        }
        i++;
    }
    return;
}

int main(){
    freopen("CUU-TRO.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sol();
    return 0; 
}