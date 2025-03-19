#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

ll m, n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n>>k;
    cout<<m * n - (k * k * (m / k) * (n / k));

    return 0;
}