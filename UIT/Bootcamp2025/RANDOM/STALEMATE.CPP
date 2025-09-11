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

    int n, k;
    cin>>n>>k;

    int res;
    if(k == 2)
        res = ((n - 2) * (n - 2) + 2 * (n - 2)) * 4 + 4 * (n - 2);
    else{
        ll s1 = (n - 2) * ((n - 2) + (n - 3) + 2 * (n - 2) * (n - 2) + (n - 2) * (n - 2) * (n - 2) + (n - 2) * (n - 3)) * 4;
        ll s2 = (n * n - 2 * n - 1 + (n - 2) * ((n - 2) * (n - 3) + 2 * (n - 3) + 2 * (n - 2))) * 4 * (n - 2);
        ll s3 = 4 * (n - 2) * (n - 2) * (n - 2);
        res = s1 + s2 + s3;
    }
    cout<<res;
    return 0;
}