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
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<ll>());

    for(int i = 0; i < n; i++){
        if(n - i < 3){
            sum = 0;
            break;
        }

        if(a[i] >= sum - a[i]) sum -= a[i];
        else break;
    }
    cout<<sum;
    return 0;
}