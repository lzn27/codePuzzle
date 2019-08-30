class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return INT_MIN;
        int l=0,r=rotateArray.size()-1;
        int mid=(l+r)/2;
        if(l==r)
                return rotateArray[l];
        while(l<=r){
            if(rotateArray[l]<rotateArray[r])
                return rotateArray[l];
            else{
                mid=(l+r)/2;
                if(rotateArray[mid]<rotateArray[mid-1])
                    return rotateArray[mid];
                else{
                    if(rotateArray[mid]>=rotateArray[l])
                        l=mid+1;
                    else
                        r=mid-1;
                }
            }
        }
        return INT_MIN;
    }
};