#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

ll n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll res = sqrt(n * 2);
    while(res * (res + 1) /2 >=n) res--;
    cout<<res;
    return 0;
}
