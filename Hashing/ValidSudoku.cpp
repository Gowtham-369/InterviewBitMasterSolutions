bool valid(int start_row,int start_col,const vector<string> &A){
    map<char,int> mp;
    for(int i=start_row; i<start_row+3; i++){
        for(int j=start_col; j<start_col+3; j++){
            if(A[i][j] != '.'){
                mp[A[i][j]] += 1;
            }
        }
    }
    for(auto it:mp){
        if(it.second>1){
            return false;
        }
    }
    return true;
}
int Solution::isValidSudoku(const vector<string> &A) {
    int n = 9;
    //every row
    for(int i=0; i<n; i++){
        map<char,int> mp;
        for(int j=0; j<n; j++){
            if(A[i][j] != '.')
                mp[A[i][j]] += 1;
        }
        for(auto it:mp){
            if(it.second>1){
                return 0;
            }
        }
    }
    //every col
    for(int j=0; j<n; j++){
        map<char,int> mp;
        for(int i=0; i<n; i++){
            if(A[i][j] != '.')
                mp[A[i][j]] += 1;
        }
        for(auto it:mp){
            if(it.second>1){
                return 0;
            }
        }
    }
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            if(!valid(i,j,A)){
                return 0;
            }
        }
    }
    return 1;
}
