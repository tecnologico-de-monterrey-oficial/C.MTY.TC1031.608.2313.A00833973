#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>

#include "DataTypes.h"
#include "mainHelper.h"
using namespace std;

int main(){
    int type = 0;
    int amount = 0;
    int algorithm = 0;
    int searchAlg = 0;
    int searchIndex;

    menuType(type, amount);
    while (type >= 0){
        
        switch (type){
        case 1:
        {
            vector<int> list;
            createListInt(list, amount);
            sortAndSearch(list, algorithm, searchAlg, searchIndex);
            
            break;
        }
        case 2:
        {
            vector<char> list;
            createListChar(list, amount);
            sortAndSearch(list, algorithm, searchAlg, searchIndex);
            break;
        }
        case 3:
        {
            vector<Hour> list;
            createListHour(list, amount);
            sortAndSearch(list, algorithm, searchAlg, searchIndex);
            break;
        }
        default:
            break;
        }
        menuType(type, amount);
    }

    return 0;
}