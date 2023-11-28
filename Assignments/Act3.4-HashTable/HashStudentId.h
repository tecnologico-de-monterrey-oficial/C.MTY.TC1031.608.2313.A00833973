
#include <iostream>

#include <vector>
using namespace std;

class HashStudentId {
private:
    vector<string> table;
    vector<char> status;
    int hash(string);
public:
    HashStudentId();
    void insert(string studentId);
    int FindStudentId(string studentId);
    int erase(string studentId);
    void print();
};

HashStudentId::HashStudentId()
{
    table.resize(101);
    status = vector<char>(101,'v');
}

void HashStudentId::insert(string studentId){
    int index = hash(studentId);
    int sIn = index;

    if (table [index] == ""){
        table[index] = studentId;
        status[index] = 'o';
    }
    else{
        while(status[sIn] != 'v'){ 
            sIn =  (sIn + 1) % 101;
            if (index == sIn ){
                return;
            }
        }
        table[sIn] = studentId;
        status[sIn]= 'o';
    }    
}

int HashStudentId::hash(string studentId){

    string el = studentId.erase(0,1);
    int index = stoi(el) % 101;  
    return index;
}


int HashStudentId::FindStudentId(string studentId){
    int index = hash(studentId);
    if(table[index] == studentId){
        return index;
    }

    int sIn = (index + 1) % 101;
    while((status[sIn] != 'v') && index != sIn ){ 
        if(table[sIn] == studentId){
            return sIn;
        }
        sIn =  (sIn + 1) % 101;
    }
    return -1;
}


int HashStudentId::erase(string studentId){
    int index = FindStudentId(studentId);
    table[index] = "";
    status[index] = 'b';
}


void HashStudentId::print(){
    for (int i =0; i < 101; i++){
        cout << i << ": " << table[i] << endl;
    }
}