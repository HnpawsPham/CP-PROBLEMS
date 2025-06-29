#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    int m = __gcd(a, b);

    int n;

    if(m < 10) n = m;
    else n = int(to_string(m)[0] - '0');
    cout<<m<<" "<<n;

    return 0;
}