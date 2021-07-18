string Solution::convert(string A, int B) {
    
    if(B == 1){
        return A;
    }
    int n = A.size();
    string ans = "";
    vector<bool> v(n,false);
    int i=1;
    while(i<=n && v[i-1]==false){
        int row = i;
        int cur_ind = i;
        ans += A[cur_ind-1];
        v[cur_ind-1] = true;
        while(cur_ind <= n){
            int jump_down_to = 2*(B-row);
            if(jump_down_to != 0){
                cur_ind += jump_down_to;
                if(cur_ind > n){
                    break;
                }
                else{
                    ans += A[cur_ind-1];
                    v[cur_ind-1] = true;
                }
            }
            int jump_up_to = 2*(row-1);
            if(jump_up_to != 0){
                cur_ind += jump_up_to;
                if(cur_ind > n){
                    break;
                }
                else{
                    ans += A[cur_ind-1];
                    v[cur_ind-1] = true;
                }
            }
        }
        i += 1;
    }
    return ans;
}
