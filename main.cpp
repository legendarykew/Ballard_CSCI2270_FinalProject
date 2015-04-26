#include <iostream>
#include "Content.h"

using namespace std;

int main()
{
    Content mainStructure; //make a content

    int choice = -1;
    string junk;
    while(choice!=4){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert data structure node"<<endl;
        cout<<"2. Insert entry node"<<endl;
        cout<<"3. Delete node"<<endl;
        cout<<"4. Quit"<<endl;
        cin>>choice; // the menu
        getline(cin,junk);
        if(choice==1){
            mainStructure.insertNodeStruct();
        }
        if(choice==2){ // delete movie
            mainStructure.insertNodeData();
        }
        if(choice==3){ // find movie
            mainStructure.deleteNode();
        }
        if(choice==4){ // exit
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
