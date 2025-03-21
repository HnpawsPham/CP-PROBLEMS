#include <iostream>
using namespace std;
#define el "\n"

int n, cntp = 0, cntn = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        int x; cin>>x;
        cntp += (x > 0);
        cntn += (x < 0);
    }
    cout<<max(cntp, cntn);

    return 0;
}