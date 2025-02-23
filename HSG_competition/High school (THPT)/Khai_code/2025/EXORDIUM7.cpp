#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;

    int cnt = 0, sum = 0;
    for(int i = 1; i <= n; i++)
        if(n % i == 0){
            cnt++;
            sum += i;
            cout<<i<<" ";
        }
    cout<<el<<cnt<<el<<sum;

    return 0;
}