#include <iostream>
using namespace std;
using ll = long long;
#define el endl

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l = 1, r = 2e9, mid;
    string res;
    while(l <= r){
        mid = (l + r) / 2;

        cout<<mid<<el;
        cin>>res;

        if(res == "HOLA") return 0;

        if(res == "SMALLER")
            r = mid - 1;
        else if(res == "BIGGER") 
            l = mid + 1;
    }
    return 0;
}