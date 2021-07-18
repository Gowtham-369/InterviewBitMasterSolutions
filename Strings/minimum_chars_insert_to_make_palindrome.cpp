bool ispalin(string s)
{
    for(int i=0,j=s.length()-1;i<=j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}
/*
int Solution::solve(string s)
{
    int cnt = 0;
    while(s.length()>0)
    {
        if(ispalin(s))
            break;
        else
        {
            cnt++;
            s.erase(s.end()-1);
        }
    }
    return cnt;
}
*/
/*
int Solution::solve(string s){
    int n = s.size();
    int low = 0,high = n-1;
    int ans = 0;
    while(low < high){
        if(s[low] == s[high]){
            low += 1;
            high -= 1;
        }
        else{
            if(low == 0){
                ans += 1;
                high -= 1;
            }
            else{
                ans += low;
                low = 0;
            }
        }
    }
    return ans;
}
//ABBABA
*/
int Solution::solve(string s){
    string B(s.begin(),s.end());
    string res = B;
    res+='$';
    reverse(B.begin(),B.end());
    res.append(B);
    int m = res.size(),n = s.size();
    vector<int> lps(m);
    lps[0] = 0;
    int i=1;
    int len = 0;
    while(i<m){
        if(res[len] == res[i]){
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i += 1;
                //len = 0;
            }
        }
    }
    //lps[m-1] gives the longest palindrome from starting point
    return n-lps[m-1];
}

