#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    double sum = 1;
    while(n--){
        int x;
        cin>>x;
        sum *= x;
    }
    ll x = sqrt(sum);
    cout << (x * x == sum ? "Yes" : "No");
    return 0;
}