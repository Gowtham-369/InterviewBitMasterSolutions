vector<int> Solution::prevSmaller(vector<int> &A)
{

    stack<int> st;
    int n = A.size(), i = n - 1;
    vector<int> res(n);
    while (i >= 0)
    {
        while (!st.empty() && A[i] < A[st.top()])
        {
            res[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
        i -= 1;
    }
    while (!st.empty())
    {
        res[st.top()] = -1;
        st.pop();
    }
    return res;
}
