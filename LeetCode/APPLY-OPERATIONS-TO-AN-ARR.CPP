#include <iostream>
using namespace std;
#define el "\n"

int n, cnt0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cnt0 = n;

    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    for(int i = 0; i < n - 1; i++)
        if(a[i] == a[i + 1]){
            a[i] *= 2;
            a[i + 1] = 0;
        }

    for(int i = 0; i < n; i++)
        if(a[i] != 0){
            cout<<a[i]<<" ";
            cnt0--;
        }
    while(cnt0--) cout<<0<<" ";

    return 0;
}