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
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0, cnt0 = 0, l = 0;
    for(int r = 0; r < n; r++){
        cnt0 += (a[r] == 0);

        while(l <= r && cnt0 > 1)
            cnt0 -= (a[l++] == 0);
        
        if(cnt0 <= 1) res = max(r - l + 1, res);  
    }
    cout<<res - 1;
    return 0;
}

// 4
// 1 1 0 1

// 9
// 0 1 1 1 0 1 1 0 1