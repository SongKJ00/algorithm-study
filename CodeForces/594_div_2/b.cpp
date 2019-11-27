#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
  int n;

  std::cin >> n;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end(), std::greater<int>());

  int horCnt = n / 2;
  int verCnt = n - horCnt;

  long long horLen = 0, verLen = 0;

  for(int i = 0; i < verCnt; i++) {
    verLen += a[i];
  }
  for(int i = verCnt; i >= 0 && i < n; i++) {
    horLen += a[i];
  }

  long long result = horLen*horLen + verLen*verLen;
  std::cout << result << std::endl;
}