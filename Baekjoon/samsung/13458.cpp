#include <iostream>
#include <vector>

int main(void)
{
  long long ret = 0;
  int N;
  std::vector<int> A;
  int B, C;

  std::cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++)
  {
    std::cin >> A[i];
  }
  std::cin >> B >> C;

  for(int i = 0; i < A.size(); i++)
  {
    A[i] -= B;
    ret++;
    if(A[i] > 0)
    {
      int quot = A[i] / C;
      int rst = A[i] % C;
      ret += quot;
      if(rst > 0)
      {
        ret += 1;
      }
    }
  }

  std::cout << ret << std::endl;


  return 0;
}