#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int compress(vector<char>& chars) {
        size_t size = chars.size();
        char prev_char;
        unsigned int count = 0;
        string s;
        
        if (size > 0) {
            prev_char = chars[0];
            count = 1; 
            if (size == 1) {
                s += chars[0];
            }
        }
        
        for (size_t i=1; i<size; ++i) {
            if (prev_char == chars[i]) {
                ++count;                    
            }
            else {
                s += prev_char;
                if (count > 1) {
                    s += to_string(count);                   
                }
                prev_char = chars[i];
                count = 1;
            }

            if (i == size -1) {
                s += chars[i];
                if (count > 1) {
                    s += to_string(count);                   
                }
            }

        }
        
        chars.clear();
        for (int i=0; i < s.length(); ++i) {
            chars.push_back(s[i]);
        }
        cout << s << endl;
        return chars.size();
    }
};
