class Solution {
public:
    bool isalnum(char c) {
        if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j) {
            while(i < j and !isalnum(s[i])) i++;
            while(j > i and !isalnum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
