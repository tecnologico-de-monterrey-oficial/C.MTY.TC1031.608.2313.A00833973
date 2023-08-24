#include <iostream>
#include <vector>

using namespace std;

// O(n)
int sumIteractive (vector<int> n){

    int size = n.size() - 1 ;
    int sum = 0;
    for (int i = 0; i <= size; i++){
        int d = n[i];
        if (d % 2 != 0){
            sum += d;
        }
    }
    return sum;
}

//O(n)
int sumRecursive(vector<int> n){
   
    int i = n.size() - 1;
    
    if (i >= 0){

        int value = n[i];
        n.pop_back();

        if(value % 2 !=0){
            return value + sumRecursive(n);
        }
        else{
            return sumRecursive(n);
        }

    }else{
        return 0;
    }
}
int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    cout << "Ambos algorítmos son O(n)" << endl;
    cout << sumIteractive(a) << "  " << sumRecursive(a);
    return 0;
}
