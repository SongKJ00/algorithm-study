#include <iostream>
#include <string>
#include <vector>

bool solution(int strLen, std::string& str1, std::string& str2)
{
  std::vector<int> diff;

  for(int i = 0; i < strLen; i++)
  {
    if(str1[i] != str2[i]) 
    { 
      diff.push_back(i);
    }
  }

  if(diff.size() == 2)
  {
    if((str1[diff[0]] == str1[diff[1]]) && (str2[diff[0]] == str2[diff[1]]))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
  
}

int main(void)
{
  int numTestCase;
  int strLen;
  std::string str1, str2;

  std::cin >> numTestCase;
  std::vector<bool> canBeSwapped(numTestCase);

  for(int i = 0; i < numTestCase; i++)
  {
    std::cin >> strLen;
    std::cin >> str1;
    std::cin >> str2;

    canBeSwapped[i] = solution(strLen, str1, str2);
  }

  for(int i = 0; i < numTestCase; i++)
  {
    if(canBeSwapped[i])
    {
      std::cout << "Yes" << std::endl; 
    }
    else
    {
      std::cout << "No" << std::endl;
    }
    
  }
}