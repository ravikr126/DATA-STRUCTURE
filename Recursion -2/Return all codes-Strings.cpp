/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :

A numeric string

Constraints :
1 <= Length of String S <= 10
Sample Input:

1123

Sample Output:

aabc
kbc
alc
aaw
kw
*/
/**************************************/
//new code by recursion


 if(input[0]=='\0')
   {
       output[0]="";
       return 1;
   }
int first=input[0]-48;
char firstchar=first+'a'-1;
char secondchar='\0';
string smalloutput1[500];
string smalloutput2[500];
int size1=getCodes(input.substr(1),smalloutput1);
int size2=0;
if(input[1] !='\0'){
int second=first*10+input[1]-48;
if(second>=10 && second<=26)
{
secondchar=second+'a'-1;
size2=getCodes(input.substr(2),smalloutput2);
}
}
int k=0;
for(int i=0;i<size1;i++){
output[k]=firstchar+smalloutput1[i];
k++;
}
for(int i=0;i<size2;i++){
output[k]=secondchar+smalloutput2[i];
k++;
}
return k;
}

/*******************************************************/
//by vector
#include <bits/stdc++.h>
using namespace std;

void help(string input,string out,vector<string> &str){
    if(input.size()==0){
        str.push_back(out);
        return;
    }
    char c1=(input[0]-48)+96;
    
    //Ignore the output coming from zero in a string
    if(input[0]=='0')
        return;
    
    help(input.substr(1),out+c1,str);
    
    if(input.size()>1){
        int d=(input[0]-48)*10+(input[1]-48);
        if(d>26)
            return;
        char c2=96+d;
        help(input.substr(2),out+c2,str);
    }
    
}


int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    vector<string> str;
    string out="";
    help(input,out,str);
    
    for(int i=0;i<str.size();i++)
        output[i]=str[i];
    
    int x=str.size();
    
    return x;

    
}

//
#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
