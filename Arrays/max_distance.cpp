
// *******************************************************************//
// another classic example sorting and using vector is better than hash_mapping
// safe from memory limit exceeded
int Solution::maximumGap(const vector<int> &A)
{

    int n = A.size();
    if (n == 1)
    {
        return 0;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(A[i], i));
    }
    sort(v.begin(), v.end());
    int ans = -1; //decreasing order
    int min_index = v[0].second;
    for (int i = 1; i < n; i++)
    {
        int cur = v[i].second;
        ans = max(ans, cur - min_index);
        min_index = min(min_index, cur);
    }
    return ans;

    /*
    map<int,pair<int,int>> mp;
    //store min and max indices
    for(int i=0; i<n; i++){
        if(mp.find(A[i]) == mp.end()){
            mp[A[i]] = {i,i};
        }
        else{
            mp[A[i]].first = min(mp[A[i]].first,i);
            mp[A[i]].second = max(mp[A[i]].second,i);
        }
    }
    map<int,pair<int,int>>:: iterator it = mp.begin();
    int min_ind = it->second.first,max_ind=it->second.second;
    int ans = -1;//all are in decreasing order
    ans = max(ans,max_ind-min_ind);//dont forget to one element case
    for(++it;it!=mp.end();it++){
        min_ind = min(min_ind,it->second.first);
        int cur_max = it->second.second;
        ans = max(ans,cur_max-min_ind);
    }
    return ans;
    */
}
