#include <iostream>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    int p = 3;

    while(n > 0){
        p++;
        if(p < 10) n--;
        else if(p < 100) n-= 2;
        else if(p < 1000) n-=3;
        else n-=4;
    }
    
    printf("%d\n", p);
    return 0;
}