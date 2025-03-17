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
    
    int temp = n;
    n = abs(n);
    string res = "";
    
    while(n > 0){
        res += char((n % 7) + '0');
        n /= 7;
    }
    reverse(res.begin(), res.end());
    if(temp < 0) cout<<"-";
    cout<<res;

    return 0;
}