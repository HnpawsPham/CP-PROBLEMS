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

    int l = 0, res = 0;
    for(int r = 0; r < n + k - 1; r++){
        if(r > 0 && a[r % n] == a[(r - 1) % n]) l = r;
        if(r - l + 1 >= k) res++;
    }
    cout<<res;
    return 0;
}