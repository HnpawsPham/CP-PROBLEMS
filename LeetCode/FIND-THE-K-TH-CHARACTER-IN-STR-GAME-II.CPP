#include <bits/stdc++.h>
using namespace std;
using db = double;
#define el "\n"

int n;
db k;

db ppow(int a, int b){
    if(b == 0) return 1;
    db half = ppow(a, b / 2);

    if(b & 1) return 1LL * half * half * a;
    return 1LL * half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>n;
    bool a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    db len = ppow(2, n);

    int d = 0;
    for(int i = n - 1; i >= 0; i--){
        len /= 2;
        if(k > len){
            k -= len;
            if(a[i]) d++;
        }
    }

    cout<<char((d % 26) + 'a');
    return 0;
}