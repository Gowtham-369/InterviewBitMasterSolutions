int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    map<int,int> mp;
    int n = A.size();
    int m = n/3;
    for(auto x:A){
        mp[x] += 1;
        if(mp[x]>m){
            return x;
        }
    }
    return -1;
    */
    int n = A.size();
    /*
    
    // fails at 3 3 3 3 4 5 6 6 5 3 2 1
    set<int> s;
    int i = 0;
    while(i<5){
        if(s.count(A[i]) == 1){
            i += 1;//move to next num as this is not the num
            continue;
        }
        int j = i+1;
        while(j<=i+4 && j<n && i<n){
            if(A[j] == A[i]){
                i = j;
                j += 1;
            }
            else{
                j += 1;
            }
        }
        if(j >= n){
            // return 1;//there is such element
            return A[i];//last found at ith index
        }
        else{
            s.insert(A[i]);
            i += 1;
        }
    }
    return -1;
    */
    if(n>0 && n<=2){
        return A[0];
    }
    int m = n/3;
    
    int ele1 = A[0],ele2;
    int i = 1;int cnt1 = 1,cnt2;
    while(i<n && A[i] == A[i-1]){
        cnt1 += 1;
        i++;
    }
    if(i == n){
        return A[i-1];
    }
    else{
        ele2 = A[i];
        cnt2 = 1;
        i += 1;
    }
    for(; i<n; i++){
        if(A[i] == ele1){
            cnt1 += 1;
        }
        else if(A[i] == ele2){
            cnt2 += 1;
        }
        else{
            
            if(cnt1 == 0){
                cnt1 = 1;
                ele1 = A[i];
            }
            else if(cnt2 == 0){
                cnt2 = 1;
                ele2 = A[i];
            }
            else{
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
    }
    cnt1 = 0,cnt2 = 0;
    for(i=0; i<n; i++){
        if(A[i] == ele1){
            cnt1 += 1;
        }
        if(A[i] == ele2){
            cnt2 += 1;
        }
    }
    if(cnt1>m){
        return ele1;
    }
    else if(cnt2 >m){
        return ele2;
    }
    else{
        return -1;
    }
}
