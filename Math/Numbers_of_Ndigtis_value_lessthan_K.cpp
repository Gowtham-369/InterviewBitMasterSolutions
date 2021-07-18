/*
int ans;
void solve_this(vector<int> &A, int B, int C,int res){
    if(to_string(res).size() == B){
        if(res<C)
            ans += 1;
        
        return;
    }
    int n = A.size();
    for(int i=0; i<n; i++){
        res *= 10;
        res += A[i];
        solve_this(A,B,C,res);
    }
}

int search(vector<int>& A,int target,int n){
    int l = 0,r= n-1;
    int ind = -1;
    int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(A[mid] < target){
            ind = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    if(ind == -1){
        return 0;//all are greater than target
    }
    else{
        return ind+1;//nos less than target
    }
}

int Solution::solve(vector<int> &A, int B, int C) {
    ans = 0;
    // int res = 0;
    // solve_this(A,B,C,res);
    int n = A.size();
    if(n == 0){
        return 0;
    }
    string s = to_string(C);
    int c_size = s.size();
    if(B>c_size){
        return 0;//no ans
    }
    else if(B<c_size){
        //all combinations of size B are possilbe
        // (pow(n,B)-leading zero cases)
        if(A[0] == 0 && B>1){
            ans = (n-1)*pow(n,B-1);
        }
        else{
            ans = pow(n,B);
        }
        return ans;
    }
    else{
        
        for(int i=0; i<c_size; i++){
            int how_many = search(A,s[i]-'0',n);
            if(i == 0 && A[0] == 0 && B > 1){
                how_many -= 1;//leading zero case
            }
            if(how_many == 0){
                //we can't have permutations further
                break;
            }
            
            ans  = ans+(how_many*pow(n,c_size-i-1));
            // cout<<"i "<<i<<"ans "<<ans<<"\n";
        }
        return ans;    
    }
   
}
*/
//Given solution
vector <int> numToVec(int N) {   
    vector<int> digit;
    while(N != 0) {
        digit.push_back(N % 10);
        N = N / 10;
    }
    if(digit.size() == 0)
        digit.push_back(0);

    reverse(digit.begin(), digit.end());
    return digit; 
}

int Solution:: solve(vector<int> &A, int B, int C) {
    vector<int> digit;
    int  d, d2;
    // Convert number to digit array
    digit = numToVec(C);
    d = A.size();

    //Case 1
    if(B > digit.size()  || d == 0)
        return 0;

    // Case 2
    else if(B < digit.size()) {
        // contain 0
        if(A[0] == 0 && B != 1)
            return (d - 1) * pow(d, B - 1);
        else 
            return pow(d, B);
    }

    //Case 3
    else {
          int dp[B + 1], lower[11];
          for(int i = 0; i <= B; i++)
              dp[i] = 0;
          for(int i = 0; i <= 10; i++)
              lower[i] = 0;
          for(int i = 0; i < d; i++)
              lower[A[i] + 1] = 1;

          for(int i = 1; i <= 10; i++)
              lower[i] = lower[i-1] + lower[i]; 

          bool flag = true;
          dp[0] = 0;
          for(int i = 1; i <= B; i++) {
              d2 = lower[digit[i-1]];
              dp[i] = dp[i-1] * d;

              // For first index we can't use 0
             if(i == 1 &&  A[0] == 0 && B != 1)
                 d2 = d2 - 1;

             //Whether (i-1) digit of generated number can be equal to (i - 1) digit of C.
             if(flag)
                 dp[i] += d2;
             //Is digit[i - 1] present in A ?
                flag = flag & (lower[digit[i-1] + 1] == lower[digit[i-1]] + 1);
        }
    return dp[B];                   
    } 
}
