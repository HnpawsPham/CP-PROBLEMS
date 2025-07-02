#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n, k;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k>>s;

        int cnt1 = 0;
        for(int i = 0; i < n; i++)
            cnt1 += (s[i] == '1');

        cout<<(cnt1 <= k || n < 2 * k ? "alice" : "bob")<<el;
    }

    return 0;
}