#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, limit;

ll calc(int n){
    return (n > 0 ? 1LL * (n + 2) * (n + 1) / 2: 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>limit;
    ll cnt = calc(n);

    cnt -= 3 * calc(n - limit - 1);
    cnt += 3 * calc(n - 2 * limit - 2);
    cnt -= 3 * calc(n - 3 * limit - 3);

    cout<<cnt;
    return 0;
}