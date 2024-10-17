#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define bit(mask, i) ((mask >> i)&1)

const int m = 4;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[m][n], dp[m][n];
    
    for(int i = 0; i < m;i++)
        for(int j = 0; j < n;j++) cin>>a[i][j];

    return 0;
}