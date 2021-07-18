string Solution::solve(string s) {
    stringstream ss;
    ss<<s;
    string word = "",ans="";
    while(ss>>word){
        ans = " "+word+ans;
    }
    return ans.substr(1);
    /*
    int n = s.size();
    int i=0;
    string word = "";
    vector<string> v;
    while(i<n){
        while(i<n && s[i] != ' '){
            word += s[i];
            i += 1;
        }
        if(i<n){
            if((int)word.size() > 0){
                v.push_back(word);
            }
            word = "";
            i += 1;
        }
    }
    if((int)word.size() > 0){
        v.push_back(word);
    }
    string ans = "";
    for(auto it=v.rbegin(); it!=v.rend() ;it++){
        ans += (*it);
        ans += ' ';
    }
    ans.pop_back();
    return ans;
    */
}
