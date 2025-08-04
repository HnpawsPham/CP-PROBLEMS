#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int calc(int l, int r, int st, vector<vi>& a){
    if(a[r][0] <= st) return st - a[l][0];
    if(a[l][0] >= st) return a[r][0] - st;

    return min(abs(st - a[l][0]), abs(a[r][0] - st)) + a[r][0] - a[l][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, st, k;
    cin>>n>>st>>k;

    vector<vi> a(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        a[i] = {l, r};
    }

    int sum = 0, res = 0, l = 0;
    for(int r = 0; r < n; r++){
        sum += a[r][1];

        while(l <= r && calc(l, r, st, a) > k){
            sum -= a[l][1];
            l++;
        }
        res = max(res, sum);
    }
    cout<<res;
    return 0;
}