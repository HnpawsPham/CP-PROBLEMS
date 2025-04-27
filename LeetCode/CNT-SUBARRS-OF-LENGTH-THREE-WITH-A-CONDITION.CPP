#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0;
    for(int i = 0; i < n - 2; i++){
        if(float(a[i] + a[i + 2]) == float(a[i + 1]) / 2)
            cnt++;
    }
    cout<<cnt;
    return 0;
}