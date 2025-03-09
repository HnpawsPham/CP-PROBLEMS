#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n == 0) return cout<<0, 0;

    string res = "";
    while(n != 0){
        int mod = n % (-2);
        n /= -2;

        if(mod < 0){
            mod += 2;
            n += 1;
        }

        res += char(mod + '0');
    }
    reverse(res.begin(), res.end());
    cout<<res;
    return 0;
}