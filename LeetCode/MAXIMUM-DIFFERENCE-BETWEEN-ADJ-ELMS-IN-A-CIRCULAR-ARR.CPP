#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = INT_MIN;
    for(int i = 0; i < n - 1; i++)
        maxx = max(maxx, abs(a[i] - a[i + 1]));

    maxx = max(maxx, (a[n - 1] - a[0]));
    cout<<maxx;

    return 0;
}