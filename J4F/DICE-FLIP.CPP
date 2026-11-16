#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define el "\n"
#define vi vector<int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int face[4] = {3,6,4,1};
    cout<<face[n % 4];
    return 0;
}