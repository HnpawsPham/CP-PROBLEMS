#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n, j, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>j>>k;
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];

        int maxx = 0;
        for(int i = 0; i < n; i++)
            maxx = max(maxx, a[i]);

        cout<<(k > 1 || a[j - 1] == maxx ? "YES" : "NO")<<el;
    }

    return 0;
}