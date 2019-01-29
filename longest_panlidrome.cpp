/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string longest_panlidrome(string& s) {
    int n = s.length();
    for (int i=0; i<s.length(); ++i) {
        cout << s[i] << " ";
    }
    bool table[n][n] = {false};
    // memset(table, 0, sizeof(table));
    
    for (int i=0; i<n; ++i) {
        table[i][i] = true;
    }

    int start = 0;
    int max = 1;
    for (int i=0; i<n-1; ++i) {
        if (s[i] == s[i+1]) {
            table[i][i+1] = true;
            start = i;
            max = 2;
        }
    }
  
    for (int k=3; k<=n; ++k) {
        for (int i=0; i<n-k+1; ++i) {
            // Get the ending index of substring from 
            // starting index i and length k 
            int j = i + k - 1; 
            
            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            if (table[i+1][j-1] && s[i] == s[j]) {
                table[i][j] = true; 
                if (k > max) { 
                    start = i; 
                    max = k; 
                } 
            }
        }
    }
    
    cout << endl;
    return s.substr(start, max);
}

int main() {
    string s = "12345678909876ASDFH";
    cout << "longest panlidrome " << longest_panlidrome(s);
    return 0;
}
