int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int m = A[i] ^ A[j];

            if (m > ans)
            {
                break; //upcoming nos will surely give greater XOR
            }
            else
            {
                ans = m;
            }
        }
    }
    return ans;
}
