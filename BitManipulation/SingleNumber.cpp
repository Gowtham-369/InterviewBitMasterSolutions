int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;//0^n = n
    for(int e:A){
        ans = (ans^e);
    }
    
    return ans;
}