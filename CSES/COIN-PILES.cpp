#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t;
ll a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a>>b;

        ll x = 2 * a - b;
        ll y = 2 * b - a;
        cout<<(x < 0 || y < 0 || x % 3 || y % 3 ? "NO" : "YES")<<el;
    }
    return 0;
}
