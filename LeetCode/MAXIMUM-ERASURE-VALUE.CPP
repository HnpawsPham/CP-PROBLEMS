#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, maxx = 0, sum = 0;
    vector<int> mp(1e4 + 1, 0);

    for(int r = 0; r < n; r++){
        mp[a[r]]++;
        sum += a[r];

        while(mp[a[r]] > 1){
            mp[a[l]]--;
            sum -= a[l];
            l++;
        }
        maxx = max(maxx, sum);
    }
    cout<<maxx;
    return 0;
}

// 5
// 4 2 4 5 6