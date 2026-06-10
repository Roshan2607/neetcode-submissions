class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    zeroRows[r] = true;
                    zeroCols[c] = true;
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (zeroRows[r] || zeroCols[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
