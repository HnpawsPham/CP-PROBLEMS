#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    freopen("sodep.inp", "r", stdin);
    freopen("sodep.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    cout<<(sum % 10 == 9);
    return 0;
}