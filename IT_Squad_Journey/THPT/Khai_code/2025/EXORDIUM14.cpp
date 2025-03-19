#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int d = (n % 2);
    for(int i = d; i <= n; i+=2)
        sum += i;
    cout<<sum;

    return 0;
}