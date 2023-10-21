#include <bits/stdc++.h>
using namespace std;

// check for all these string also

// "acaca"
// "aaaaa"
// "abcde"
// "aaabb"
// "abaab"
// "aaaba"

int main() {
  // PI Table
  string p1 = "acac";
  int m = p1.size();
  string p = "0" + p1;
  vector<int> pi(m + 1, 0);
  // count the no of comparisons
  int count = 0;
  int k = 0;

  for (int q = 2; q <= m; q++) {
    bool t = (p[k + 1] != p[q]);
    count++;

    while (k > 0 && t) {
      k = pi[k];
      t = (p[k + 1] != p[q]);
      count++;
    }

    if (!t) {
      k++;
    }
    pi[q] = k;
  }

  // print the pi table
  for (int i = 1; i <= m; i++) {
    cout << p[i] << " " << pi[i] << endl;
  }

  cout << "total count is " << count << endl;

  // KMP Matcher
  string t1 = "acacacacac";
  int n = t1.size();
  string t = "0" + t1;
  int q = 0;

  for (int i = 1; i <= n; i++) {
    while (q > 0 && p[q + 1] != t[i]) {
      q = pi[q];
    }
    if (p[q + 1] == t[i]) {
      q = q + 1;
    }
    if (q == m) {
      cout << "pattern occures with shift " << i - m << endl;
      q = pi[q];
    }
  }

  return 0;
}