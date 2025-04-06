class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queenCol(n, -1);
        dfs(0, queenCol, res);
        return res;
    }
    void dfs(int row, vector<int>& queenCol, vector<vector<string>>& res) {
        int n = queenCol.size();
        if (row == n) {
            vector<string> cur(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                cur[i][queenCol[i]] = 'Q';
            }
            res.push_back(cur);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isValid(queenCol, row, j)) {
                queenCol[row] = j;
                dfs(row + 1, queenCol, res);
                queenCol[row] = -1;
            }
        }
    }
    bool isValid(vector<int>& queenCol, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == queenCol[i] || abs(row - i) == abs(col - queenCol[i])) return false;
        }
        return true;
    }
};
