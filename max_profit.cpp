#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int>& p) {
    int max = 0;
    int low = p[0];

    for (int i=1;i<p.size(); ++i) {
        
        if (p[i] < low || p[i] < p[i-1]) {
            low = p[i];
        } 
        
        if (p[i]-low > max) {
            max = p[i]-low;
        }
   
    }
    
    return max;
}

int main()
{
    // vector<int> p = {45, 24, 35, 31, 40, 38, 25, 40, 70, 55, 24, 10};
    vector<int> p = {100, 180, 260, 310, 40, 535, 695};
    for (auto i: p) {
        cout << i << " ";
    }
    cout << endl;
    cout << "max profit " << max_profit(p);
    
    return 0;
}
