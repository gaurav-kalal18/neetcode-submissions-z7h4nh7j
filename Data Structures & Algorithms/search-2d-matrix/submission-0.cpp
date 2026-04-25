class Solution {
public:
    // another method is o(m)+logn iterate all rows and whenever target is
    //  in range do binary search over that matrix[i]
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // row
        int n = matrix[0].size(); // cls
        int low = 0, high = (n * m) - 1;
        while (low <= high) {
            int mid = (low) + (high - low) / 2;
            int row = mid / n;
            int cls = mid % n;
            if (matrix[row][cls] == target)
                return true;

            else if (matrix[row][cls] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};