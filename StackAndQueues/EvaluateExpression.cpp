int Solution::evalRPN(vector<string> &A)
{
    deque<string> dq;
    int n = A.size(), i = 0;
    while (i < n)
    {
        string cur = A[i];
        if (cur == "+" || cur == "-" || cur == '*' || cur == '/')
        {
            int back = stoi(dq.back());
            dq.pop_back();
            int back_to_back = stoi(dq.back());
            dq.pop_back();
            if (cur == "+")
            {
                back_to_back += back;
            }
            else if (cur == "-")
            {
                back_to_back -= back;
            }
            else if (cur == '*')
            {
                back_to_back *= back;
            }
            else
            {
                back_to_back /= back;
            }
            dq.push_back(back_to_back);
        }
        else
        {
            dq.push_back(to_string(cur));
        }
        i += 1;
    }
    return *dq.begin();
}
