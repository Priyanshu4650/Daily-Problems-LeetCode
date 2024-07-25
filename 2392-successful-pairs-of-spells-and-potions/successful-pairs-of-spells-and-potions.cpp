class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int> result;
        for(int i = 0; i < spells.size(); i++) {
            long long min_potion = (success + spells[i] - 1) / spells[i];  // Calculate the minimum potion needed for the spell to be successful
            int index = lower_bound(potions.begin(), potions.end(), min_potion) - potions.begin();
            result.push_back(potions.size() - index);
        }

        return result;
    }
};
