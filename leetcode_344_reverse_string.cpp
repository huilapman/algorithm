class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for (int i=0; i<s.size()/2; ++i) {
            // tmp = s[i];
            // s[i] = s[s.size()-1-i];
            // s[s.size()-1-i] = tmp;
            
            tmp = std::move(s[i]);
            s[i] = std::move(s[s.size()-1-i]);
            s[s.size()-1-i] = std::move(tmp);
        }
    }
};
