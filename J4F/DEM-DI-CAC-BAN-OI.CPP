#include <iostream>
using namespace std;
#define el '\n'

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; ++i) cin>>a[i];

    int cnt[23] = {0};
    long long res = 0;

    for(int i = 6; i < n; ++i){
        cnt[a[i - 6] % 23]++;
        res += cnt[a[i] % 23];
    }
    return cout<<res, 0;
}