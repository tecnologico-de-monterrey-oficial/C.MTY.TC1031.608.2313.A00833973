#include <iostream>
using namespace std;

#include "BST.h"
#include "mainHelper.h"

void createListInt(BST<int> &list, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        int num = rand() % 1000000 + 1;
        list.insert(num);
    }
}


int main() {
    BST<int> bst;
    int option = -1;

    cout << "BST STRUCTURE" << endl;
    while(option != 9){
        cout << endl;
        cout << "0. Insert random values"<< endl;
        cout << "1. Insert data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Print " << endl;
        cout << "4. Find data" << endl;
        cout << "5. Visit structure" << endl;
        cout << "6. Height" << endl;
        cout << "7. Ancestors" << endl;
        cout << "8. Data level " << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "Option: ";
        cin >> option;
        cout << endl;

        
        switch (option)
        {
            
        case 0:{
            cout << "Number of values: ";
            int amount; 
            cin >> amount;
            createListInt(bst,amount);
            break;
        }
        case 1:{
            cout << "Value of the data: ";
            int value;
            cin >> value;
            bst.insert(value); 
            break;
        }
        case 2:{
            cout << "Delete value: ";
            int value;
            cin>> value;
            bst.remove(value);
            break;
        }
        case 3:{
            bst.print();
            break;
        }
        case 4:{
            cout << "Find value: ";
            int value; 
            cin >> value;
            if (bst.find(value)){
                cout << "Value found"<< endl;
            }
            else{
                cout << "Value not found" << endl;
            }
            break;
        }
        case 5:{cout << "Visit by method"<<endl;
            cout << "1. Preorder" <<endl;
            cout << "2. Inorder " << endl;
            cout << "3. Postorder" << endl;
            cout << "4. Level By Level" << endl;
            cout << "Option: ";
            int op;
            cin >> op;
            bst.visit(op);
            break;
        }
        case 6:{
            cout << "The height of the structure is ";
            cout << bst.height() << endl;
            break;
            
        }
        case 7:{
            cout << "Data to find the ancestors: ";
            int value;
            cin >> value;
            bst.ancestors(value);
            break;
        }
        case 8:{
            cout << "Find level of value: ";
            int value;
            cin >> value;
            int level = bst.whatLevelAml(value);
            if(level != -1){
                cout << "The value is in level "<< level << endl;
            }
            else{
                cout << "Value not found";
            }
            break;
        } 
        default:
            break;
        }
    }
    return 0;
}