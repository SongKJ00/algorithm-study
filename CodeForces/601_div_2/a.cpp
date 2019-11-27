#include <iostream>
#include <vector>

int main(void)
{
  int numOfCase;
  int a, b;
  std::vector<int> result;

  std::cin >> numOfCase;
  result.resize(numOfCase);

  for(int i = 0; i < numOfCase; i++)
  {
    std::cin >> a >> b;
    int changeCnt = 0;
    int gap = abs(a-b);
    int quot = gap / 5;
    int remainder = gap % 5;
    switch(remainder)
    {
      case 0:
        changeCnt = quot;
        break;
      case 1:
      case 2:
        changeCnt = quot + 1;
        break;
      case 3:
      case 4:
        changeCnt  = quot + 2;
        break;
    }
    result[i] = changeCnt;
  }

  for(int i = 0; i < numOfCase; i++)
  {
    std::cout << result[i] << std::endl;
  }


  return 0;
}