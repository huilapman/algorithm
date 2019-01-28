#include <iostream>
#include <stack>
using namespace std;

int max_binary_gap(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n%2);
        n = n/2;
    }
    
    int max = 0;
    int count = 0;
    while (!s.empty()) {
        //cout << s.top();
        int curr = s.top();
        s.pop();
        
        if (curr == 0) {
            ++count;
        }
        else {
            if (count > 0 && count > max) {
                max = count;
            }
            count = 0;
        }
    }
    //cout << endl;
    return max;
}

int main() {    
    cout << "max binary gap " << max_binary_gap(9) << endl;
    cout << "max binary gap " << max_binary_gap(529) << endl;
    cout << "max binary gap " << max_binary_gap(20) << endl;
    cout << "max binary gap " << max_binary_gap(15) << endl;
    cout << "max binary gap " << max_binary_gap(1041) << endl;
    return 0;
}
