class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> res;
        for(string s : strs) {
            vector<int> count(26);
            for(char c: s) {
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++) {
                key += ","+to_string(count[i]);
            }
            anagrams[key].push_back(s);
        }
        for(auto pr : anagrams) {
            res.push_back(pr.second);
        }
        return res;
    }
};
