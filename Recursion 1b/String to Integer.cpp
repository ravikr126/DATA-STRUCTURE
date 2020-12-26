
/****************************************************************

String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
1231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567

****************************************************************/
//1st method

int len(char a[])
{
    int res = 0;
    for(int i =0;a[i]!='\0';i++)
        res++;
    return res;
}
int pow(int m,int n)
{
    int res =1;
    int p =1;
    for(int i=1;i<=n;i++)
    {
        res = res*m;
    }
    return res;
}
int stringToNumber(char a[]) {
    int l = len(a);
    if(l==1)
        return a[0]-'0';
    int df = stringToNumber(a+1);
    int c = a[0]-'0';
    return c*pow(10,l-1)+df;
    
}



//2nd method

#include <sstream>
using namespace std; 
int stringToNumber(char input[]) {

	// object from the class stringstream 
	stringstream geek(input); 

	// The object has the value 12345 and stream 
	// it to the integer x 
	int x = 0; 
	geek >> x; 

	// Now the variable x holds the value 12345 
	return x;
}



//main func

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
