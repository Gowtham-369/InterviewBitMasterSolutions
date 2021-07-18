int Solution::solve(string A) {
    stack<char> st;
    int i=0,n=A.size();
    while(i<n){
        
        char cur = A[i];
        if(st.empty()){
            if(cur == ')')
                return 0;
            else{
                st.push(cur);
            }
        }
        else{
            if(cur == ')'){
                if(st.top() == '('){
                    st.pop();
                }
            }
            else{
                st.push(cur);
            }
            
        }
        i += 1;
    }
    return (st.empty()?1:0);
}
