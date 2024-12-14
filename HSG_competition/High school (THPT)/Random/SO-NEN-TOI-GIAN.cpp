#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll n;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;

    while(t--){
        cin>>n;
        int s = 0;
        while(n > 0){
            s += n % 10;
            n/=10;
        }

        ll res = s % 9;
        if(!res) res = 9;
        cout<<res<<el;
    }
    return 0;
}