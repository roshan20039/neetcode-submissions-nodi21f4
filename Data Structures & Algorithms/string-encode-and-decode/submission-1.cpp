class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> res;        
        int i = 0;
        while(i < n) {
            int j = i;
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j - i));
            i = j+1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
