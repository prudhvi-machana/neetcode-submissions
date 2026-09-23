class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int i=0,j=0;
        int m = nums1.size();
        int n = nums2.size();

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                tmp.push_back(nums1[i]);
                i++;
            }else{
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            tmp.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            tmp.push_back(nums2[j]);
            j++;
        }

        for(int i=0;i<(m+n);i++){
            cout<<tmp[i]<<" ";
        }
        if((m+n)%2 != 0){
            return tmp[(m+n)/2];
        }else{
            return (double)(tmp[(m+n)/2] + tmp[(m+n-1)/2])/2;
        }
    }
};
