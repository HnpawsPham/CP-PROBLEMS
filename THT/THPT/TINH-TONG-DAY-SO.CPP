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
    ll sum = 0;

    int i = 1;
    for(int j = 0; j < m; j+=2){
        sum = sum + i + n - (i - 1);
        i++;
    }
    if(m % 2) sum -= n - (i - 2);
    cout<<sum;
    return 0;
}