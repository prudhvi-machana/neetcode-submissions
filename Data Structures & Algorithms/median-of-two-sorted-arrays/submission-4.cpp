class Solution {
public:
    int findval(vector<int>&A, int a, vector<int>& B, int b, int k){
        if(a>= A.size()){
            return B[b+k-1];
        }
        if(b>=B.size()){
            return A[a+k-1];
        }

        if(k==1){
            return min(A[a], B[b]);
        }

        int h = k/2;
        int ia = min((int)A.size()-1, a+h-1);
        int ib = min((int)B.size()-1, b+h-1);

        if(A[ia] >= B[ib]){
            return findval(A, a, B, ib+1, k-(ib-b+1));
        }else{
            return findval(A, ia+1, B, b, k-(ia-a+1));
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int m = nums1.size();
        int n = nums2.size();
        
        if((m+n)%2!=0) return findval(nums1,0,nums2,0, (m+n)/2 + 1);

        int l = findval(nums1,0,nums2,0, (m+n)/2);
        int r = findval(nums1,0,nums2,0, (m+n)/2 + 1);

        return (l+r)/2.0;
    }
};
