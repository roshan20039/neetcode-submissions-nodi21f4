class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if(n!=m) return false;
        vector<int> sfreq(126);
        //sfreq r->2, a->2, c->2, e->1 
        for(char c : s) {
            sfreq[c]++;
        }
        for(char c : t) {
            sfreq[c]--;
        }
        for(int freq : sfreq) {
            if(freq != 0) return false;
        }
        return true;
    }
};
