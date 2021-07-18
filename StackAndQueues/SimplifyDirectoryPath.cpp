string Solution::simplifyPath(string A) {
    int n = A.size();
    // stack<string> st;
    // vector<string> st;
    deque<string> dq;
    string temp = "";
    for(int i=0; i<n; i++){
        temp = "";
        while(i<n && A[i] == '/'){
            //multiple // are same as /
            //  /home//foo/ = /home/foo
            i += 1;
        }
        while(i<n && A[i] != '/'){
            temp += A[i++];
        }
        if(temp == ".."){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
        else if(temp == "."){
            continue;
        }
        else{
            if(temp != ""){
                dq.push_back(temp);
            }
        }
        
    }
    string res = "/";//root directory
    deque<string>::iterator it = dq.begin();
    while(it != dq.end()){
        res += (*it+"/");
        it++;
    }
    if(res.length() > 1)
        res.pop_back();
    return res;
}
