#include <iostream>
#include <vector>

int main(void)
{
  int origSensorLen, newSensorLen;
  std::vector<int> origSensorPacket, newSensorPacket;
  std::pair<int, int> origSensorBinCnt; // <0, 1>
  std::pair<int, int> newSensorBinCnt; // <0, 1> or <1, 0>

  std::cin >> origSensorLen >> newSensorLen;
  origSensorPacket.resize(origSensorLen);
  newSensorPacket.resize(newSensorLen);

  for(int i = 0; i < origSensorLen; i++)
  {
    std::cin >> origSensorPacket[i];
    if(origSensorPacket[i] == 0)
    {
      origSensorBinCnt.first++;
    }
    else
    {
      origSensorBinCnt.second++;
    }
  }
  for(int i = 0; i < newSensorLen; i++)
  {
    std::cin >> newSensorPacket[i];
    if(i % 2 == 0)
    {
      newSensorBinCnt.first += newSensorPacket[i];
    }
    else
    {
      newSensorBinCnt.second += newSensorPacket[i];
    }
  }

  std::vector<std::vector<int> > possibleConvPacket;

  if(newSensorBinCnt.first == newSensorBinCnt.second)
  {
    possibleConvPacket.resize(2);
    for(int i = 0; i < 2; i++)
    {
      int currNum = i;
      for(int j = 0; j < newSensorPacket.size(); j++)
      {
        for(int k = 0; k < newSensorPacket[j]; k++)
        {
          possibleConvPacket[i].push_back(currNum);
        }
        currNum = currNum == 0 ? 1 : 0;
      }
    }
  }
  else
  {
    possibleConvPacket.resize(1);
    int currNum;
    if(origSensorBinCnt.first == newSensorBinCnt.first)
    {
      currNum = 0;
    }
    else
    {
      currNum = 1;
    }
    for(int i = 0; i < newSensorPacket.size(); i++)
    {
      for(int j = 0; j < newSensorPacket[i]; j++)
      {
        possibleConvPacket[0].push_back(currNum);
      }
      currNum = currNum == 0 ? 1 : 0;
    }
  }

  std::vector<int> tempOrigSensorPacket = origSensorPacket;
  int ret = -1;
  for(int i = 0; i < possibleConvPacket.size(); i++)
  {
    int cnt = 0;
    for(int j = 0; j < origSensorPacket.size(); j++)
    {
      if(possibleConvPacket[i][j] != origSensorPacket[j])
      {
        for(int k = j + 1; k < origSensorPacket.size(); k++)
        {
          cnt++;
          if(origSensorPacket[k] != origSensorPacket[j])
          {
            std::swap(origSensorPacket[k], origSensorPacket[j]);
            break;
          }
        }
      }
    }
    ret = ret == -1 ? cnt : std::min(ret, cnt);
    origSensorPacket = tempOrigSensorPacket;
  }

  std::cout << ret << std::endl;

  return 0;
}