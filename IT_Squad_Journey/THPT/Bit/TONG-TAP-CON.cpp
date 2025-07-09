#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define bit(mask, i) ((mask>>i) &1)

int n, s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int a[n];

    for(int i = 0; i < n;i++) cin>>a[i];

    int res = 0;
    for(int i = 1; i < (1 << n); i++){
        int sum = 0;
        for(int j = 0; j < n;j++){
            if(bit(i, j)) sum += a[j];
        }
        res += (sum == s);
    }
    cout<<res<<el;

    return 0;
}