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

    int cnt = 0;
    for(int x : a){
        if(x % 2) cnt++;
        else cnt = 0;

        if(cnt == 3) return cout<<"true", 0;
    }
    cout<<"false";
    return 0;
}