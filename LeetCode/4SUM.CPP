#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l, r, sum;
    ll target;

    sort(a, a + n);

    for(int i = 0; i < n - 3; ++i){
        if(i > 0 && a[i] == a[i - 1]) continue;

        for(int j = i + 1; j < n - 2; ++j){
            if(j > i + 1 && a[j] == a[j - 1]) continue;

            l = j + 1;
            r = n - 1;
            target = k * 1LL - a[i] * 1LL - a[j] * 1LL;

            while(l < r){
                sum = a[l] + a[r];
                if(sum == target){
                    cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<" "<<a[r]<<el;
                    
                    while(l < r && a[l] == a[l + 1]) l++;
                    while(l < r && a[r] == a[r - 1]) r--;
                    l++; r--;
                }
                else if(sum > target) r--;
                else l++;
            }
        }
    }
    return 0;
}