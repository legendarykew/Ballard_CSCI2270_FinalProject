#include "Content.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Content::Content(){
    Node* newRoot = new Node(1,"root",1);
    root = newRoot;
};

Content::~Content(){};

int Content::getHash(string in_title){ // from lecture notes
    int sum = 0;
    for(int i = 1;i<in_title.length();i++){ // sum up ascii values then mod by 10 to get the hash
        sum = sum + in_title[i];
    }
    sum = sum % 10;
    return sum;
}

Node* Content::traverse(Node* currentNode, Node* newNode, int level){
    if(currentNode->type==1){
        if(currentNode->nextRight==NULL){
            currentNode->nextRight = newNode;
            if(level==1){
                return currentNode->nextRight;
            }else{
                return currentNode;
            }
        }else{
            cout<<"Traversing down linked list " << currentNode->name << "..."<<endl;
            return traverse(currentNode->nextRight, newNode, level);
        }
    }
    if(currentNode->type==2){
        if(currentNode->nextRight==NULL and currentNode->nextLeft==NULL){
            cout<<"Traversing empty binary tree "<< currentNode->name<<"..."<<endl;
            currentNode->nextRight = newNode;
            if(level==1){
                return currentNode->nextRight;
            }else{
                return currentNode;
            }
        }else{
            cout<<"Found binary tree "<< currentNode->name <<", select branch:"<<endl;
            if(currentNode->nextLeft==NULL){
                cout<<"1 - NULL"<<endl;
            }else{
                cout<<"1 - "<<currentNode->nextLeft->name<<endl;
            }
            if(currentNode->nextRight==NULL){
                cout<<"2 - NULL"<<endl;
            }else{
                cout<<"2 - "<<currentNode->nextRight->name<<endl;
            }
            string strchoice;
            getline(cin,strchoice);
            int choice = -1;
            choice = atoi(strchoice.c_str());
            if(choice==1){
                if(currentNode->nextLeft==NULL){
                    currentNode->nextLeft = newNode;
                    if(level==1){
                        return currentNode->nextLeft;
                    }else{
                        return currentNode;
                    }
                }else{
                    return traverse(currentNode->nextLeft, newNode, level);
                }
            }else{
                if(currentNode->nextRight==NULL){
                    currentNode->nextRight = newNode;
                    if(level==1){
                        return currentNode->nextRight;
                    }else{
                        return currentNode;
                    }
                }else{
                    return traverse(currentNode->nextRight, newNode, level);
                }
            }
        }
    }
    if(currentNode->type==3){
        int nameHash = getHash(newNode->name);
        cout<<"Traversing down hash table " << currentNode->name << "..."<<endl;
        if(currentNode->hTable[nameHash]==NULL){
            currentNode->hTable[nameHash] = newNode;
            if(level==1){
                return currentNode->hTable[nameHash];
            }else{
                return currentNode;
            }
        }else{
            return traverse(currentNode->hTable[nameHash], newNode, level);
        }
    }
}

void Content::insertNodeStruct(){
    cout<<"Select:"<<endl;
    cout<<"1 - Linked list"<<endl;
    cout<<"2 - Binary tree"<<endl;
    cout<<"3 - Hash table"<<endl;
    string strchoice;
    getline(cin,strchoice);
    int addType = -1;
    addType = atoi(strchoice.c_str());
    cout<<"Give it a name: ";
    string addName;
    getline(cin,addName);
    int addOption = 1;
    if(addType==4){
        cout<<"Size of hash table: ";
        getline(cin,strchoice);
        addOption = atoi(strchoice.c_str());
    }
    Node* addNode = new Node(addType,addName,addOption);
    Node* targetNode = new Node;
    targetNode = traverse(root,addNode,1);
    /*cout<<"Confirming selection..."<<endl;
    cout<<parentNode->name<<endl;
    targetNode = traverse(parentNode,addNode,1);
    if(parentNode->nextRight==targetNode){
        parentNode->nextRight=addNode;
    }
    if(parentNode->nextLeft==targetNode){
        parentNode->nextLeft=addNode;
    }
    if(parentNode->type==4){
        for(int i=0;i<parentNode->option;i++){
            if(parentNode->hTable[i]==targetNode){
                parentNode->hTable[i] = addNode;
            }
        }
    }
    targetNode = addNode; */
}

void Content::insertNodeData(){ // essentially a shortcut to just quickly add something to the list. just makes a singly linked list element
    cout<<"Give it a name: ";
    string addName;
    getline(cin,addName);
    Node* addNode = new Node(1,addName,1);
    Node* targetNode = new Node;
    targetNode = traverse(root,addNode,1);
    targetNode = addNode;
}

void Content::deleteNode(){
    Node* parentNode = new Node;
    Node* targetNode = new Node;
    Node* newNode = new Node;
    parentNode = traverse(root,newNode,0);
    cout<<"Confirm selection."<<endl;
    targetNode = traverse(parentNode,newNode,1);
    if(parentNode->nextLeft==targetNode){
        parentNode->nextLeft = NULL;
    }
    if(parentNode->nextRight==targetNode){
        parentNode->nextRight = NULL;
    }
    if(parentNode->type==4){
        for(int i=0;i<parentNode->option;i++){
            if(parentNode->hTable[i]==targetNode){
                parentNode->hTable[i] = NULL;
            }
        }
    }
    delete targetNode;
}
