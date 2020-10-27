/***********************************************************

Pair star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

**********************************************************/

#include<cstring>
using namespace std;

void pairStar(char input[]) {
		// Recursive CPP program to insert * between 
// Recursive CPP program to insert * between 
// two consecutive same characters. 
    if(input[0] =='\0')
    {
        return;
    }
    int len=strlen(input);
 
 
        if(input[0]==input[1])
        {
            for(int i=len;i>=1;i--)
            {
            input[i+1]=input[i];
            }
            input[1]='*';
        }
      pairStar(input+1);
      
}

//main func
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
