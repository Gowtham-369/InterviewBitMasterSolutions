/*
int Solution::maxProfit(const vector<int> &A)
{
    int n = A.size();
    int res = 0;
 
    int i = 0;
 
    while(i<n-1)
    {
        while(i<n-1 && A[i+1]<=A[i])
            i++;
 
        if(i==n-1)
            break;
 
        int j = i;
 
        while(i<n-1 && A[i+1]>=A[i])
            i++;
 
        res += (A[i] - A[j]);
        i++;
    }
    return res;
}
*/
int Solution::maxProfit(const vector<int> &A)
{
    int n = A.size();
    int res = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (A[i + 1] >= A[i])
        {
            res += (A[i + 1] - A[i]);
        }
    }
    return res;
}
