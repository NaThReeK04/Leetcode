class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int i,int j,vector<vector<char>>&board,string word,int index){
        if(index==word.size())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[index])return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool found=dfs(i+1,j,board,word,index+1)||
                   dfs(i-1,j,board,word,index+1)||
                   dfs(i,j-1,board,word,index+1)||
                   dfs(i,j+1,board,word,index+1);
        board[i][j]=temp;
        return found;           
    }
};