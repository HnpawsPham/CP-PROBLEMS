#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int a, b, c, d;

int get(int from, int to){
    int res = abs(to - from);
    int reverse = 10 - res;
    return min(res, reverse);
}

int main(){
    freopen(".\\txt\\KHOASO.INP", "r", stdin);
    freopen("KHOASO.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>d;

    cout<<get(a, 2) + get(b, 0) + get(c, 2) + get(d, 5);

    return 0;
}