/* 
time complexity O(N^2)
SPACE complexity O(N)
WHERE N  IS SIZE OF ARRAY
*/


int pairsum(int *arr,int startindex,int endindex, int num)
{
    int numpair= 0;
    while(startindex<endindex)
    {
            if(arr[startindex]+arr[endindex]<num)
            startindex++;
            else if(arr[startindex]+arr[endindex] > num)
            endindex--;
            else
                {
                    int elementatstart=arr[startindex];
                    int elementatend=arr[endindex];
                    
                }
    }
}