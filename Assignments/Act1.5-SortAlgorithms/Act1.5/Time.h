#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
float getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return elapsed.count() * 1e-9;
    //printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

void printTime(float time){
  printf("Execution time: %.8f seconds.\n", time);
  cout <<endl;
}

class Hour{
  public:
    int second;
    int minute;
    int hour;

    Hour();
    Hour(int , int, int);

    bool operator< (Hour h);
    bool operator== (Hour h);
    bool operator!= (Hour h);
    bool operator> (Hour h);
    bool operator>= (Hour h);
    bool operator<= (Hour h);

};

Hour::Hour(){
    second = rand() % 59;
    minute = rand() % 59;
    hour = rand() % 24;
}

Hour::Hour( int h, int min, int sec)
{
    second = sec;
    minute = min;
    hour = h;
}

ostream& operator<<(ostream &s, const Hour &hour) {
    return s << hour.hour <<":"<<hour.minute<<":"<<hour.second;
}
istream& operator>>(istream &input, Hour &h ) { 
  input >> h.hour >> h.minute >> h.second;
  return input;            
}

bool Hour::operator ==(Hour h){
  if (hour == h.hour && minute == h.minute && second == h.second){
    return true;
  }
  return false;
}

bool Hour::operator<(Hour h){
  if (hour < h.hour){
    return true;
  } 
  if (hour == h.hour && minute < h.minute){
    return true;
  }
  if (minute == h.minute && second < h.second){
    return true;
  }
  return false;
}
bool Hour::operator > (Hour h){
  if(*this<h || *this == h){
    return false;
  }
  return true;
}

bool Hour::operator >=(Hour h){
  if(*this < h){
    return false;
  }
  return true;
}

bool Hour::operator <=(Hour h){
  if(*this < h || *this== h){
    return true;
  }
  return false;
}

bool Hour::operator!= (Hour h){
  return !(*this == h);
}