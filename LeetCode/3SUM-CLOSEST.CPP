#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int l, r, n = a.size();
    ll sum, target, nearest = 1e9;
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        l = i + 1;
        r = n - 1;
        target = k - a[i];

        while (l < r) {
            sum = a[l] + a[r];
            if (sum == target) return cout<<k, 0;

            else if (sum < target) l++;
            else r--;

            if ((ll)abs(target - sum) < (ll)abs(k - nearest))
                nearest = a[i] + sum;
        }
    }
    cout<<nearest;
    return 0;
}