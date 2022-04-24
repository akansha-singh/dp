class Solution{
public:
    vector<vector<int>>result;
    bool isSafe(vector<vector<int>>board,int row,int col){
        int i, j;
        int N = board.size();
        /* Check this row on left side */
        for (i = 0; i < col; i++)
            if (board[row][i])
                return false;

        /* Check upper diagonal on left side */
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        /* Check lower diagonal on left side */
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;
        return true;
    }

    bool solveNQUtil(vector<vector<int>>&board,int col){
        int N = board.size();
        //base case starts
        if (col == N){
        vector<int> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    v.push_back(j + 1); // bcoz we are pushing column numbers
            }
        }
        result.push_back(v);
        return true;
        }
        //base case ends
        //Consider this column and try placing this queen in all rows one by one
        bool res=false;
        for (int i = 0; i < N; i++){
            if (isSafe(board, i, col)){
                board[i][col]=1;
                res = solveNQUtil(board, col + 1)||res;
                board[i][col] = 0; // BACKTRACK
            }
        }
        return res;
    }
    
    vector<vector<int>>nQueen(int n){
        vector<vector<int>>board(n,vector<int>(n, 0));
        if (solveNQUtil(board, 0) == false){
            return {};
        }
        sort(result.begin(), result.end());
        return result;
    }
};

