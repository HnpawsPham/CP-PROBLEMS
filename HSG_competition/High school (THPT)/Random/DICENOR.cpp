#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

ll n;
const int p[7] = {0, 6, 5, 4, 3, 2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll minn;

    if(n <= 6) minn = p[n];
    else minn = (n / 6) + p[n % 6];
    
    cout<< minn <<" "<<n * 6;

    return 0;
}