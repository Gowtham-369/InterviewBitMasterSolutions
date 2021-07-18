int Solution::maxSubArray(const vector<int> &A)
{
    //Kadanes
    //max sum of contigiuos subarray
    int ans = INT_MIN;
    int sum = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            //break the segment
            sum = 0;
        }
    }
    return ans;
}
