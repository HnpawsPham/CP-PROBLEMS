#include <iostream>
using namespace std;
#define MOD 14062008

int n;

int main(){
    cin>>n;
    int a[n * 2], b[n * 2];
    int sum = 0;
    for(int i = 0; i < n * 2; i++) {
        cin>>a[i]>>b[i];
        sum += a[i];
    }

 
    return 0;
}