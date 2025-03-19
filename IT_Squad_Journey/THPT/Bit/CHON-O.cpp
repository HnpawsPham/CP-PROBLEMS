#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define bit(mask, i) ((mask >> i)&1)

const int m = 4;
int n, res = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[m][n], dp[m][n];
    
    for(int i = 0; i < m;i++)
        for(int j = 0; j < n;j++) cin>>a[i][j];

    for(int i = 1; i < 15;i++){
        bool ok = true;
        for(int j = 0; j < 3; j++){
            if(bit(i, j) && bit(i, j + 1)) ok = false; 
        }
    }
    cout<<res<<el;
    return 0;
}