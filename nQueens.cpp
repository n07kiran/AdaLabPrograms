#include<vector>
// #include<string>
#include<iostream>

using namespace std;

bool isSafe(vector<string> board,int n,int row,int col){

    //left row
    int r=row,c=col;
    while(c>=0){
        if(board[r][c] == 'Q' ) return false;
        c--;
    }

    //left upper diagonal
    r=row,c=col;
    while(r>=0 && c>=0){
        if(board[r][c] == 'Q' ) return false;
        r--;c--;
    }

    //left lower diagonal
    r=row,c=col;
    while(r<n && c>=0){
        if(board[r][c] == 'Q' ) return false;
        r++;c--;
    }

    return true;
}

void solve(vector<string> &board,int n,int col,vector<vector<string>> &ans)
{
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,n,row,col)){
            board[row][col] = 'Q' ;
            solve(board,n,col+1,ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board (n,string (n,'.') );
    solve(board,n,0,ans);

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
