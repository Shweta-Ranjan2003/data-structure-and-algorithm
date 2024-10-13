#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maximumTotalDamage(std::vector<int>& power) {
        // Frequency count of each damage value
        std::unordered_map<int, int> damage_freq;
        for (int dmg : power) {
            damage_freq[dmg]++;
        }
        
        std::vector<int> unique_damage;
        for (const auto& pair : damage_freq) {
            unique_damage.push_back(pair.first);
        }
        
        std::sort(unique_damage.begin(), unique_damage.end());

        if (unique_damage.size() == 1) {
            return unique_damage[0] * damage_freq[unique_damage[0]];
        }

        int n = unique_damage.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int current_damage = unique_damage[i - 1] * damage_freq[unique_damage[i - 1]];
            int take = current_damage;

            for (int j = i - 2; j >= 0; --j) {
                if (unique_damage[i - 1] - unique_damage[j] > 2) {
                    take += dp[j + 1];
                    break;
                }
            }
            int dont_take = dp[i - 1];
            dp[i] = std::max(take, dont_take);
        }

        return dp[n];
    }
};

// Example usage
int main() {
    Solution sol;
    std::vector<int> power1 = {1, 1, 3, 4};
    std::vector<int> power2 = {7, 1, 6, 6};
    std::vector<int> power3 = {5, 9, 2, 10, 2, 7, 10, 9, 3, 8};

    std::cout << sol.maximumTotalDamage(power1) << std::endl;  // Output: 6
    std::cout << sol.maximumTotalDamage(power2) << std::endl;  // Output: 13
    std::cout << sol.maximumTotalDamage(power3) << std::endl;  // Output: 31

    return 0;
}
