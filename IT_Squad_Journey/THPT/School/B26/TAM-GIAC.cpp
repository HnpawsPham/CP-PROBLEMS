#include <bits/stdc++.h>
using namespace std;
#define el "\n"

double xa, ya, xb, yb, xc, yc, xm, ym;
bool ok = 1;

double get_dis(double x, double y, double x1, double y1, double x2, double y2){
    return x * (y2 - y1) - y * (x2 - x1) - (y2 - y1) * x1 + (x2 - x1) * y1;
}

void check(double x1, double y1, double x2, double y2, double x3, double y3){
    double p = get_dis(xm, ym, x2, y2, x3, y3);
    double q = get_dis(x1, y1, x2, y2, x3, y3);
    ok = ok && (p * q) >= 0;
    return;
}

int main(){
    freopen(".\\txt\\TAM-GIAC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>xa>>ya>>xb>>yb>>xc>>yc>>xm>>ym;
    check(xa, ya, xb, yb, xc, yc);
    check(xb, yb, xa, ya, xc, yc);
    check(xc, yc, xa, ya, xb, yb);
    cout<<ok;

    return 0;
}