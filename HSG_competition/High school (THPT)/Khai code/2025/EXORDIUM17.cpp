#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"

int n; ll k;
const int maxn = (int)1e6 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll t = k % n;

    for(int i = t; i < n; i++) cout << a[i] << " ";
    for(int i = 0; i < t; i++) cout << a[i] << " ";
    cout << el;

    for(int i = n - t; i < n; i++) cout << a[i] << " ";
    for(int i = 0; i < n - t; i++) cout << a[i] << " ";
    cout << el;

    return 0;
}