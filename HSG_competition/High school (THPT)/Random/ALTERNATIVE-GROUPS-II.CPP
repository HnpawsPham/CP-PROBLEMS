#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    bool a[n * 2];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i + n] = a[i];
    }

    int len = 1, maxx = 0;
    for(int i = 1; i < n * 2; i++){
        if(a[i] ^ a[i - 1] == 1) len++;
        else len = 1;
        maxx = max(maxx, len);
    }
    int res = maxx - k + 1;
    if(maxx == n * 2) res = (res + 1) / 2 + 1;
    cout<<max(0, res);
    return 0;
}