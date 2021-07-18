vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    int word_size = B[0].size();
    int B_size = B.size();
    int t_len = word_size * B_size;
    int n = A.size();
    vector<int> res;
    map<string, int> mp;
    for (auto str : B)
    {
        mp[str] += 1;
    }
    for (int i = 0; i + t_len <= n; i++)
    {
        int j = i;
        map<string, int> temp = mp;
        while (j < i + t_len)
        {

            string to_find = A.substr(j, word_size);
            if (temp[to_find] <= 0)
            {
                break;
            }
            else
            {
                temp[to_find] -= 1;
            }
            j += word_size;
        }
        if (j == i + t_len)
        {
            res.push_back(j - t_len);
        }
        /*
        while(j<i+t_len){
            
            string to_find = A.substr(j,word_size);
            auto it = temp.find(to_find);
            if(it == temp.end()){
                break;
            }
            else{
                temp[to_find] -= 1;
            }
            j += word_size;
        }
        bool flag = true;
        for(auto it=temp.begin();it!=temp.end();it++)
            if(it->second>0)
                flag=false;
 
        if(flag)
            res.push_back(i);
        */
    }
    return res;
}
