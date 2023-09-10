#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

template <class T>
int binarySearch(vector<T> list, T find){
    int right = list.size() - 1;
    int left = 0;
    int i;
    
    while ((right - left) >= 0){
        i = left + ( right - left)/2;

        if (list[i] == find){
            return i;
        }
        else if (list[i] < find){
            left = i+1;
        }
        else{
            right = i-1;
        }
    }
    return -1;

}
template <class T>
int sequentialSearch(vector<T> list, T find){
  
  for (int i = 0; i < list.size() - 1; i++){
    if (list[i] == find){
      return i;
    }
  }
  return -1;
}
