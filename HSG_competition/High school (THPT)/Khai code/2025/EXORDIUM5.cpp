#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll d, m, y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>d>>m>>y;
    bool valid = (d > 0) & (m > 0) & (y > 0);
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        valid &= (d <= 31);
    }
    else if(m == 2){
        if(((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) valid &= (d <= 29);
        else valid &= (d <= 28);
    }
    else valid &= (d <= 30);
    valid &= (m < 13);
    cout<<(valid ? "Hop le" : "Khong hop le");
    return 0;
}