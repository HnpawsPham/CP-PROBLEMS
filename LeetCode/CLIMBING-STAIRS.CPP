#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int dp0 = 1, dp1 = 1, cur = 1;

    for(int i = 2; i <= n; i++){
        cur = dp0 + dp1;
        dp0 = dp1;
        dp1 = cur;
    }

    return 0;
}