class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = m;
        while(low<=high){
            int i = low + (high-low)/2;
            int j = (m+n+1)/2 - i;
            int aleft = (i==0) ? INT_MIN : nums1[i-1];
            int aright = (i==m) ? INT_MAX : nums1[i];
            int bleft = (j==0) ? INT_MIN : nums2[j-1];
            int bright = (j==n) ? INT_MAX : nums2[j];

            if(aleft <= bright  && bleft<=aright){
                if((m+n)%2 ==1){
                    return max(aleft, bleft);
                }else{
                    return (max(aleft, bleft) + min(aright, bright))/2.0;
                }
            }
            if(aleft > bright){
                high = i-1;
            }else{
                low = i+1;
            }
        }
        return -1;
    }
};
