class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
    int right = 0;
    int numRows = mat.size();
    int numCols = mat[0].size();
    int left = numRows;
    int result = 0;
    for (int i = 0; i < numRows; ++i) {
        right += mat[i].back();
        }
    
    
    while (left <= right) {
            int mid = (left + right) / 2;
            if (countSumsLessThanOrEqual(mat, k, 0, mid) < k)
                left = mid + 1;
            else {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }

    int countSumsLessThanOrEqual(vector<vector<int>>& mat, int k, int row, int mid) {
        if (mid < 0)
            return 0;
        if (row == mat.size())
            return 1;
        
        int totalCount = 0;
        for (int col = 0; col < mat[0].size(); col++) {
            int count = countSumsLessThanOrEqual(mat, k, row + 1, mid - mat[row][col]);
            if (count == 0)
                break;
            totalCount += count;
            if (totalCount > k)
                break;
        }
        return totalCount;
    }
};
