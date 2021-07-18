struct trie
{
    int isLeaf;
    pair<trie*,int> child[26];
};

trie *getNode()
{
    trie *node = new trie();
    for(int i=0; i<26; i++){
        node->child[i].first = NULL;
        node->child[i].second = 0;
    }
    node->isLeaf = 0;
    
    return node;
}

void insert(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx].first){
            curr->child[idx].first = getNode();
        }
        curr->child[idx].second += 1;
        curr = curr->child[idx].first;
    }
    curr->isLeaf = 1; 
}

string search(trie *A, string s)
{
    trie *curr = A;
    string ans = "";
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx].first){
            return ans;
        }
        if(curr->child[idx].second>1){
            ans += s[i];
        }
        else{
            //<=1
            ans += s[i];
            return ans;
        }
        
        curr = curr->child[idx].first;
    }
    return ans;
}
vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> res;
    trie *root = getNode();
    
    for(int i=0; i<n; i++){
        insert(root,A[i]);
    }
    
    for(int i=0; i<n; i++){
        string s = search(root,A[i]);
        res.push_back(s);
    }
    return res;
}
