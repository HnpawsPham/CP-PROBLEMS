#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[n] = {0};
    for(int i = 0; i < n; i++)
        for(char x : a[i])
            if(x == '1') cnt[i]++;

    int res = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(cnt[j] > 0){
                res += cnt[i] * cnt[j];
                break;
            }
    cout<<res;
    return 0;
}

// 4
// 011001
// 000000
// 010100
// 001000