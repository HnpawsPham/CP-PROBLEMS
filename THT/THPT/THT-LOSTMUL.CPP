#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(n == m) return cout<<0, 0;
    
    bool check[m + 1] = {0};

    while(n--){
        int x;
        cin>>x;
        check[x] = 1;
    }

    ll mul = 1;
    for(int i = 1; i <= m; i++)
        if(!check[i]) mul = (mul * i) % MOD;
    
    cout<<mul;
    return 0;
}