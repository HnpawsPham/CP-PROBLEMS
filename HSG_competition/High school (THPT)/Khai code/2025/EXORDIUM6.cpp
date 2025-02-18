#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int h1, m1, s1, h2, m2, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>h1>>m1>>s1>>h2>>m2>>s2;
    int t1 = s1 + m1 * 60 + h1 * 3600;
    int t2 = s2 + m2 * 60 + h2 * 3600;
    int res = abs(t1 - t2);
    int h3 = res / 3600;
    int m3 = res % 3600 / 60;
    int s3 = res % 3600 % 60;
    cout<<h3<<" "<<m3<<" "<<s3;

    return 0;
}