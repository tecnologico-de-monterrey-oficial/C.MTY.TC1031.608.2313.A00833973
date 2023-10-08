#pragma once
#include <map>
#include <algorithm>
#include "extras.h"

 struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key;
    string keyIP;

    Log();
    Log(string year, string month, string day, string time, string ip, string message);

    void keyGenerator();
    void keyGeneratorIP();

    bool operator <  (Log log);
    bool operator >  (Log log);
    bool operator == (Log log);
    bool operator <= (Log log);
    bool operator >= (Log log);
    bool operator != (Log log);

    friend ostream& operator<<(ostream& os, Log log); 

};

Log::Log(){
}

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;

    // Generamos la llave con una función que convierta el mes a numero y concatene año, mes, dia y hora
    keyGenerator();
    keyGeneratorIP();
}

void Log::keyGenerator(){
    string monthNumber = getMonth(month);
    key = addZero(year,4) + addZero(monthNumber,2) + addZero(day,2) + addZero(time,6);
    key.erase( remove(key.begin(), key.end(), ':') , key.end());
}

void Log::keyGeneratorIP(){
    vector<string> ips = split(ip,'.');
    string IPkey = "";
    for(int i = 0; i< ips.size(); i++){

        IPkey += addZero(ips[i],3);
    }
    keyIP = IPkey + key;
}

bool Log::operator<(Log log) {
    return key < log.key;
}
bool Log::operator>(Log log){
    return key > log.key;
}
bool Log::operator==(Log log){
    return key == log.key;
}
bool Log::operator!=(Log log){
    return key != log.key;
}
bool Log::operator<=(Log log){
    return key <= log.key;
}
bool Log::operator>=(Log log){
    return key >= log.key;
}

ostream& operator<<(ostream& os, Log log) {
    os << "Log: " << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " "<< log.message  << /*" " << log.key << "\t"<< log.keyIP <<*/ "\n";
    return os;
}


