#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //counting no. of set bits

    int n = 13;
    int cnt = 0;
    while(n!=0) {
        if(n&1==1) cnt++;
        n = n >> 1;
    }
    cout << cnt << endl;

    //method 2

    int cnt2 = 0;
    while(n!=0) {
        n = n&(n-1);
        cnt2++;
    }
    
    cout << cnt2;

//other problems I did: removing last set bit (rightmost); clearing the ith bit; checking if the ith bit is set;
//toggling a bit; setting the ith bit; (only this problem is here because it doesn't have one liner as a sol)

    return 0;
}