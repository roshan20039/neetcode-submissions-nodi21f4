class Solution {
public:
    
    string encode(vector<string>& strs) {
        string res = "";
        for (auto str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.length()) {
            int j = i;
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j-i));
            string substr = s.substr(j+1, length);
            res.push_back(substr);
            i = j+1+length;
        }
        return res;
    }
};
