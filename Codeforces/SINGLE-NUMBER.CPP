#include <iostream>

int n;

int main(){
    std::cin>>n;
    int sum = 0, x;
    
    while(n--){
        std::cin>>x;
        sum ^= x;
    }
    std::cout<<sum;
    return 0;
}