
class Solution {
    vector<string> validColumns;
    vector<vector<int>> memo;
    const int MOD = 1'000'000'007;

    // Generate all valid column colorings of height 'rows'
    void buildValidColumns(string current, int rowsLeft, char previousColor, int rows) {
        if (rowsLeft == 0) {
            validColumns.push_back(current);
            return;
        }

        for (char color : {'R', 'G', 'B'}) {
            if (color == previousColor) continue;
            buildValidColumns(current + color, rowsLeft - 1, color, rows);
        }
    }

    int countWays(int colsLeft, int prevColIndex, int rows) {
        if (colsLeft == 0) return 1;
        if (memo[colsLeft][prevColIndex] != -1) return memo[colsLeft][prevColIndex];

        int ways = 0;
        const string& prevCol = validColumns[prevColIndex];

        for (int nextColIndex = 0; nextColIndex < validColumns.size(); ++nextColIndex) {
            const string& nextCol = validColumns[nextColIndex];
            bool isCompatible = true;

            for (int r = 0; r < rows; ++r) {
                if (prevCol[r] == nextCol[r]) {
                    isCompatible = false;
                    break;
                }
            }

            if (isCompatible) {
                ways = (ways + countWays(colsLeft - 1, nextColIndex, rows)) % MOD;
            }
        }

        return memo[colsLeft][prevColIndex] = ways;
    }

public:
    int colorTheGrid(int rows, int cols) {
        validColumns.clear();
        buildValidColumns("", rows, '#', rows);

        int totalPatterns = validColumns.size();
        memo.assign(cols, vector<int>(totalPatterns, -1));

        int totalWays = 0;
        for (int i = 0; i < totalPatterns; ++i) {
            totalWays = (totalWays + countWays(cols - 1, i, rows)) % MOD;
        }

        return totalWays;
    }
};
