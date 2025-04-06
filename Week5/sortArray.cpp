class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    	int n = nums.size(), j = 0;
        vector<int> res(n), count(100001);
        for (int num : nums) ++count[num + 50000];
        for (int i = 0; i < count.size(); ++i) {
        	while (count[i]-- > 0) {
        		res[j++] = i - 50000;
        	}
        }
        return res;
    }
};
