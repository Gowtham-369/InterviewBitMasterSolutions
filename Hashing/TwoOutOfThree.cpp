vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int,int> mp1,mp2,mp3;
    for(auto x:A){
        mp1[x] += 1;
    }
    for(auto x:B){
        mp2[x] += 1;
    }
    for(auto x:C){
        mp3[x] += 1;
    }
    // multiset<int> ans;//for multiple occurences
    set<int> ans;
    for(auto x:A){
        if(mp1[x]>0 and mp2[x]>0 and mp3[x]>0){
            ans.insert(x);
            mp1[x] -= 1;mp2[x]-=1;mp3[x]-=1;
        }
        else if(mp1[x]>0 and mp2[x]>0){
            ans.insert(x);
            mp1[x] -= 1;
            mp2[x] -= 1;
        }
        else if(mp2[x]>0 and mp3[x]>0){
            ans.insert(x);
            mp2[x] -= 1;
            mp3[x] -= 1;
        }
        else if(mp3[x]>0 and mp1[x]>0){
            ans.insert(x);
            mp3[x] -= 1;
            mp1[x] -= 1;
        }
        /*
        auto it1 = mp1.find(x);
        map<int,int>::iterator it2 = mp2.find(x);
        auto it = mp3.find(x);
        if(it1 != mp1.end() and it2 != mp2.end() and it3 != mp3.end()){
            it1->second -= 1;
            it2->second -= 1;
            it3->second -= 1;
        }
        */
    }
    for(auto x:B){
        if(mp1[x]>0 and mp2[x]>0 and mp3[x]>0){
            ans.insert(x);
            mp1[x] -= 1;mp2[x]-=1;mp3[x]-=1;
        }
        else if(mp1[x]>0 and mp2[x]>0){
            ans.insert(x);
            mp1[x] -= 1;
            mp2[x] -= 1;
        }
        else if(mp2[x]>0 and mp3[x]>0){
            ans.insert(x);
            mp2[x] -= 1;
            mp3[x] -= 1;
        }
        else if(mp3[x]>0 and mp1[x]>0){
            ans.insert(x);
            mp3[x] -= 1;
            mp1[x] -= 1;
        }
    }
    return vector<int>(ans.begin(),ans.end());
}
