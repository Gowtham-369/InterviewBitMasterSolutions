int search(vector<int>& depart,int target,int n){
    int l= 0,r=n-1;
    int ans = 0;
    int mid;
    while(l<=r){
        mid = r+(l-r)/2;
        if(depart[mid]<=target){
            ans = mid+1;//till mid,we can have
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int n = arrive.size();
    for(int i=0; i<n; i++){
        int rooms_wanted = (i+1);
        int cnt = search(depart,arrive[i],n);
        rooms_wanted -= cnt;
        if(rooms_wanted > K){
            return false;
        }
    }
    return true;
}
