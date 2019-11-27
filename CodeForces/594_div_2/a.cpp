#include <iostream>
#include <vector>

int main(void)
{
  int t;
  std::cin >> t;
  std::vector<long long> result;
  while(t--) {
    int n, m;
    std::vector<long long> evenCnt(2);
    std::vector<long long> oddCnt(2);
    std::cin >> n;
    while(n--) {
      int p;
      std::cin >> p;
      if(p % 2 == 0) {
        oddCnt[0]++;
      }
      else {
        evenCnt[0]++;
      }
    }
    std::cin >> m;
    while(m--) {
      int q;
      std::cin >> q;
      if(q % 2 == 0) {
        oddCnt[1]++;
      }
      else {
        evenCnt[1]++;
      }
    }
    result.push_back(oddCnt[0]*oddCnt[1] + evenCnt[0]*evenCnt[1]);
  }

  for(auto& r: result) {
    std::cout << r << std::endl;
  }
}