#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5;
    int a[] = {3, 6, 2, 8, 4};

    for(int i = 0; i < (1 << n); i++){
        for(int j = 0;j < n;j++){
            if((i >> j) & 1) cout<<a[j]<<" ";
        }
        cout<<el;
    }

    return 0;
}