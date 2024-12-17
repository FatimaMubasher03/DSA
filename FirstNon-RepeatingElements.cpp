#include <iostream>
#include <vector>
using namespace std;

int firstNonRepeatingElement(vector<int>& nums) {
    vector<int> freq(2001,0);
    
    for (int num : nums) {
        freq[num + 1000]++;
    }

    for (int num : nums) {
        if (freq[num + 1000] == 1) {
            return num;
        }
    }
    return -1;
}


int main() {
    vector<int> nums = {4, 5, 6, 7, 4, 6, 5, 6, 4, 5, 5, 6};
    cout << firstNonRepeatingElement(nums) << endl; 
    vector<int> nums1= {1, 5, 2, 5, 4, 1, 2, 3, 4, 3, 5};
    cout << firstNonRepeatingElement(nums1) << endl;

    return 0;
}