#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    int sz = a.length();

    if(sz > b.size()) return cout<<"No", 0;
    for(int i = 0; i < sz; i++)
        if(a[i] != b[i]) return cout<<"No", 0;
    cout<<"Yes";
    return 0;
}