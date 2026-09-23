class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int i=0,j=0;
        int m = nums1.size();
        int n = nums2.size();
        int m1 = 0, m2 = 0;

        for(int cnt = 0; cnt <(m+n)/2 + 1; cnt++){
            m2 = m1;
            if(i<m && j<n){
                if(nums1[i] > nums2[j]){
                    m1 = nums2[j];
                    j++;
                }else{
                    m1 = nums1[i];
                    i++;
                }
            }else if(i<m){
                m1 = nums1[i];
                i++;
            }else{
                m1 = nums2[j];
                j++;
            }
        }

        if((m+n)%2 == 1){
            return (double)m1;
        }else{
            return (double)(m1+m2)/2;
        }
    }
};
