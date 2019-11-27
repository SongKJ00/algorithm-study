#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
  int numOfSweets, maxSweetEachDay;
  int totalEatDay = 1;
  std::vector<int> sweets;
  std::vector<long long> totalSugarPen;
  std::vector<long long> addSweetEachDay;

  std::cin >> numOfSweets >> maxSweetEachDay;
  addSweetEachDay.resize(maxSweetEachDay);
  sweets.resize(numOfSweets+1);
  totalSugarPen.resize(numOfSweets+1);
  sweets[0] = 0;
  totalSugarPen[0] = 0;
  for(auto i = 1; i < sweets.size(); i++)
  {
    std::cin >> sweets[i];
  }

  std::sort(sweets.begin(), sweets.end());

  for(auto i = 1; i < sweets.size(); i++)
  {
    if(i <= maxSweetEachDay)
    {
      totalSugarPen[i] = totalSugarPen[i-1] + sweets[i];
      addSweetEachDay[i-1] = sweets[i];
    }
    else
    {
      int dayOffset = (i-1) % maxSweetEachDay;
      if(dayOffset == 0)
      {
        totalEatDay++;
      }
      addSweetEachDay[dayOffset] += sweets[(totalEatDay-1)*maxSweetEachDay + (dayOffset+1)];
      totalSugarPen[i] = totalSugarPen[i-1] + addSweetEachDay[dayOffset];
    }
  }

  for(auto i = 1; i < sweets.size(); i++)
  {
    std::cout << totalSugarPen[i] <<  " ";
  }
  std::cout << std::endl;

}

