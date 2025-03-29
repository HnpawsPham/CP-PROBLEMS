#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a, a + n);
        
    for(int cur = 0; cur < n; cur++){
        if(cur > 0 && a[cur] == a[cur - 1]) continue;
        i = cur + 1; 
        j = n - 1;
        target = 0 - a[cur];

        while(i < j){
            sum = a[i] + a[j];

            if(sum == target){
                cout<<a[cur]<<" "<<a[i]<<" "<<a[j]<<el;

                while (i < j && a[i] == a[i + 1]) i++;
                while(i < j && a[j] == a[j - 1]) j--;
                i++; j--; 
            }
            else if(sum > target) j--;
            else i++;
        }
    }
    return 0;
}