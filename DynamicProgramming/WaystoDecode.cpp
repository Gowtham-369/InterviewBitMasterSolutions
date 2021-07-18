vector<int> t;
int mod = 1e9+7;
int countDecoding(string digits, int n)
{
    int count[n+1];
    count[0] = 1;
    count[1] = 1;
    //for base condition "01123" should return 0
    if(digits[0]=='0') 
         return 0;
    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;
 
        // If the last digit is not 0,
        // then last digit must add to the number of words
        if (digits[i-1] > '0')
            count[i] += count[i-1];
 
        // If second last digit is smaller
        // than 2 and last digit is smaller than 7,
        // then last two digits form a valid character
        if (digits[i-2] == '1' ||
              (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] = (count[i]+count[i-2])%mod;
    }
    return count[n]%mod;
}
 

int countWays(string digits, int n)
{
    return countDecoding(digits, n);
}

long long solve(int i,int n,string &s){
    
    if(i>=n-1){
        return 1;    
    }
    long long int ans = 0;
    if(s[i]=='0'){
        return 0;
    }
    if(t[i+1] == -1){
        t[i+1] = solve(i+1,n,s);
    }
    ans = (ans+t[i+1])%mod;
    if(s[i]-'0' == 1){
        if(i+1<n && s[i+1]-'0'>=0 && s[i+1]-'0'<=9){
            if(t[i+2] == -1){
                t[i+2] = solve(i+2,n,s);
            }
            ans = (ans+t[i+2])%mod;
        }
    }
    if(s[i]-'0'== 2){
        if(i+1<n && s[i+1]-'0'>=0 && s[i+1]-'0'<=6){
            if(t[i+2] == -1){
                t[i+2] = solve(i+2,n,s);
            }
            ans = (ans+t[i+2])%mod;
        }
    }
    return ans;
    
}
int Solution::numDecodings(string A) {
    int n = A.size();
    t.erase(t.begin(),t.end());
    t.resize(n+1,-1);
    int ans = solve(0,n,A)%mod;
    // int ans = countWays(A,n)%mod;
    return ans;
}
