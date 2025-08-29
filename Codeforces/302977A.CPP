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
    if(n % 2) return cout<<0, 0;
    if(n == 2) return cout<<2, 0; 
    // else cout<<(ll)pow(2, n / 2);
    int dp1 = 2, dp2 = 4;
    for(int i = 6; i <= n; i+=2){
        int tmp = dp2 + 2 * dp1;
        dp1 = dp2;
        dp2 = tmp;
    }
    cout<<dp2;
    return 0;
}