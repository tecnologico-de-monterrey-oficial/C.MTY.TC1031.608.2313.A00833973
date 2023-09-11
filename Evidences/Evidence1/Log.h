#pragma once
#include <map>
#include<algorithm>

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key;

    map<string, string> MONTHS;

    Log(string year, string month, string day, string time, string ip, string message);

    void keyGenerator();
    void createMap();

    bool operator <  (Log log);
    bool operator >  (Log log);
    bool operator == (Log log);
    bool operator <= (Log log);
    bool operator >= (Log log);
    bool operator != (Log log);

    friend ostream& operator<<(ostream& os, Log log); 

};

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;

    createMap();
    // Generamos la llave con una función que convierta el mes a numero y concatene año, mes, dia y hora
    keyGenerator();
}

void Log::createMap(){

    MONTHS.insert(pair<string, string>("Jan", "01"));
    MONTHS.insert(pair<string, string>("Feb", "02"));
    MONTHS.insert(pair<string, string>("Mar", "03"));
    MONTHS.insert(pair<string, string>("Apr", "04"));
    MONTHS.insert(pair<string, string>("May", "05"));
    MONTHS.insert(pair<string, string>("Jun", "06"));
    MONTHS.insert(pair<string, string>("Jul", "07"));
    MONTHS.insert(pair<string, string>("Aug", "08"));
    MONTHS.insert(pair<string, string>("Sep", "09"));
    MONTHS.insert(pair<string, string>("Oct", "10"));
    MONTHS.insert(pair<string, string>("Nov", "11"));
    MONTHS.insert(pair<string, string>("Dec", "12"));

}
void Log::keyGenerator(){
    string monthNumber = MONTHS[month];
    key = year + monthNumber + day + time;
    key.erase( remove(key.begin(), key.end(), ':') , key.end());
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
    os << "Log: " << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " "<< log.message  << "\n";
    return os;
}