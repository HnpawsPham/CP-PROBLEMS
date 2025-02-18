#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    int n = str.length();
    int sum = 0;
    for(char x : str) sum += int(x - '0');

    cout<<n<<el<<str[n - 1]<<el<<str[0]<<el<<sum<<el;
    reverse(str.begin(), str.end());
    cout<<stoll(str);

    return 0;
}