class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i <= n; i++) {
        xor1 ^= i; // XOR of all numbers from 0 to n
    }
    
    for (int num : nums) {
        xor2 ^= num; // XOR of all elements in nums
    }

    return xor1 ^ xor2; //
    }
};