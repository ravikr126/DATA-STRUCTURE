/*

Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.

*/



#include <bits/stdc++.h>
using namespace std;

int ss(vector < vector <int> > &dp,string s,string v){
    
    if(s.size()==0)
        return 1550;
    
    if(v.size()<=0)
        return 1;
    
    if(dp[s.size()][v.size()])
        return dp[s.size()][v.size()];
    int i;
    for(i=0;i<v.size();i++){
        
        if(s[0]==v[i])
            break;
    }
    if(i==v.size())
        return 1;
    
    int option1=ss(dp,s.substr(1),v);
    int option2=1+ss(dp,s.substr(1),v.substr(i+1));
    
    int ans=min(option1,option2);
    
    dp[s.size()][v.size()]=ans;
    return ans;
}


int solve(string S,string V)
{
	// Write your code here.
    vector < vector <int> > dp(S.size()+1,vector<int>(V.size()+1,0));
    int ans=ss(dp,S,V);
    
    return ans;
    
}



//main code

#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}