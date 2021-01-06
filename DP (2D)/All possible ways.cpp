/*


All possible ways
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 <= b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2

*/

//1st approach

#include <iostream>
using namespace std;

int power(int num, unsigned int n) 
{ 
    if (n == 0) 
        return 1; 
    else if (n%2 == 0) 
        return power(num, n/2)*power(num, n/2); 
    else
        return num*power(num, n/2)*power(num, n/2);
}

int check(int x,int n,int curr_num,int curr_sum){
    int res=0;
    int p = power(curr_num,n);
    while(p+curr_sum<x){
        res += check(x,n,curr_num+1,curr_sum+p);
        curr_num++;
        p=power(curr_num,n);
    }
    if(p+curr_sum==x)
        res++;
    return res;
}

int allWays(int x, int n) {
    return check(x,n,1,0);
}


//2nd approach

#include<cmath>
int apw(int num, int power, int n){
	if(num==0){
		return 1;
	}
	if(num < 0){
		return 0;
	}
	int reducer = pow(n, power);
	if(reducer > num){
		return 0;
	}
	int x = apw(num-reducer, power, n+1);
	int y = apw(num, power, n+1);
	return x+y;
}

int getAllWays(int a, int b) {
	// Write your code here
    return apw(a, b, 1);
}


//main code

#include <iostream>
using namespace std;
#include "solution.h"

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}#include <iostream>
using namespace std;
#include "solution.h"

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}