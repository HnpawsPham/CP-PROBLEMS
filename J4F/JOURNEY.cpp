#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        ll n; int a, b, c;
        cin>>n>>a>>b>>c;

        int sum = a + b + c;
        int res = n / sum * 3;
        int left = n % sum;

        if(left){
            if(a >= left) res++;
            else if(a + b >= left) res += 2;
            else if(a + b + c >= left) res += 3;
        }

        cout<<res<<el;
    }

    return 0;
}