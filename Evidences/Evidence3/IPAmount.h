struct IPAmount
{
    string ip;
    int amount;
    IPAmount(string, int);
    IPAmount();

    void operator ++();
    bool operator <(IPAmount);
    bool operator >(IPAmount);
    bool operator == (IPAmount);
    bool operator <= (IPAmount);
    bool operator >= (IPAmount);
    bool operator != (IPAmount);
};

IPAmount::IPAmount(string ip, int amount)
{
    this->ip = ip;
    this->amount = amount;

}
IPAmount::IPAmount()
{
    this->ip = "";
    amount = 0;

}
void IPAmount::operator++(){
    amount ++;
}

bool IPAmount::operator<(IPAmount other){
    return amount < other.amount;
}

bool IPAmount::operator>(IPAmount other){
    return amount > other.amount;
}

bool IPAmount::operator==(IPAmount other){
    return amount == other.amount;
}
bool IPAmount::operator!=(IPAmount other){
    return amount != other.amount;
}
bool IPAmount::operator<=(IPAmount other){
    return amount <= other.amount;
}
bool IPAmount::operator>=(IPAmount other){
    return amount >= other.amount;
}

ostream& operator<<(ostream& os, IPAmount other) {
    os << "The IP: " << other.ip << " has " << other.amount << " registers.\n";
    return os;
}


