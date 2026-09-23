class Solution {
public:
    int findval(vector<int>&A, vector<int>& B, int k){
        int i=0, j=0;
        while(true){
            if(i>= A.size()){
                return B[j+k-1];
            }
            if(j>=B.size()){
                return A[i+k-1];
            }
            if(k==1){
                return min(A[i], B[j]);
            }
            int h = k/2;
            int ia = min((int)A.size()-1, i+h-1);
            int ib = min((int)B.size()-1, j+h-1);

            if(A[ia] >= B[ib]){
                k = k - (ib - j +1);
                j=ib+1;
            }else{
                k = k - (ia-i+1);
                i = ia+1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if((m+n)%2!=0) return findval(nums1, nums2, (m+n)/2 + 1);

        int l = findval(nums1, nums2, (m+n)/2);
        int r = findval(nums1, nums2, (m+n)/2 + 1);

        return (l+r)/2.0;
    }
};
