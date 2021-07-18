typedef long long ll;
vector<vector<int>> Solution::fourSum(vector<int> &A, int target)
{
    vector<vector<int>> ans;
    int n = A.size();
    if (n < 4)
    {
        return ans;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        if (A[i] + A[i + 1] + A[i + 2] + A[i + 3] > target)
            break;
        if (A[i] + A[n - 3] + A[n - 2] + A[n - 1] < target)
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && A[j] == A[j - 1])
                continue;
            if (A[i] + A[j] + A[j + 1] + A[j + 2] > target)
                break;
            if (A[i] + A[j] + A[n - 2] + A[n - 1] < target)
                continue;

            int l = j + 1, r = n - 1;
            int to_find = target - A[i] - A[j];

            while (l < r)
            {

                int sum = A[l] + A[r] + A[i] + A[j];
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                {
                    ans.push_back(vector<int>{A[i], A[j], A[l], A[r]});
                    l += 1;
                    r -= 1;
                    while (l < r && A[l - 1] == A[l])
                    {
                        l++;
                    }
                    while (l < r && A[r + 1] == A[r])
                    {
                        r--;
                    }
                }
            }
        }
    }
    return ans;
}
/*
vector<vector<int> > Solution::fourSum(vector<int> &A, int target) {
    sort(A.begin(),A.end());
    map<ll,vector<pair<int,int>>> mp;
    set<vector<int>> ans;
    
    int len = A.size();
    for(int i=0; i<len; i++){
        ll sum = A[i];
        for(int j=i+1; j<len; j++){
            sum += A[j];
            mp[sum].push_back({i,j});
            sum -= A[j];
        }
    }
    for(auto it = mp.begin(); it!=mp.end(); it++){
        int to_find = target-it->first;
        auto it2 = mp.find(to_find);
        if(it2 != mp.end()){
            int n = it->second.size(),m=it2->second.size();
           
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    vector<int> v;
                    v.push_back(it->second[i].first);
                    v.push_back(it->second[i].second);
                    v.push_back(it2->second[j].first);
                    v.push_back(it2->second[j].second);
                    sort(v.begin(),v.end());
                    int k=0;
                    vector<int> res;
                    while(k<4){
                        while(k<3 && v[k] == v[k+1]){
                            k += 1;
                        }
                        res.push_back(A[v[k]]);
                        k += 1;
                    }
                    if((int)res.size() == 4){
                        ans.insert(res);
                    }
                }
            }
        }
    }
    vector<vector<int>> final_ans(ans.begin(),ans.end());
    return final_ans;
}
*/
