#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int t, n;

void sol(){
  int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    int cnt = 0, pos = -1;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) {
            cout<<"YES"<<el<<2<<el;
            cout<<a[i]<<" "<<b[i]<<el;
            return;
        }
    
    cout<<"NO"<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        sol();
    }

    return 0;
}