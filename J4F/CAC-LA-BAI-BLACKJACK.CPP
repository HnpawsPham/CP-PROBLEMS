#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int res = 0;
    for(int i = 0; i < n - 1; i++){
        int l = i + 1, r = n - 1;

        while(l < r){
            int sum = a[i] + a[l] + a[r];
            
            while(r > l && sum > m)
                sum -= a[r--];

            if(sum <= m) res = max(res, sum);
            l++;
        }
    }
    cout<<res;
    return 0;
}