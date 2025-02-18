#include <bits/stdc++.h>
using namespace std;
#define el "\n"

double xa, ya, xb, yb;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>xa>>ya>>xb>>yb;
    double res = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    cout<<fixed<<setprecision(4)<<res;

    return 0;
}