#include<vector>
// #include<string>
#include<iostream>

using namespace std;

// bool isSafe(vector<string> board,int n,int row,int col, vector<int> &leftRowHash,vector<int> &upperDiagonalHash,vector<int> &lowerDiagonalHash){

//     int r=row,c=col;
//     //left row && //left upper diagonal && //left lower diagonal
//     if(!leftRowHash[r] && !lowerDiagonalHash[r+c] && !upperDiagonalHash[n-1+c-r])
//         return true;
//     return false;
// }

void solve(vector<string> &board,int n,int col,vector<int> &leftRowHash,vector<int> &upperDiagonalHash,vector<int> &lowerDiagonalHash,vector<vector<string>> &ans)
{
    if(col==n){
        ans.push_back(board);
        return;
    }
    int r,c;
    for(int row=0;row<n;row++){
        r = row,c = col;
        // isSafe function call is replaced by single if condition!
        if(!leftRowHash[r] && !lowerDiagonalHash[r+c] && !upperDiagonalHash[n-1+c-r]){
            board[row][col] = 'Q' ;
            leftRowHash[r] = 1;
            lowerDiagonalHash[r+c] = 1;
            upperDiagonalHash[n-1+c-r] = 1;
            solve(board,n,col+1,leftRowHash,upperDiagonalHash,lowerDiagonalHash,ans);
            leftRowHash[r] = 0;
            lowerDiagonalHash[r+c] = 0;
            upperDiagonalHash[n-1+c-r] = 0;
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board (n,string (n,'.') );

    vector<int> leftRowHash (n,0);
    vector<int> upperDiagonalHash ((2*n-1),0);
    vector<int> lowerDiagonalHash ((2*n-1),0);

    solve(board,n,0,leftRowHash,upperDiagonalHash,lowerDiagonalHash,ans);
    return ans;
}

int main( int argc, char* argv[] ){
    //int n = atoi(argv[1]);
    int n;
    cout<<"Enter the board size (n) : ";
    cin>>n;

    vector<vector<string>> ans = solveNQueens(n);

    for(auto b: ans){
        cout<<"-=-=-=---==--=-=-=--=-=-=-=-=-=--=-=\n";
        for(auto r:b){
            for(auto c:r){
                cout<<c<<" ";
            }
            cout<<"\n";
        }
        cout<<"-=-=-=---==--=-=-=--=-=-=-=-=-=--=-=\n";

    }

    cout<<"No of Solutions = "<<ans.size()<<"\n";
}
