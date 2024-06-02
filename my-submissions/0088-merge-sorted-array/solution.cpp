class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1; 
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};


/*
other so;ution taking i ,j and k as 0 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n); // Temporary array to store merged results
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int k = 0; // Pointer for temp array

        // Merge nums1 and nums2 into temp array
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }

        // Copy remaining elements of nums1, if any
        while (i < m) {
            temp[k++] = nums1[i++];
        }

        // Copy remaining elements of nums2, if any
        while (j < n) {
            temp[k++] = nums2[j++];
        }

        // Copy the merged elements back to nums1
        for (int l = 0; l < m + n; ++l) {
            nums1[l] = temp[l];
        }
    }
};
*/



