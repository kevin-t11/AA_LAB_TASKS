#include <iostream>
#include <vector>

using namespace std;

int random(int p, int r) {
  srand(time(0));
  int ans = p + rand() % (r - p + 1);
  return ans;
}

int partition(vector<int> &arr, int p, int r, int &comp) {
  int x = arr[r];
  int i = p - 1;
  int j;

  for (j = p; j <= r - 1; j++) {
    comp++;
    if (arr[j] <= x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[r]);
  return i + 1;
}

int randomized_partition(vector<int> &arr, int p, int r, int &comp) {
  int i = random(p, r);
  swap(arr[i], arr[r]);

  return partition(arr, p, r, comp);
}

void randomized_qs(vector<int> &arr, int p, int r, int &comp) {
  if (p < r) {
    int q = randomized_partition(arr, p, r, comp);
    randomized_qs(arr, p, q - 1, comp);
    randomized_qs(arr, q + 1, r, comp);
  }
}

int n_partition(vector<int> arr, int p, int r, int &comp) {
  int x = arr[r];

  int i = (p - 1);

  for (int j = p; j <= r - 1; j++) {
    comp++;
    if (arr[j] < x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[r]);
  return (i + 1);
}

void n_quickSort(vector<int> arr, int p, int r, int &comp) {
  if (p < r) {
    int pi = n_partition(arr, p, r, comp);
    n_quickSort(arr, p, pi - 1, comp);
    n_quickSort(arr, pi + 1, r, comp);
  }
}

int main() {

  vector<int> arr;
  // worst case for quick sort
  for (int i = 0; i < 1000; i++) {
    arr.push_back(i);
  }
  int comp = 0;
  // randomized_qs(arr, 0, arr.size() - 1, comp);

  // normal quicksort
  n_quickSort(arr, 0, arr.size() - 1, comp);

  for (auto i : arr)
    cout << i << " ";
  cout << endl;

  cout << comp << endl;
  return 0;
}