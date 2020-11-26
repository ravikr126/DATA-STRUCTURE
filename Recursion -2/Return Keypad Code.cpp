/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf

*/

//  1st approach 
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    string value[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    if(num == 0) {
        output[0] = "";
        return 1;
    }
    
    
    int smallNum = keypad(num/10, output);
    int c = value[num % 10].size();
    
    string a[smallNum];
    
    for(int i = 0;i < smallNum;i++) {
        a[i] = output[i];
    }
    int k = 0;
    for(int j = 0;j < c;j++){
        for(int i = 0;i < smallNum;i++) {
               output[k] = a[i] + value[num%10][j];
               k++;
        }
    }
    
    return c*smallNum;
}


//2nd approach using recursion

#include <string>
using namespace std;
string func(int n)
{
  string array[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};  
    return array[n];
}
  int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    // let take the exapmle of 23
    int my_num=num%10;//3 for recursion
    int ans=keypad(num/10,output);//ans will be 3 as string is "abc"
    string op=func(my_num);//we assume that our faith has obtained "def"
    for(int i=op.size()-1;i>=0;i--){
        for(int j=0;j<ans;j++){
            output[i*ans + j]=output[j]+op[i];
            //output[2*3 + 0] = output[0]+op[2] == 'a'+'f' = af
        }
    }
    return ans*op.size();
    // return 3*3;
}


//  3rd approach  map approach
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

string pad(int key){
    unordered_map<int,string> dial;
    dial[0]="";
    dial[1]="";
    dial[2]="abc";
    dial[3]="def";
    dial[4]="ghi";
    dial[5]="jkl";
    dial[6]="mno";
    dial[7]="pqrs";
    dial[8]="tuv";
    dial[9]="wxyz";
    
    return dial[key];
}


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    int smallOutSize=keypad(num/10,output);
    
    string pd=pad(num%10);
    int newsize=pd.size()*smallOutSize;
    //Copy
    string temp[10000];
    for(int i=0;i<10000;i++)
        temp[i]=output[i];
    
    for(int i=0;i<pd.size();i++){
        
        for (int j=0;j<smallOutSize;j++){
            output[j+i*smallOutSize]=temp[j]+pd[i];
        }
    }
    return newsize;
}
#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
