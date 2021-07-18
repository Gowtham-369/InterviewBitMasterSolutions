/*
void solve(string A,vector<string>& res,int cnt,string ans){
    
    int n = A.size();
    
    if(cnt == 4){
        cout<<"ans "<<ans<<"\n";
        if(n == 0){
            //reached end of given string
            ans.pop_back();//remove dot
            res.push_back(ans);
        }
        return;
    }
    if(n == 0){
        return;
    }
    for(int len=1;len<=3 && len<=n; len++){
        
        string s = A.substr(0,len)+'.';
        //remove zeros at front
        if((int)s.size() == 1 && stoi(s)>=0 && stoi(s)<=255){
            solve(A.substr(len,n-len),res,cnt+1,ans+s);
        }
        else{
            if((int)s.size()>1 && s[0] != '0' && stoi(s)>=0 && stoi(s)<=255){
                solve(A.substr(len,n-len),res,cnt+1,ans+s);
            }
        }
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res;
    int cnt = 0;
    string ans = "";
    solve(A,res,cnt,ans);
    return res;
}
*/
bool isValid(string s) {
    if (s.size() > 1 && s[0]  ==  '0')
        return false;
    if (stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}
vector<string> Solution::restoreIpAddresses(string s)  {
    vector<string> ans;
    if (s.size() > 12 || s.size() < 4)
        return ans;
    for(int i=1; i<4; i++){
        string first = s.substr(0,i);
        if(!isValid(first)){
            continue;
        }
        for(int j=1; j<4 && i+j<(int)s.size(); j++){
            string second = s.substr(i,j);
            if(!isValid(second)){
                continue;
            }
            for(int k=1; k<4 && i+j+k<(int)s.size(); k++){
                string third = s.substr(i+j,k);
                string fourth = s.substr(i+j+k);//remaining string
                if(isValid(third) && isValid(fourth))){
                    string res = first+'.'+second+'.'+third+'.'+fourth;
                    ans.push_back(res);
                }
            }
        }
    }

    return ans;
}
