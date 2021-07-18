#define deb2(x,y) cout<<#x<<" "<<x<<#y<<" "<<y<<"\n"

map<int,char> mp;
bool found;
bool isValid(int row,int col,vector<vector<char>> &A){
    for(int i=0; i<9; i++){
        if(i!=row && A[i][col] == A[row][col]){
            return false;
        }
    }
    for(int j=0; j<9; j++){
        if(j!=col && A[row][j] == A[row][col]){
            return false;
        }
    }
    /*
    row = row/3;
    col = col/3;
    for(int i=row*3; i<(row+1)*3; i++){
        for(int j=col*3 ;j<(col+1)*3; j++){
            if(i!=row && j != col && A[i][j] == A[row][col]){
                return false;
            }
        }
    }
    //giving WA
    */
    
    
    int mrow = (row/3)*3;
    int mcol = (col/3)*3;
 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int newi = mrow + i;
            int newj = mcol + j;
            if(newi!=row && newj!=col && A[newi][newj]==A[row][col])
                return false;
        }
    }
    
    return true;
}

void solve(int row,int col,vector<vector<char>> temp,vector<vector<char> > &A){
    if(found){
        return;
    }
    if(row == 8 && col==8){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                A[i][j] = temp[i][j];
            }
        }
        found = true;
        return;
    }
    for(int i=row; i<9; i++){
        for(int j=col; j<9; j++){
            if(temp[i][j] == '.'){
                for(int k=1; k<=9; k++){
                    temp[i][j] = mp[k];
                    if(isValid(i,j,temp)){
                        deb2(i,j);
                        solve(i,j,temp,A);
                    }
                    temp[i][j] = '.';
                }
            }
        }
    }
}

bool solve2(int row,int col,vector<vector<char>>  &A){
    if(col == 9){
        row += 1;
        col = col%9;
    }
    if(row == 9){
        return true;
    }
    bool flag = false;
    if(A[row][col] != '.'){
        flag = solve2(row,col+1,A);
        if(flag){
            return true;
        }
    }
    else{
        for(int i=1; i<=9; i++){
            A[row][col] = char(i+'0');
            if(isValid(row,col,A)){
                flag = solve2(row,col+1,A);
                if(flag){
                    return true;
                }
            }
            A[row][col] = '.';
            
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char>>  &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    // vector<vector<char>> temp;
    // int n = 9;
    // for(int i=1; i<=n; i++){
    //     mp[i] = char(i+'0');
    // }
    // assert(n == (int)A.size());
    // n = A.size();
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         temp[i][j] = A[i][j];
    //     }
    // }
    // found = false;
    // deb2(n,found);
    // solve(0,0,temp,A);
    */
    solve2(0,0,A);
    
}
