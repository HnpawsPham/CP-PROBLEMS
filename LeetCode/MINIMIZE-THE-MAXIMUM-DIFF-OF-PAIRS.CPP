#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, p;

bool check(int x, vi& a){
    int cnt = 0;

    for(int i = 1; i < n;){
        if(a[i] - a[i - 1] <= x){
            cnt++;
            i += 2;
        }
        else i++;
    }
    return cnt >= p;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>p;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    int l = 0, r = a[n - 1] - a[0], mid, res;
    while(l <= r){
        mid = l + (r - l) / 2;

        if(check(mid, a)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout<<res;
    return 0;
}