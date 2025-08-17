#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int res = (k - 1) % n + 1;

        if(n % 2){
            int d = (k - 1) / (n / 2);
            res = (res + d - 1) % n + 1;
        }
        cout<<res<<el;
    }

    return 0;
}