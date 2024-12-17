#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printFrequencySorted(const string& s) {
    vector<pair<int, int>> freq(26, {0, 0});

    for (int i = 0; i < 26; i++) {
        freq[i].first = i;
    }

    for (char ch : s) {
        freq[ch - 'A'].second++;
    }

   	sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    for (const auto& p : freq) {
        if (p.second > 0) {
            cout << string(p.second, 'A' + p.first);
        }
    }
    cout << endl;

}

int main(){
    string s="DACDACCDCBC";
    printFrequencySorted(s);
    
    string s1="ZXZXYYZZYYXYYZZZWWQQQQQVVVVVVVVVWXX";
    printFrequencySorted(s1);
    return 0;
}
