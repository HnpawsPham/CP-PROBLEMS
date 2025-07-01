#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int cnt = 1;
    int n = s.length();

    for(int i = 1; i < n; i++)
        if(s[i] == s[i - 1]) cnt++;
    cout<<cnt;
    return 0;
}