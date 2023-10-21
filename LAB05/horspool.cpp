#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string text;
  cin >> text;

  int size_text = text.length();
  // cout << size << " ";
  string pattern;
  cin >> pattern;

  int size_ptn;
  pattern.length();

  unordered_map<char, int> shiftTable;

  for (int i = 1; i <= 26; i++) {
    shiftTable[pattern[i]] = size_ptn;
  }
  for (int i = 0; i < size_text - 1; i++) {
    shiftTable[pattern[i] - 'a'] = size_text - 1 - i;
  }

  int j = 0;
  while (j + size_ptn <= size_text) {
    if (pattern[size_ptn - 1] == text[j + size_ptn - 1]) {
      int i = size_ptn - 2;
      while (i >= 0 && pattern[i] == text[j + i]) {
        i = i - 1;
      }
      if (i == -1)
        cout << j << " ";
    }
    if (text[(j + size_ptn - 1)] == '_')
      j += size_ptn;
    else
      j = j + shiftTable[text[j + size_ptn - 1]];
  }
}