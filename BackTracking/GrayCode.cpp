vector<int> Solution::grayCode(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int n = A;
    if (n == 0)
    {
        return ans;
    }
    ans = {0, 1};
    if (n == 1)
    {
        return ans;
    }
    for (int i = 2; i <= n; i++)
    {
        int m = ans.size();
        m *= 2;
        ans.resize(m);
        // int bit_value = pow(2,i-1);
        int bit_value = (1 << (i - 1));
        for (int j = 0; j < m / 2; j++)
        {
            ans[m - j - 1] = bit_value + ans[j];
        }
    }
    return ans;
}
