#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        if(n == 0) {
            cout<<"Tong "<<1<<" so nhi phan. ";
            continue;
        }

        int maxx = 0;
        while(n > 0){
            maxx = max(maxx, n % 10);
            n /= 10;
        }
        cout<<"Tong "<<maxx<<" so nhi phan. ";
    }

    return 0;
}
