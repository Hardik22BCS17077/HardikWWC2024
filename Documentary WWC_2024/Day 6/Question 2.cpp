class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            int start = 0;
            int end = row.size() - 1;

            if (target >= row[start] && target <= row[end]) {

                while (start <= end) {
                    int mid =  (end + start) / 2;

                    if (row[mid] == target) {
                        return true;
                    } else if (row[mid] < target) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
