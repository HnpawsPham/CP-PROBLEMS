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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int len = 1;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] > a[i + 1]) break;
        len++;
    }
    cout<<n - len;
    return 0;
}