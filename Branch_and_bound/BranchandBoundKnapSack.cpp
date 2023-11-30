
#include<iostream>
using namespace std;

class Item {
public:
  int i, j;
  int w; // w[i, j] = p(j) + q(j) + w[i, j-1]
  int c; // c[i, j] = c[i, r-1] + c[r+1, j] + w[i, j]
  int r; // r[i, j] = argmin(c[i, r-1] + c[r+1, j]) for i <= r <= j
};

int main() {
  int n;
  cin >> n;
  int p[n], q[n + 1]; // p[1..n], q[0..n]
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i <= n; i++)
    cin >> q[i];
  Item **items = new Item *[n + 1];
  for (int i = 0; i <= n; i++)
    items[i] = new Item[n + 1];
  for (int i = 0; i <= n; i++) {
    items[i][i].w = q[i];
    items[i][i].c = 0;
    items[i][i].r = 0;
  }
  for (int l = 1; l <= n; l++) { // l is the chain length
    for (int i = 0; i < n - l + 1; i++) { // i is the start index
      int j = i + l;                       // j is the end index
      items[i][j].w = p[j] + q[j] + (j > i ? items[i][j - 1].w : 0);
      items[i][j].c = INT16_MAX;
      for (int r = i; r <= j; r++) {
        int c = (r > i ? items[i][r - 1].c : 0) + (r < j ? items[r + 1][j].c : 0) + items[i][j].w;
        if (c < items[i][j].c) {
          items[i][j].c = c;
          items[i][j].r = r;
        }
      }
    }
  }
  cout << "Cost: " << items[0][n - 1].c << endl;
  return 0;
}