#include <iostream>
using namespace std;

int s1, s2, s3;

int main(){
    cin>>s1>>s2>>s3;
    int cnt[81] = {};

    for(int i = 1; i <= s1; i++)
        for(int j = 1; j <= s2; j++)
            for(int k = 1; k <= s3; k++)
                cnt[i + j + k]++;
    
    int res, maxx = 0;
    for(int i = 1; i <= 80; i++) 
        if(cnt[i] > maxx){
            maxx = cnt[i];
            res = i;
        }
    cout<<res;
    return 0;
}