#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, a, b;

    cin>>t;
    while(t--){
        cin>>a>>b;

        int cnt = 0;
        while(a != b){
            if(a < b) swap(a, b);
            a -= b;
            cnt++;
        }
        cout<<cnt<<el;
    }
    return 0;
}