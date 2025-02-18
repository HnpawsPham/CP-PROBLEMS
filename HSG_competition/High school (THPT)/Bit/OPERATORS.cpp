#include <bits/stdc++.h>
using namespace std;
#define el '\n'

void bin(int x){
    string ss = "";

    while(x > 0){
        if (x & 1) ss += '1';
        else ss += '0';
        x >>= 1;
    }
    reverse(ss.begin(), ss.end());
    cout<<ss<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // bin(3);
    bitset<10> b("0000");
    cout<<b.count()<<el;

    return 0;
}