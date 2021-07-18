int Solution::reverse(int A) {
    //int range is (-2**31) to (2**(31)-1))
    bool neg = false;
    if(A < 0){
        neg = true;
        A = abs(A);
    }
    //we must not convert it to int and process by N%10,N/=10
    //as -INT_MAX can't fit in int
    string s = to_string(A);
    int n = s.size();
    // for(int i=0; i<n/2; i++){
    //     char temp = s[i];
    //     s[i] = s[n-i-1];
    //     s[n-i-1] = temp;
    // }
    std::reverse(s.begin(),s.end());
    int i=0,ans = 0;
    while(i<n){
        int x = s[i]-'0';
        if(neg){
            if(ans>INT_MAX/10+1){
                return 0;
            }
        }
        else{
            if(ans > INT_MAX/10){
                return 0;
            }
        }
        ans *= 10;
        // cout<<"ans "<<ans<<"\n";
        if(neg){
            if(ans-1 > INT_MAX-x){
                return 0;
            }
        }
        else{
            if(ans>INT_MAX-x){
                return 0;
            }
        }
        ans += x;
        // cout<<"ans "<<ans<<"\n";
        i += 1;
    }
    if(neg){
        return -ans;
    }
    else{
        return ans;
    }
}
//4294967296
//-4294967297
//-582764641 1