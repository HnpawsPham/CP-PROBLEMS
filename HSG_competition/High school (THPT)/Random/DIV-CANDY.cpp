#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cout<<(n % m == 0 ? "Yes" : "No"); 
    return 0;
}