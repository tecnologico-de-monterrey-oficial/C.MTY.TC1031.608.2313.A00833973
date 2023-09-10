#pragma once

struct Log{
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;

    Log(string year, string month, string day, string time, string ip, string message);
}

Log::Log(string year, string month, string day, string time, string ip, string message){
    this -> year = year;
    this -> month = month;
    this -> day = day;
    this -> time = time;
    this -> ip = ip;
    this -> message = message;
}
