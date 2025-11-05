#include <iostream>
using namespace std;
#define el "\n"

int t, a, x, y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a>>x>>y;

        bool ok = 0;

        for(int i = 1; i <= 100; i++)
            if(i != a)
                if(abs(x - i) < abs(i - a) && abs(y - i) < abs(i - a)){
                    ok = 1;
                    break;
                }
        cout<<(ok ? "YES" : "NO")<<el;
    }

    return 0;
}