#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0, l = 0;
    ll mul = 1;
    
    for(int r = 0; r < n; r++){
        mul *= a[r];

        while(l <= r && mul >= k){
            mul /= a[l];
            l++;
        }
        cnt += r - l + 1;
    }
    cout<<cnt;
    return 0;
}

// 4
// 100
// 10 5 2 6