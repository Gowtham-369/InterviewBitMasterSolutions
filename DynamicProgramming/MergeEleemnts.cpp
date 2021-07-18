int merge(int i, int j, vector<int> &A, vector<vector<int>> &T)
{

    if (T[i][j] != -1) // Already Visited
        return T[i][j];
    if (i == j) // Base case => For 1 element cost = 0.
        T[i][j] = 0;
    else if (i == j - 1) // Base Case => For 2 elements cost = sum of two elements.
        T[i][j] = A[i] + A[j];
    else
    {
        int val = INT_MAX;
        int sum = A[j];
        for (int k = i; k < j; k++)
        {
            sum += A[k];
            val = min(val, merge(i, k, A, T) + merge(k + 1, j, A, T));
        }
        T[i][j] = val + sum;
    }

    return T[i][j];
}

int Solution::solve(vector &A)
{

    int n = A.size();
    vector<vector<int>> T(n, vector<int>(n, -1));

    int soln = merge(0, n - 1, A, T);
    return soln;
}