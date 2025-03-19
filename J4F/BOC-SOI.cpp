#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

ll n, m;

// Boc sao cho den luot doi thu con m + 1  vien soi
// => n k chia het cho m + 1 (con du soi thi minh moi boc de thang duoc)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(n % (m + 1) != 0) cout<<"POSSIBLE";
    else cout<<"IMPOSSIBLE";
    return 0;
}