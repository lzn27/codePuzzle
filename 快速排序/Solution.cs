public class Solution
{
    public void QuickSort(int[] nums)
    {
        Qs(nums, 0, nums.Length - 1);
    }
    private void Qs(int[] nums, int l, int r)
    {
        if(l<r){
            int index = Partition(nums, l, r);
            Qs(nums, l, index-1);
            Qs(nums, index+1, r);
        }
    }

    private int Partition(int[] nums, int l, int r){
        int key = nums[l];
        while(l < r){
            while(l < r && nums[r] >= key) r--;
            nums[l] = nums[r];
            while(l<r && nums[l] <= key) l++;
            nums[r] = nums[l];
        }
        nums[l] = key;
        return l;
    }
}