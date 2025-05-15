#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
ll l, v1, v2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>v1>>v2>>k;

    ll m = (n + k - 1) / k;

    double ratio = (double)v1 / v2;
    double a = ratio + (2 * m - 1);
    double b = v1 * (2 * m - 1) + v2;
    double time = (double)l * a / b;

    cout << fixed << setprecision(20) << time << el;
    return 0;
}