#include <iostream>
#include <vector>
using namespace std;

int find (vector<int> arr, int fin){

    int s = arr.size() - 1;
    int c = 0;
    int i;
    
    while ((s - c ) >= 0){
        i = c + ( s - c )/2;

        // cout << "loop ";
        // cout << i << "-"<< arr[i] <<" ";

        if (arr[i] == fin){
            return i;
        }
        else if (arr[i] < fin){
            c = i+1;
        }
        else{
            s = i-1;
        }
    }
    return -1;
}

int main()
{

    vector<int> a = {1,2,3,4,5};
    int f = 5;

    cout << find(a,f);
    
    return 0;
}
