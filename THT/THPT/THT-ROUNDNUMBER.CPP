#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    cout<<s[0]<<setfill('0')<<setw(s.length() - 1)<<"";
    return 0;
}