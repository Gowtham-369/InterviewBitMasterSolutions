int Solution::trailingZeroes(int A) {
    int cnt = 0;
    while(A>0){
        cnt += A/5;
        A /= 5;
    }
    //no of 2s are greter than no of 5s
    return cnt;
}
