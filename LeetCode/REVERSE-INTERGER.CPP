#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int x;

int main(){
    cin>>x;
    if(x > INT_MAX || x < INT_MIN) return cout<<0, 0;

    string s = to_string(abs(x));
    std::reverse(s.begin(), s.end());
    if(x < 0) s = '-' + s;
    int res;

    try { res = stoi(s);}
    catch (...) {return cout<<0, 0;}

    cout<<res;
    return 0;
}