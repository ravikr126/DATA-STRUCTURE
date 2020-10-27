/**********************************************************

Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

****************************************************************/

// Change in the given string itself. So no need to return or print anything
#include<cstring>
#include<algorithm>
using namespace std;
void removeX(char input[]) 
{
        if(input[0]== '\0')
        {
            return;
        }
      removeX(input+1);
    int len = strlen(input);
if(input[0]=='x')
     {
   for(int i=0;i<len;i++)
   {
      input[i]=input[i+1];
    }
    }
  
}

//main code

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
