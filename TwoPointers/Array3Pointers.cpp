vector<int> search(const vector<int> &A,int target){
    int n = A.size();
    vector<int> v(2);
    int ind = upper_bound(A.begin(),A.end(),target)-A.begin();
    ind -= 1;
    if(ind < 0){
        //only upper bound
        v[0] = INT_MIN;
        v[1] = A[ind+1];
    }
    else if(ind==n-1){
        v[0] = A[ind];
        v[1] = INT_MAX;
    }
    else{
        if(A[ind] == target){
            v[0] = v[1] = target;
        }
        else{
            v[0] = A[ind];
            v[1] = A[ind+1];
        }
    }
    return v;
}
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    /*
    int b_size = B.size();
    long long ans = INT64_MAX;
    for(int i=0; i<b_size; i++){
        int target = B[i];
        //check in A
        vector<int> a = search(A,target);
        
        //check in C
        vector<int> c = search(C,target);
        //get maxx_diff
        long long diff1 = max(abs(B[i]-a[1]),abs(B[i]-c[1]));//towards right
        long long diff2 = max(abs(B[i]-a[0]),abs(B[i]-c[0]));//towards left
        long long diff3 = abs(a[0]-c[1]);
        long long diff4 = abs(a[1]-c[0]);
        
        ans = min(ans,min(min(diff1,diff2),min(diff3,diff4)));
        //minimise that
    }
    return (int)ans;
    */
    int ans = INT_MAX;
    int a_size = A.size(),b_size = B.size(),c_size = C.size();
    for(int i=0,j=0,k=0; i<a_size&&j<b_size&&k<c_size;){
        int minn = min(A[i],min(B[j],C[k]));
        int maxx = max(A[i],max(B[j],C[k]));
        int diff = maxx-minn;
        if(diff == 0){
            ans = diff;
            return ans;
        }
        if(ans > diff){
            ans = diff;
        }
        if(A[i] == minn){
            i += 1;
        }
        else if(B[j] == minn){
            j += 1;
        }
        else{
            k += 1;
        }
    }
    return ans;
}
