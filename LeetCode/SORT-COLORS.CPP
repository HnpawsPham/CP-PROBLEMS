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

    int c0 = 0, c1 = 0, c2 = 0;
    for(int x : a){
        if(x == 0) c0++;
        else if(x == 1) c1++;
        else c2++;
    }
    for(int i = 0; i < c0; i++) a[i] = 0;
    for(int i = c0; i < c0 + c1; i++) a[i] = 1;
    for(int i = c0 + c1; i < c0 + c1 + c2; i++) a[i] = 2;

    for(int x : a) cout<<x<<" ";
    return 0;
}