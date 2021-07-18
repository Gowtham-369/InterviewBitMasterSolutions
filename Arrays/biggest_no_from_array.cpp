bool mycompare(string& x,string& y){
    
    string XY = x;
    XY += y;
    string YX = y;
    YX += x;
    int n = XY.size();
    for(int i=0; i<n; i++){
        if(XY[i]>YX[i]){
            //x>y
            return true;
        }
        if(XY[i]<YX[i]){
            return false;
        }
    }
    return true;
    // return (XY.compare(YX)>0?true:false);
}
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> v(n);
    for(int i=0; i<n; i++){
        v[i] = to_string(A[i]);
    }
    sort(v.begin(),v.end(),mycompare);
    string res = "";
    for(int i=0 ;i<n; i++){
        // cout<<v[i]<<"\n";
        res += v[i];
    }
    reverse(res.begin(),res.end());
    while((int)res.size()>1 && res.back() == '0'){
        res.pop_back();
    }
    reverse(res.begin(),res.end());
    return res;
}
