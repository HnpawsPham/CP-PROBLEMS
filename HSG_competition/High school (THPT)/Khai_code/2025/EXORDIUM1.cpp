#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    cout<<a + b<<el<<a - b<<el<<b - a<<el<<a * b;
    return 0;
}