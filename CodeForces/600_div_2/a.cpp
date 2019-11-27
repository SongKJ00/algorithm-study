#include <iostream>
#include <vector>

int main(void)
{
  //freopen("600_div_2/a.txt", "r", stdin);
  int numOfCase;
  int arrLen;
  std::vector<int> arr1, arr2;
  std::vector<bool> result;

  std::cin >> numOfCase;
  result.resize(numOfCase);

  for(int i = 0; i < numOfCase; i++)
  {
    std::cin >> arrLen;
    arr1.resize(arrLen);
    arr2.resize(arrLen);
    for (int j = 0; j < arrLen; j++)
    {
      std::cin >> arr1[j];
    }
    for (int j = 0; j < arrLen; j++)
    {
      std::cin >> arr2[j];
    }

    int prevGap = 0;
    bool gapMustNotBeChanged = false;
    bool isValid = true;
    for (int j = 0; j < arrLen; j++)
    {
      int currGap = arr2[j] - arr1[j];
      if(currGap < 0)
      {
        isValid = false;
        break;
      }
      if(gapMustNotBeChanged && prevGap != currGap)
      {
        isValid = false;
        break;
      }
      if(prevGap != currGap && prevGap > 0 && currGap > 0)
      {
        isValid = false;
        break;
      }
      if(prevGap > 0 && currGap == 0)
      {
        gapMustNotBeChanged = true;
      }
      prevGap = currGap;
    }
    result[i] = isValid;
  }

  for(int i = 0; i < numOfCase; i++)
  {
    if(result[i])
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }
}
