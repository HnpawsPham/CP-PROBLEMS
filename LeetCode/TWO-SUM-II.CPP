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

    int i = 0, j = n - 1, sum;
    while(i < j){
        sum = a[i] + a[j];
        if(sum == k) return cout<<i + 1<<" "<<j + 1;
        else if(sum < k) i++;
        else j--;
    }

    return 0;
}