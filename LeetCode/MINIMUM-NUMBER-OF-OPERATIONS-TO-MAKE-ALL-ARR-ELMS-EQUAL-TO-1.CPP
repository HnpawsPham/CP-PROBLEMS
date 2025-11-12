#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
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

    int cnt1 = 0;
    for(int x : a) 
        cnt1 += x == 1;

    if(cnt1 >= 1) return cout<<n - cnt1, 0;
    int len = n + 5;
    
    for(int i = 0; i < n; i++){
        int gcd = a[i];
        for(int j = i + 1; j < n; j++){
            gcd = __gcd(gcd, a[j]);

            if(gcd == 1){
                len = min(len, j - i + 1);
                break;
            }
        }
    }
    if(len == n + 5) cout<<-1;
    else cout<<len - 2 + n;
    return 0;
}