#include <bits/stdc++.h>
using namespace std;

string a, b;

int main(){
    cin>>a>>b;

    int i = a.length() - 1, j = b.length() - 1;
    string res = "";
    int remember = 0, sum;

    while(i >= 0 || j >= 0 || remember){
        sum = remember;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';

        res += (sum % 2) + '0';
        remember = sum / 2;
    }

    reverse(res.begin(), res.end());
    cout<<res;
    
    return 0;
}