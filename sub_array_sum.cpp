#include <bits/stdc++.h> 
using namespace std; 

// Function to print subarray with sum as given sum 
void subArraySum(unordered_map<int, int>& map, int arr[], int n, int sum) { 

    // Maintains sum of elements so far 
    int curr_sum = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        // add current element to curr_sum 
        curr_sum = curr_sum + arr[i]; 
        //cout << "curr_sum " << curr_sum << endl;
        //cout << "curr_sum - sum " << curr_sum - sum << endl;
        
        
        // if curr_sum is equal to target sum 
        // we found a subarray starting from index 0 
        // and ending at index i 
        if (curr_sum == sum) 
        { 
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl; 
            return; 
        } 
  
        // If curr_sum - sum already exists in map 
        // we have found a subarray with target sum 
        if (map.find(curr_sum - sum) != map.end()) 
        { 
            cout << "Sum found between indexes "
                 << map[curr_sum - sum] + 1 
                 << " to " << i << endl; 
            return; 
        } 
  
        cout << "map[curr_sum]" << curr_sum << " " << i << endl;
        map[curr_sum] = i; 
        // cout << "==========================" << endl;
    } 
  
    // If we reach here, then no subarray exists 
    cout << "No subarray with given sum exists"; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {9, 10, 2, -2, -20, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = -10; 
    unordered_map<int, int> map;
    
    subArraySum(map, arr, n, sum); 
    
    
    // Traversing an unordered map 
    //for (auto x : map)  
    //  cout << x.first << " " << x.second << endl; 
    //cout << "map size " << map.size() << endl;

    return 0; 
} 
