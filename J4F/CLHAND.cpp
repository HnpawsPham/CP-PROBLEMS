#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

int h, m;
ll z;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>m>>z;
    m += z;
    h += m / 60;
    m %= 60;
    h %= 12;
    
    float res = abs(h * 30 + m * 0.5 - m * 6);
    cout<<(float)min(360 - res, res);

    return 0;
}