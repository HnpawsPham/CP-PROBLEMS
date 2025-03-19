#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll w = n / 168;
    ll d = n % 168 / 24;
    ll h = n % 168 % 24;
    cout<<w<<" "<<d<<" "<<h;

    return 0;
}