/*
int Solution::solve(vector<int> &A, int B) {
    //contigiously place 0s and move the window of zeros
    // vector<int> v(A.begin(),A.end());
    vector<int> zeros;
    int n = A.size();
    int i=0;
    int ans = 0;
    if(B == 0){
        i = 0;
        int cnt = 0;
        while(i<n){
            cnt = 0;
            while(i<n && A[i]==1){
                cnt += 1;
                i += 1;
            }
            ans = max(ans,cnt);
            i += 1;//dont forget this step
        }
        return ans;
    }
    //above is special case
    
    int start = -1,end = -1;
    i = 0;
    while(i<n){
        if(A[i] == 0){
            zeros.push_back(i);
        }
        i += 1;
    }
    int m = zeros.size();
    start = 0;
    if(B > m){
        end = m-1;
    }
    else
        end = B-1;
    // cout<<"start "<<start<<"end "<<end<<"\n";
    //placed as many zeros as possible
    //next move one by and get max ans
    bool flag = true;
    while(end<m){
        // cout<<"start "<<start<<"end "<<end<<"\n";
        for(int j=start; flag == true && j<=end ;j++){
            A[zeros[j]] = 1;
        }
        i = 0;
        int cnt = 0;
        while(i<n){
            cnt = 0;
            while(i<n && A[i]==1){
                cnt += 1;
                i += 1;
            }
            ans = max(ans,cnt);
            i += 1;//dont forget this step
        }
        //moving window
        A[zeros[start]] = 0;
        start += 1;
        end += 1;
        
        if(end<m){
            A[zeros[end]] = 1;
        }
        flag = true;
        
    }
    return ans;
}
*/
int Solution::solve(vector<int> &A, int B)
{
    int cnt = 0;
    int i = 0, l = 0;
    int ans = 0;
    while (i < n)
    {
        if (A[i] == 0)
        {
            cnt += 1;
        }
        while (cnt > B)
        {
            if (A[l] == 0)
            {
                cnt -= 1;
            }
            l += 1;
        }
        ans = max(ans, i - l + 1);
    }
}
