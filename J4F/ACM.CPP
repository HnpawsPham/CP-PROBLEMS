#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main(){
    cin>>n;
    int sum = 0;
    int v[2 * n];
    
    for(int i = 0; i < n * 2; i++) {
        int a, b;
        cin>>a>>b;
        sum += a;
        v[i] = b - a;
    }
    sort(v, v + 2 * n);
    
    for(int i = 0; i < n; i++) sum += v[i];
    cout<<sum;
    return 0;
}