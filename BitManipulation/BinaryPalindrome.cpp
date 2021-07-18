bool check(int num)
{
    string s = "";
    int m = num;
    while (m > 0)
    {
        s += char('0' + m % 2);
        m = m / 2;
    }
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i += 1;
            j -= 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int get_value(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        ans = ans * 2;
        if (s[i] == '1')
        {
            ans += 1;
        }
    }
    return ans;
}
int Solution::solve(int A)
{
    //as we dont consider leading zereos
    //all even are ruled out
    //Approach 1
    /*
    int cnt = 0;
    int num = 1;
    while(cnt<A){
        if(check(num)){
            cnt += 1;
        }
        if(cnt>=A){
            break;
        }
        num += 2;
    }
    return num;
    
    */
    if (A == 1)
    {
        return A;
    }
    if (A == 2)
    {
        return 3;
    }
    queue<string> q;
    q.push("11");
    int ans;
    A--;
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        A--;
        if (A == 0)
        {
            ans = get_value(s);
            break;
        }
        int len = s.size();
        if ((len & 1) != 0)
        {
            //odd
            int mid = len / 2;
            string ch = s.substr(mid, 1);
            string s1 = s;
            s1.insert(mid, ch);
            q.push(s1);
        }
        else
        {
            //even
            int mid = len / 2;
            string s1 = s, s2 = s;
            s1.insert(mid, "0");
            s2.insert(mid, "1");
            q.push(s1);//push this first
            q.push(s2);
        }
    }
    return ans;
}
