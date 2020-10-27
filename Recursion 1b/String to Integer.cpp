
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
