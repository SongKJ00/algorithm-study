#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& heightPlanks)
{
  const int width = heightPlanks.size();
  int maxLength = 0;

  std::sort(heightPlanks.begin(), heightPlanks.end());

  for(int i = 0; i < width; i++)
  {
    int diffHereEnd = width-i;
    if(heightPlanks[i] <= diffHereEnd)
    {
      maxLength = heightPlanks[i];
    }
    else
    {
      if(diffHereEnd > maxLength)
      {
        maxLength = diffHereEnd;
      }
      return maxLength;
    }
  }

  return maxLength;
}

int main(void)
{
  int numTestCase;
  int numPlanks;
  std::vector<int> maxLengthOfCase;

  std::cin >> numTestCase;
  maxLengthOfCase.resize(numTestCase);
  for(int i = 0; i < numTestCase; i++)
  {
    std::cin >> numPlanks;
    std::vector<int> heightPlanks(numPlanks);
    for(int j = 0; j < numPlanks; j++)
    {
      std::cin >> heightPlanks[j];
    }
    maxLengthOfCase[i] = solution(heightPlanks);
  }

  for(int i = 0; i < numTestCase; i++)
  {
    std::cout << maxLengthOfCase[i] << std::endl;
  }

  return 0;
}