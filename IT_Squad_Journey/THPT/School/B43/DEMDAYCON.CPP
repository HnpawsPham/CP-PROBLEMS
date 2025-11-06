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

int n;
ll s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0, l = 0;
    ll sum = 0;
    for(int r = 0; r < n; r++){
        sum += abs(a[r]);

        if(sum > s) cnt++;
        while(sum > s){
            sum -= abs(a[l]);
            l++;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

// 4 4
// 5 -1 8 -5

// 10 7
// -4 9 2 -11 -3 8 -6 5 -3 1