#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 3;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a, a + n);
    if(a[0] + a[1] <= a[2]) return cout<<"none", 0;
    else if(a[0] == a[2]) return cout<<"equilateral", 0;
    else if(a[0] == a[1] || a[1] == a[2]) return cout<<"isosceles", 0;
    
    cout<<"scalene";
    return 0;
}