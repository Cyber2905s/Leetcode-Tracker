class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
       int n = nums.size();
        
        // Two large prime moduli and bases for collision-free double hashing
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 1315423911ULL % MOD1;
        const uint64_t BASE2 = 2654435761ULL % MOD2;
        
        // Precompute powers of BASE1 and BASE2
        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
        }
        
        // Helper: returns true if there exists at least one unique subarray of length L
        auto hasUnique = [&](int L) -> bool {
            int count = n - L + 1;
            vector<uint64_t> hashes;
            hashes.reserve(count);
            
            uint64_t h1 = 0, h2 = 0;
            // Compute hash of first window [0 .. L-1]
            for (int i = 0; i < L; i++) {
                h1 = (h1 * BASE1 + nums[i]) % MOD1;
                h2 = (h2 * BASE2 + nums[i]) % MOD2;
            }
            hashes.push_back((h1 << 32) | h2);
            
            // Slide window across the rest of the array
            for (int i = L; i < n; i++) {
                uint64_t out1 = (nums[i - L] * pow1[L - 1]) % MOD1;
                uint64_t out2 = (nums[i - L] * pow2[L - 1]) % MOD2;
                
                h1 = ((h1 + MOD1 - out1) * BASE1 + nums[i]) % MOD1;
                h2 = ((h2 + MOD2 - out2) * BASE2 + nums[i]) % MOD2;
                
                hashes.push_back((h1 << 32) | h2);
            }
            
            // Sort hashes to check if any element appears strictly once
            sort(hashes.begin(), hashes.end());
            for (int i = 0; i < count; i++) {
                bool same_prev = (i > 0 && hashes[i] == hashes[i - 1]);
                bool same_next = (i + 1 < count && hashes[i] == hashes[i + 1]);
                if (!same_prev && !same_next) {
                    return true;
                }
            }
            return false;
        };
        
        // Binary search for the minimum valid length in [1, n]
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    } 
};
