//Problem: Exit Point in a Matrix
//Topic: Matrix
//Pattern: Medium

class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (true) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }

            int ni = i, nj = j;

            if (dir == 0) nj++;
            else if (dir == 1) ni++;
            else if (dir == 2) nj--;
            else ni--;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                return {i, j};
            }

            i = ni;
            j = nj;
        }
        
    }
};
