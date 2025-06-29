#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, n;
const int maxn = 1e5 + 5;
int a[maxn];

bool check(int a, int b, int c, int maxx){
    int sum = a + b + c;
    return (sum > maxx && sum > 2 * c);
}

ll sol(){
    ll cnt = 0;
    sort(a, a + n);
    int maxx = a[n - 1];

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int sum = a[i] + a[j];

            int l = maxx - sum + 1;
            int r = sum - 1; 
            if(r < l) continue;

            cnt += upper_bound(a + j + 1, a + n, r) - lower_bound(a + j + 1, a + n, l);
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++) cin>>a[i];
        cout<<sol()<<el;
    }

    return 0;
}