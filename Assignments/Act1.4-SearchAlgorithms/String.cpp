#include <iostream>
#include <string>
using namespace std;

char getCharSequencial(string text, int& repeat ){
    
    int size = text.size() - 1;

    for (int i = 0; i <= size; i+= 2){
        repeat ++;
        if (text[i] != text[i +1]){
            return text[i];
        }
        else if (size - (i + 1) == 1){
            return text[i + 2];
        }
    }
    return ' ';
}

char getCharBinary(string text, int& repeat){
    
    int right = text.size() - 1;
    int left = 0;
    int i;
    
    while ((right - left ) >= 0){
        
        repeat ++;
        i = left + ( right - left )/2;
        //cout << i<<text[i];
        
        if (text[i] != text[i+1] && text[i] != text[i-1]){
                return text[i];
        }

        else if(text[i] != text[i + 1] || (i%2 == 0 && text[i] == text[i+1])){
            left = i + 1;
            if (right - left == 0){
                return text[i+1];
            }
        }

        else {
            right = i - 1;
            if (right - left == 0){
                return text[i-1];
            }
        }
    }
    return ' ';
}

int main()
{
    int sizeArray = 0;
    cin >> sizeArray;

    string s[sizeArray];
    for (int i = 0; i < sizeArray; i++){
        cin >> s[i];
    }

    int repSeq = 0;
    int repBin = 0;

    for (int i =0; i<sizeArray; i++){
        cout << getCharSequencial(s[i],repSeq) << " " << repSeq << " ";
        cout << getCharBinary(s[i],repBin) << " " << repBin << endl;

        repSeq = 0;
        repBin = 0;
    }
    
    return 0;
}
