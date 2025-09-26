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
    vi a(n);

    int cnt = 0;
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            int pos = lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin();
            cnt += max(0, pos - j - 1);
        }
    cout<<cnt;
    return 0;
}