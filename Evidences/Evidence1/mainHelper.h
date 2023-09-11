#pragma once

template <class T>
void writeFile(string fileName, vector<T> list){
    ofstream file(fileName);
     if (file.is_open())
    {
        for(int i = 0; i<list.size(); i++){
            file<< list[i];
        }
        file.close();
    }
    else cout << "Unable to open file";
}

void askData(string& data, string text, int size){
    int currentSize = 0;
    while (currentSize != size){
        cout << text;
        cin >> data;
        currentSize = data.size();
    }
}

Log askLogTime(){
    string year;
    string month;
    string day;
    string time;

    
    cout << "Introduce the next data"<<endl;
    askData(year,"Year (yyyy): ",4);
    askData(month,"Month (mmm): ",3);
    askData(day,"Day (dd): ",2);
    askData(time,"Time (hh:mm:ss): ",8);
    cout << endl;
    Log newLog = Log(year, month, day, time, "", "");
    return newLog;
}

void getRange(vector<Log> list, vector<Log>& rangeList){
    cout << endl;
    cout << "Left limit" << endl;
    Log left = askLogTime();

    cout << "Right limit" << endl;
    Log right = askLogTime();

    cout << "Searching..."<<endl;
    int leftIndex = binarySearch(list, left);
    int rightIndex = binarySearch(list, right);
    cout << "Search completed"<<endl;

    if (list[leftIndex] < left){
        leftIndex++;
    }
    if(list[rightIndex] > right){
        rightIndex--;
    }

    for (int i = leftIndex ; i < rightIndex + 1; i++){
        rangeList.push_back(list[i]);
    }
    
}
