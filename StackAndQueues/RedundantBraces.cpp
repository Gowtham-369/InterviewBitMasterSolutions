int Solution::braces(string A) {
    stack<char> st;
    int i=0,n=A.size();
    while(i<n){
        char cur = A[i];
        if(cur == ')'){
            int cnt = 0;
            while(!st.empty() and st.top() != '('){
                st.pop();
                cnt += 1;
            }
            if(!st.empty()){
                st.pop();//remove '('
            }
            if(cnt > 1){
                //no problems
                i += 1;
                continue;
            }
            else{
                return 1;
            }
        }
        st.push(cur);
        i += 1;
    }
    return 0;
}