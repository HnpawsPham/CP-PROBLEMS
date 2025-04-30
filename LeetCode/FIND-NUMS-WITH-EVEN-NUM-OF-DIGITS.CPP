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

    int res = 0;
    for(int x : a){
        int cnt = 0;
        while(x > 0){
            x /= 10;
            cnt++;
        }
        res += (cnt % 2 == 0);
    }
    cout<<res;
    return 0;
}