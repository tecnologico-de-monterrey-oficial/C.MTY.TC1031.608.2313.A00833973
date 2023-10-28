#pragma once
struct AmountIP
{
    string ip;
    int amount;
    AmountIP(string, int);
    AmountIP();

    bool operator <(AmountIP);
    bool operator >(AmountIP);
    bool operator == (AmountIP);
    bool operator <= (AmountIP);
    bool operator >= (AmountIP);
    bool operator != (AmountIP);
};

AmountIP::AmountIP(string ip, int amount)
{
    this->ip = ip;
    this->amount = amount;

}
AmountIP::AmountIP()
{
    this->ip = "";
    amount = 0;

}
bool AmountIP::operator<(AmountIP other){
    return ip < other.ip;
}

bool AmountIP::operator>(AmountIP other){
    return ip > other.ip;
}

bool AmountIP::operator==(AmountIP other){
    return ip == other.ip;
}
bool AmountIP::operator!=(AmountIP other){
    return ip != other.ip;
}
bool AmountIP::operator<=(AmountIP other){
    return ip <= other.ip;
}
bool AmountIP::operator>=(AmountIP other){
    return ip >= other.ip;
}

ostream& operator<<(ostream& os, AmountIP other) {
    os << "The IP: " << other.ip << " has " << other.amount << " registers.\n";
    return os;
}
