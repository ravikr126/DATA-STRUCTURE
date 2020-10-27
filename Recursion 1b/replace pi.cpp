/***********************************************************

Replace pi (recursive)
Send Feedback
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p

***********************************************************/

// A recursive C++ program to replace 
// all pi in a given string with 3.14 
#include <bits/stdc++.h> 
using namespace std; 

// Recursive Function to replace all 
// occurrences of pi in a given 
// with 3.14 
void replacePiHelper(char input[], int start) 
{ 

	// Base condition 
	// if the string is empty 
	// or of length one 
	if (input[start] == '\0' || input[start] == '\0') { 
		return; 
	} 

	// Getting the answer from 
	// recursion for the smaller 
	// problem 
	replacePiHelper(input, start + 1); 

	// Small calculation part 
	// if the first character is 'p' 
	// and the first character of the part 
	// passed to recursion is 'i' then replace 
	// "pi" with "3.14" 
	if (input[start] == 'p' && input[start + 1] == 'i') { 

		// Shifting the characeters to 
		// right side to put 3.14 in 
		// the character array 
		for (int i = strlen(input); i >= start + 2; i--) { 
			input[i + 2] = input[i]; 
		} 

		// Replacing with "3.14" 
		input[start] = '3'; 
		input[start + 1] = '.'; 
		input[start + 2] = '1'; 
		input[start + 3] = '4'; 
	} 
} 

// Function to replace pi with 3.14 
void replacePi(char str[]) 
{ 
	replacePiHelper(str, 0); 
} 


//main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
