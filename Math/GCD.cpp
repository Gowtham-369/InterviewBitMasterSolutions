int solve_gcd(int A,int B){
    if(A == 0){
        return B;
    }
    return solve_gcd(B%A,A);
}
int Solution::gcd(int A, int B) {
    return solve_gcd(A,B);
}
