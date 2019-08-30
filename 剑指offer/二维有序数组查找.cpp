class Solution {
public:
    bool Find(int target, const vector<vector<int>>& array) {
        if (array.size() == 0)return false;
        else if (array[0].size() == 0)return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            if (array[i][j] == target)return true;
            else if (array[i][j] > target)j--;
            else
                i++;
        }
        
        return false;
    }
};