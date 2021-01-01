Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/




#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;
int balancedBTs(int h) {
    long *ans = new long[h+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=3;
    ans[3]=15;
    //int mod = (int) pow(10,9)+7;
    for(int i=2;i<=h;i++){
        long x = ans[i-1]%mod;
        long y = ans[i-2]%mod;
        long temp1 =  (x*x)%mod;
        long temp2 =  (2*x*y)%mod;
        ans[i]= ((temp1)+(temp2))%mod;
    }
    return ans[h];
}


//main code

#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
