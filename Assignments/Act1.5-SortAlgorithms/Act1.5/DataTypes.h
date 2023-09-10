#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>
#include "Time.h"
using namespace std;

void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}
void createListChar(vector<char> &list, int quantity){
    for (int i = 0; i < quantity; i++)
    {
        int num = 91;
        while (num >= 91 && num <= 96)
            {
            num = rand() % 58 + 65;
            }
        list.push_back(char(num));
    }
}

void createListHour(vector<Hour> &list, int quantity){
     for (int i = 0; i < quantity; i++)
    {
        Hour h = Hour();
        list.push_back(h);
    }
}
// }

// template <class T>
// int getListByType(vector<T> list, int type, int size){
//     switch (type)
//     {
//     case 0:
//         createListInt(list,size);
//         return 0;
//     case 1:
//         createListChar(list,size);
//         return 0;
//     case 3:
//         createListTime(list,size);
//         return 0;
//     default:
//         return (-1);
//     }
// }