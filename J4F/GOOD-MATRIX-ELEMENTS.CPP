#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int sum = 0;
    for(int i = 0, j = 0; i < n && j < n; i++, j++) sum += a[i][j];
    for(int i = n - 1, j = 0; i >= 0 && j < n; i--, j++) sum += a[i][j];

    for(int i = 0; i < n; i++) sum += a[i][n / 2];
    for(int i = 0; i < n; i++) sum += a[n / 2][i];
    cout<<sum - a[n / 2][n / 2] * 3;
    return 0;
}