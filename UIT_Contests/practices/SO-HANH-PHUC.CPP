#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        bool ok = 1;
        mp.clear();

        while(a[i] != 1 && a[i] != 7){
            if(mp[a[i]]){
                ok = 0;
                break;
            }
            mp[a[i]]++;
            
            int x = a[i];
            ll sum = 0;

            while(x > 0){
                sum += (x % 10) * (x % 10);
                x /= 10;
            }
            a[i] = sum;
        }

        if(ok) cnt++;
    }
    cout<<cnt;
    return 0;
}