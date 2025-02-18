#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
char k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str>>k;
    int n = str.length();
    for(int i = 0; i < n; i++)
        if(str[i] ==k) cout<<i + 1<<" ";

    return 0;
}