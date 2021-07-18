int Solution::cntBits(vector<int> &A)
{
    int n = A.size();
    long long ans = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i < 32; i++)
    {
        int n_zeros = 0, n_ones = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (A[j] >> i & 1 == 1)
            {
                ans = (ans + n_zeros % mod) % mod;
                n_ones += 1;
            }
            else
            {
                ans = (ans + n_ones % mod) % mod;
                n_zeros += 1;
            }
        }
    }
    ans = ans * 2 % mod;
    return ans;
}
