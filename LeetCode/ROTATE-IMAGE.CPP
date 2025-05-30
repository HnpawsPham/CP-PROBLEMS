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

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(a[i][j], a[j][i]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n / 2; j++)
            swap(a[i][j], a[i][n - j - 1]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout<<a[i][j]<<" ";
        cout<<el;
    }
    return 0;
}