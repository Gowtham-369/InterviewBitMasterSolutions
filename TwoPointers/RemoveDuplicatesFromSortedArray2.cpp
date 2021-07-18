int Solution::removeDuplicates(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0, j = 0;
    int n = A.size();
    while (j < n)
    {
        int cnt = 1;
        while (j < n - 1 && A[j] == A[j + 1])
        {
            cnt += 1;
            j += 1;
        }
        A[i] = A[j];
        i += 1;
        if (cnt >= 2 && i < n)
        {
            A[i] = A[j];
            i += 1;
        }
        j += 1;
    }
    A.resize(i);
    return i;
}
