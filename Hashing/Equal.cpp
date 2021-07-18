#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n" 
int upperbound(vector<pair<int,int>> v,int l,int r,int target){
    // cout<<"Upper bound is called\n";
    int ans = r+1;
    int mid;
    while(l<=r){
        mid = l+(r-l)/2;
        if(v[mid].first<=target){
            ans = mid+1;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    map<int,pair<int,int>> mp;
    vector<int> res;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = A[i]+A[j];
            if(mp.find(sum) == mp.end()){
                mp[sum] = {i,j};
            }
            else{
                int ii = mp[sum].first;
                int jj = mp[sum].second;
                if(ii == i || ii == j || jj == i || jj == j){
                    continue;
                }
                vector<int>temp = {ii,jj,i,j};
                if(res.empty()){
                    res = temp;
                }
                else{
                    for(int k=0; k<4; k++){
                        if(res[k] < temp[k]){
                            break;
                        }
                        else{
                            if(res[k]>temp[k]){
                                res = temp;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
    
    
}
