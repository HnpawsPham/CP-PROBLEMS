#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 26;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int fibo[n + 1];
    fibo[0] = fibo[1] = 0;
    fibo[2] = 1;

    for(int i = 3; i <= n; i++)
        fibo[i] = ((fibo[i - 1] + fibo[i - 2]) % MOD + fibo[i - 3]) % MOD;

    cout<<fibo[n];
    return 0;
}