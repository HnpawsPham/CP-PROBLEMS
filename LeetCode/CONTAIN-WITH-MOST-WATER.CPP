#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0, i = 0, j = n - 1;
    while(i < j){
        res = max(res, min(a[i], a[j]) * (j - i));

        if(a[i] == a[j]){
            i++;
            j--;
        }
        else if(a[i] < a[j]) i++;
        else j--;
    }    
    cout<<res;
    return 0;
}