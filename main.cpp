#include <iostream>
#include "Content.h"

using namespace std;

int main()
{
    Content mainStructure; //make a content

    int choice = -1;
    string junk;
    while(choice!=6){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert data structure node"<<endl;
        cout<<"2. Insert entry node"<<endl;
        cout<<"3. Delete node"<<endl;
        cout<<"4. Change node name"<<endl;
        cout<<"5. Check hash"<<endl;
        cout<<"6. Quit"<<endl;
        cin>>choice; // the menu
        getline(cin,junk);
        if(choice==1){ // make a structure
            mainStructure.insertNodeStruct();
        }
        if(choice==2){ // add a node
            mainStructure.insertNodeData();
        }
        if(choice==3){ // delete a node
            mainStructure.deleteNode();
        }
        if(choice==4){ // change a node name
            mainStructure.changeName();
        }
        if(choice==5){ // check a hash
            mainStructure.checkHash();
        }
        if(choice==6){ // exit
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
