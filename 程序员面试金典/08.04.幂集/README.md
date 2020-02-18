幂集。编写一种方法，返回某集合的所有子集。输入集合不包含重复元素，即不需要去重。
示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-set-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
//较好的递归方案。
class Solution {//注意：无需考虑集合的顺序问题，新元素直接加到后面即可
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        addsubset_begin_with_be(nums,ans,0);
        return ans;
    }

    void addsubset_begin_with_be(const vector<int>& nums,vector<vector<int>>& ans,int be){
        if(be==nums.size()-1){
            ans.push_back(vector<int>());
            ans.push_back(vector<int>{nums.back()});
            return;
        }
        addsubset_begin_with_be(nums,ans,be+1);
        int size=ans.size();
        for(int i=0;i<size;i++){
            vector<int> v(ans[i]);
            v.push_back(nums[be]);
            ans.push_back(v);
        }
    }
};
```

```c++
//利用n位长度的二进制映射的1的情况包含了所有的子集，所有使用nums.size()长度的二进制数，
//该数的大小最大是2^(nums.size())
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(unsigned int i=0;i<pow(2,nums.size());i++){//该方法使用i代表长度位nums.size()的数字，所以当nums长度超过32时，该方法不适用。
            unsigned int index=0,j=1;
            vector<int> v;
            for(;index<nums.size();index++){
                if((i&j)!=0){//位运算优先级比等号小，要加括号
                    v.push_back(nums[index]);
                }
                j<<=1;
            }
            ans.push_back(v);
        }
        return ans;
    }
};

```