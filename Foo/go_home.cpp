#include <iostream>
#include <vector>

int main(void)
{
  int N, B;
  std::vector<int> S, T;

  std::cin >> N >> B;
  S.resize(N);
  T.resize(N);

  for(int i = 0; i < N; i++)
  {
    std::cin >> S[i] >> T[i];
  }

  std::sort(S.begin(), S.end());

  int passedTime = 0;
  for(int i = 0; i < N; i++)
  {
    if(passedTime < S[i])
    {
      passedTime += S[i] - passedTime;
    }
    passedTime += T[i];
    passedTime += B;
  }

  std::cout << passedTime << std::endl;

  return 0;
}