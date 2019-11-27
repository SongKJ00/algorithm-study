#include <iostream>
#include <set>
#include <vector>

int main(void)
{
  //freopen("600_div_2/b.txt", "r", stdin);
  int numOfTotalEvents;
  std::set<int> isEnteredList;
  std::set<int> inOfficeList;
  std::vector<int> inputs;
  std::vector<int> validEventsNum;
  bool isInvalid = false;

  /* --- Input --- */
  std::cin >> numOfTotalEvents;
  inputs.resize(numOfTotalEvents);
  for(auto i = 0; i < numOfTotalEvents; i++)
  {
    std::cin >> inputs[i];
    int employee = abs(inputs[i]);
  }

  int eventCnt = 0;
  for(auto i = 0; i < numOfTotalEvents; i++)
  {
    eventCnt++;
    bool enterState = inputs[i] >= 0;
    int employee = abs(inputs[i]);

    if(enterState)
    {
      if(inOfficeList.find(employee) != inOfficeList.end()) // employee has already entered
      {
        isInvalid = true;
        break;
      }
      else
      {
        if(isEnteredList.find(employee) != isEnteredList.end())
        {
          isInvalid = true;
          break;
        }
        else
        {
          inOfficeList.insert(employee);
          isEnteredList.insert(employee);
        }
      }
    }
    else
    {
      if(inOfficeList.find(employee) == inOfficeList.end()) // employee has already out;
      {
        isInvalid = true;
        break;
      }
      else
      {
        inOfficeList.erase(employee);
        if(inOfficeList.empty())
        {
          isEnteredList.clear();
          validEventsNum.push_back(eventCnt);
          eventCnt = 0;
        }
      }
    }
  }

  if(isInvalid || !(inOfficeList.empty()))
  {
    std::cout << -1 << std::endl;
  }
  else
  {
    std::cout << validEventsNum.size() << std::endl;
    for(auto i = 0; i < validEventsNum.size(); i++)
    {
      std::cout << validEventsNum[i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}