#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int N)
{
  long long answer = 0;

  if(N == 1) { return 1*4; }
  if(N == 2) { return (1+1)*4; }

  long long a = 1, b = 1;
  long long c = 1;
  for(int i = 2; i < N+1; i++)
  {
    a = b;
    b = c;
    c = a + b;
  }

  answer = (c + b) * 2;
  return answer;
}

int main()
{
  cout << solution(5) << endl;
  cout << solution(6) << endl;
}