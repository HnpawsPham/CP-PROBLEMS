#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    string rs = str;
    reverse(rs.begin(), rs.end());
    cout<<(str == rs ? "YES" : "NO");

    return 0;
}