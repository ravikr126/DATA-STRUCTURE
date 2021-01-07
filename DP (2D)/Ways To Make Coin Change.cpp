/*

Ways To Make Coin Change
Send Feedback
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903

*/


int count(int denom[],int **dp,int m,int n)
{
    
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(m==0)
    {
        return 0;
    }
    if(dp[n][m-1]!=-1)
    {
        return dp[n][m-1];
    }
    int a=count(denom+1,dp,m-1,n);
    int b=count(denom,dp,m,n-denom[0]);
    int ans=a+b;
    dp[n][m-1]=ans;
    return ans; 
}
int countWaysToMakeChange(int denom[], int m, int n){
  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1;
        }
    }
    //int i=0;
    //int j=0;
    int ans=count(denom,dp,m,n);
    for(int i=0;i<=n;i++)
    {
        delete dp[i];
    }
    delete []dp;
    return ans;
}
/*#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector <int> > &dp,int c[],int n,int v){
    if(v<0)
        return 0;
    if(v==0)
        return 1;
    if(n==0)
        return 0;
    
    if(dp[n][v])
        return dp[n][v];
    
    //Either include nth coin or don't include
    int ans=helper(dp,c,n,v-c[n-1])+helper(dp,c,n-1,v);
    dp[n][v]=ans;
    return ans;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
/*    vector <vector <int> > dp(numDenominations+1,vector<int>(value+1,0));
    int ans=helper(dp,denominations,numDenominations,value);
    
    return ans;

}*/

//main code

#include <iostream>
using namespace std;

#include "solution.h"

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}