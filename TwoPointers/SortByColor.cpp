void swap(int &a,int &b){
    int temp = b;
    b = a;
    a = temp;
}
void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //Dutch flag problem
    int n = A.size();
    int l = 0,r = n-1;
    int i = 0;
    
    while(i<=r){
        if(A[i] == 0){
            if(i<=l){
                i += 1;
                continue;
            }
            else{
                swap(A[l],A[i]);
                l += 1;
            }
        }
        else if(A[i] == 2){
            swap(A[r],A[i]);
            r -= 1;
        }
        else{
            i += 1;
        }   
    }
    
}
