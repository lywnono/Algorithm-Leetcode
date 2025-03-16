class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n = people.size(), left = 0, right = n - 1;
        sort(people.begin(), people.end());
        while (left <= right) {
            if (people[left] + people[right] <= limit) ++left;
            --right;
            ++res;
        }
        return res;
    }
};