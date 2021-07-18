int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cnt = 0;
    /*
    while(A>0){
        if(A&1 == 1){
            cnt += 1;
        }
        A = A>>1;
    }
    return cnt;
    */
    for(int i=0;i<32;i++){
        if((A&(1<<i))!=0){
           // cout<<(1<<i)<<endl;
            cnt++;
        }
    }
    
    return cnt;
}
