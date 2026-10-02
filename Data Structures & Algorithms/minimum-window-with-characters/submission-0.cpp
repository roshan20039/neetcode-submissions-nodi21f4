class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m==0) return "";
        int i = 0, minlength = INT_MAX, match = 0, startindex = 0;
        unordered_map<char, int> tmap;
        for(char c : t) tmap[c]++;
        for(int j = 0; j < n; j++) {
            char c = s[j];
            if(tmap[c] > 0) {
                match++;
            }
            tmap[c]--;
            while(match == m) {
                if(j-i+1 < minlength) {
                    minlength = j-i+1;
                    startindex = i;
                }
                if(tmap[s[i]] == 0) {
                    match--;
                }
                tmap[s[i]]++;
                i++;
            }
        }
        return minlength != INT_MAX ? s.substr(startindex, minlength) : "";

    }
};
