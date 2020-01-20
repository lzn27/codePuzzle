# 215. 数组中的第K个最大元素

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {//调用parttition算法，每次只需要处理一半的元素，时间复杂度为O(N);
        int l=0,r=nums.size()-1;
        while(l<=r){
            int pos=partition(nums,l,r);
            if(pos==k-1)return nums[pos];
            else if(pos<k-1){
                l=pos+1;
            }
            else{
                r=pos-1;
            }
        }
        return 0;
    }

    int partition(vector<int>& nums,int l,int r){//parttition算法
        int key=nums[r];
        int store=l;
        for(int i=l;i<=r;i++){
            if(nums[i]>key){
                swap(nums[store++],nums[i]);
            }
        }
        swap(nums[store],nums[r]);
        return store;
    }
};
```


