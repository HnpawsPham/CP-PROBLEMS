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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt0 = 0, res = 0, l = 0;
    int bestl = -1, bestr = -1;
    for(int r = 0; r < n; r++){
        cnt0 += 1 - a[r];

        while(l <= r && cnt0 > k){
            cnt0 -= 1 - a[l];
            l++;
        }

        if(cnt0 <= k && r - l + 1 > res) {
            res = r - l + 1;
            bestl = l;
            bestr = r;
        }
    }
    for(int i = bestl; i <= bestr; i++) a[i] = 1;
    cout<<res<<el;
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    return 0;
}