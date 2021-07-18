struct trie
{
    int isLeaf;
    trie *child[26];
};

trie *getNode()
{
    trie *node = new trie();
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    node->isLeaf = 0;
    
    return node;
}

void insert(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        
        curr = curr->child[idx];
    }
    curr->isLeaf = 1; 
}

int search(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            return 0;
        
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}

void convert(string &str)
{
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)	 
    {
	if(str[i] == '_')	
	     str[i] = ' ';
    }
    return;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first) 
        return a.second < b.second;
    
    return a.first > b.first;	
}

vector<int> Solution::solve(string A, vector<string> &B)
{
    vector<int > v;
    vector<pair<int, int>> v1;

    trie *root = getNode();
    
    convert(A);
    
    string word;

    stringstream ss;

    ss<<A;

    while(ss>>word)	
        insert(root, word);
	
    int cnt;
    for(int i=0; i<B.size(); i++)
    {
	convert(B[i]);
	ss.clear();

	ss<<B[i];

	cnt = 0;
	while(ss>>word)	
	{
	    if(search(root, word))	
		cnt++;
	}
	v1.push_back({cnt, i});
    }
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(int i=0; i<B.size(); i++)
        v.push_back(v1[i].second);
    
    return v;
    
}

/*
class Trie{
    public:
        int isLeaf;
        vector<Trie*> child;
        // Trie(){
        //     this->isLeaf = 0;
        //      //this->child.resize(26);
        //     for(int i=0; i<26; i++){
        //         this->child[i] = NULL;
        //     }
        // }
};

//No need if construtor is there
Trie *GetNode()
{
    Trie *node = new Trie();
    node->child.resize(26);
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    node->isLeaf = 0;
    
    return node;
}

//we can pass with or withour reference,bcoz we are alreading changing addresses
void Insert(Trie *root,string s){
    Trie *curr = root;
    int n = s.size();
    for(int i=0; i<n; i++){
        int idx = s[i]-'a';
        if(curr->child[idx] != NULL){
            // node->child[idx] = new Trie();
            curr->child[idx] = GetNode();
        }
        curr = curr->child[idx];
    }
    curr->isLeaf = 1;//a word ends at here
}
int Search(Trie *root,string s){
    Trie *curr = root;
    int n = s.size();
    for(int i=0; i<n; i++){
        int idx = s[i]-'a';
        if(curr->child[idx] == NULL){
            return 0;
        }
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}


void Convert(string &A){
    int n = A.size();
    for(int i=0; i<n; i++){
        if(A[i] == '_'){
            A[i] = ' ';
        }
    }
    return;
}
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    
    if(a.first == b.first){
        return (a.second<b.second);
    }
    return (a.first>b.first);
}

vector<int> Solution::solve(string A, vector<string> &B) {
    Trie *root = GetNode();
    Convert(A);//to use for stringstream
    stringstream ss;
    ss<<A;
    string word;
    while(ss>>word){
        try
        {
            Insert(root,word);
        }
        catch (const runtime_error& error)
        {
            // your error handling code here
            cout<<"Runtime Error is called in Insert\n";
        }
        
    }
    //Trie is created on A
    int m = B.size();
    vector<pair<int,int>> v1;
    vector<int> ans;
    for(int i=0; i<m; i++){
        //find good words in each review 
        Convert(B[i]);
        ss.clear();
        ss<<B[i];
        int cnt = 0;
        while(ss>>word){
            try
            {
                if(Search(root,word)){
                    cnt += 1;
                }
            }
            catch (const runtime_error& error)
            {
                // your error handling code here
                cout<<"Runtime Error is called in Search\n";
            }
            
        }
        // v1[i] = make_pair(cnt,i);
        v1.push_back({cnt,i});
    }
    sort(v1.begin(),v1.end(),cmp);
    for(auto p:v1){
        ans.push_back(p.second);
    }
    return ans;
}
*/