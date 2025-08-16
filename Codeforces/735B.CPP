#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, n1, n2;
    cin>>n>>n1>>n2;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n, greater<int>());
    if(n1 > n2) swap(n1, n2);

    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < n1; i++) sum1 += a[i];
    sum1 /= n1;

    for(int i = n1; i < n2 + n1; i++) sum2 += a[i];
    sum2 /= n2;

    cout<<fixed<<setprecision(6)<<sum1 + sum2;
    return 0;
}