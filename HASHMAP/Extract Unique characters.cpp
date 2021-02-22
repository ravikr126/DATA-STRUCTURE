/*

Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde

*/


# include<bits/stdc++.h>
using namespace std;

char* uniqueChar(char *str){
    int len = strlen(str);
    if(len==0){
        char *ans = new char[1];
        ans[1]='/0';
        return ans;
    }
    unordered_map<char,bool> m;
    char *ans = new char[len+1];
    int j=0;
    for(int i=0;i<len;i++){
        if(m.count(str[i])==0){
            m[str[i]]=true;
            ans[j++]=str[i];
        }
    }
    return ans;
}


//main code


#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}