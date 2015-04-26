#include "Content.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Content()

   Constructor. Creates a root node on start.

   Pre-condition: Nothing. Expected to be run at start of program.
   Post-condition: There is now a root node.
*/
Content::Content(){
    Node* newRoot = new Node(1,"root",1);
    root = newRoot;
};

/* ~Content()

   Destructor.

   Pre-condition: A content class exists.
   Post-condition: The content class is no longer present.
*/
Content::~Content(){};


/* getHash(string)

   Generates a hash based on the algorithm from Assignment 9. Used for when the user adds a hash table to the main structure
   and we need to work with it.

   Ex. getHash("potato");

   Pre-condition: Given a valid string.
   Post-condition: Returns the generated hash.
*/
int Content::getHash(string in_title){ // from lecture notes
    int sum = 0;
    for(int i = 1;i<in_title.length();i++){ // sum up ascii values then mod by 10 to get the hash
        sum = sum + in_title[i];
    }
    sum = sum % 10;
    return sum;
}
/* traverse(Node*, Node*, int)

   Traverses the entire structure. Recurses down until it finds an empty point. Level indicates if it
   returns the parent or the target node.

   Ex.
   With structure of linked list elements (root)-->(bob)-->(fred) previously created...

   Node* newNode = new Node;
   Node* targetNode = new Node;
   traverse(targetNode, newNode, 1);

   Pre-condition: Given two Node*, the first being where we start searching, the second being a potential one to add, and
                  then an integer of 1 or 0, denoting what traverse() should return. (1 means the new node, 0 means the parent)
   Post-condition: New node is put wherever traverse() eventually reaches. The parent or new node is returned, based on the integer.
*/
Node* Content::traverse(Node* currentNode, Node* newNode, int level){
    if(currentNode->type==1){ // if linked list
        if(currentNode->nextRight==NULL){ // if we're at end of linked list
            currentNode->nextRight = newNode; // return
            if(level==1){
                return currentNode->nextRight;
            }else{
                return currentNode;
            }
        }else{ // or, keep going down
            cout<<"Traversing down linked list " << currentNode->name << "..."<<endl;
            return traverse(currentNode->nextRight, newNode, level);
        }
    }
    if(currentNode->type==2){ // if binary tree
        if(currentNode->nextRight==NULL and currentNode->nextLeft==NULL){ // if empty, just default to the right and keep going
            cout<<"Traversing empty binary tree "<< currentNode->name<<"..."<<endl;
            currentNode->nextRight = newNode;
            if(level==1){
                return currentNode->nextRight;
            }else{
                return currentNode;
            }
        }else{ // or, let the user choose. This isn't a BST, so the user gets to pick.
            cout<<"Found binary tree "<< currentNode->name <<", select branch:"<<endl; // give relevant info to user
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
            getline(cin,strchoice); // they choose one
            int choice = -1;
            choice = atoi(strchoice.c_str());
            if(choice==1){ // then either continue down or return whatever they chose
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
    if(currentNode->type==3){ // if hash table
        int nameHash = getHash(newNode->name); //get hash
        cout<<"Traversing down hash table " << currentNode->name << "..."<<endl;
        if(currentNode->hTable[nameHash]==NULL){ // if empty, return
            currentNode->hTable[nameHash] = newNode;
            if(level==1){
                return currentNode->hTable[nameHash];
            }else{
                return currentNode;
            }
        }else{ // else keep going
            return traverse(currentNode->hTable[nameHash], newNode, level);
        }
    }
    return NULL; // should never happen, but if something breaks and we get a unusable type, return NULL
}

/* insertNodeStruct()

   Inserts a node of some structure type into the main structure.

   Ex. insertNodeStruct(), selecting (1 - Linked list), then entering (foobar) will insert a linked list item called foobar.

   Pre-condition: There exists some main structure starting at root.
   Post-condition: A user-defined structure is added to that structure.
*/
void Content::insertNodeStruct(){ // ask user for what structure they want
    cout<<"Select:"<<endl;
    cout<<"1 - Linked list"<<endl;
    cout<<"2 - Binary tree"<<endl;
    cout<<"3 - Hash table"<<endl;
    string strchoice;
    getline(cin,strchoice);
    int addType = -1;
    addType = atoi(strchoice.c_str());
    cout<<"Give it a name: "; // get a name
    string addName;
    getline(cin,addName);
    int addOption = 1;
    if(addType==4){
        cout<<"Size of hash table: "; // if hash table, get the size.
        getline(cin,strchoice);
        addOption = atoi(strchoice.c_str());
    }
    Node* addNode = new Node(addType,addName,addOption); // make the node
    Node* targetNode = new Node;
    targetNode = traverse(root,addNode,1); // traverse to put in the node
}

/* insertNodeData()

   A simplified version of insertNodeStruct... inserts a linked list into the main structure. Lowers the number of user inputs
   significantly.

   Ex. insertNodeData(), then entering (foobar) will insert a linked list item called foobar.

   Pre-condition: There exists some main structure starting at root.
   Post-condition: A user-defined linked list element is added to that structure.
*/
void Content::insertNodeData(){ // essentially a shortcut to just quickly add something to the list. just makes a linked list element
    cout<<"Give it a name: ";
    string addName;
    getline(cin,addName);
    Node* addNode = new Node(1,addName,1);
    Node* targetNode = new Node;
    targetNode = traverse(root,addNode,1);
    targetNode = addNode;
}

/* deleteNode()

   Deletes a node in the list based on a traverse.

   Ex. deleteNode(), then traversing to some linked list with next as null. It is removed.

   Pre-condition: There exists some main structure starting at root.
   Post-condition: A user-defined element in the structure with no dependent nodes is removed.
*/
void Content::deleteNode(){
    Node* parentNode = new Node;
    Node* targetNode = new Node;
    Node* newNode = new Node;
    parentNode = traverse(root,newNode,0); // traverse to what we're deleting
    cout<<"Confirm selection."<<endl;
    targetNode = traverse(parentNode,newNode,1); // doubles as both confirming a selection and to get additional information to cleanly delete
    if(parentNode->nextLeft==targetNode){ //then, search everywhere where the target node could be (we have a lot of potential structures, so there's a bit to check)
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
    delete targetNode; // then finally delete
}

/* changeName()

   Uses a traverse to change the name of a node.

   Ex. changeName(), then entering "bar", traversing to some linked list named "foo". It will be changed to "bar".

   Pre-condition: There exists some main structure starting at root.
   Post-condition: A user-defined element in the structure's name is changed.
*/
void Content::changeName(){
    cout<<"Give it a name: ";
    string addName;
    getline(cin,addName);
    Node* newNode = new Node;
    Node* targetNode = new Node;
    targetNode = traverse(root,newNode,0); //traverse to the node, then change its name
    targetNode->name = addName;
    if(targetNode->nextLeft==newNode){ // remove the new node added to the structure
        targetNode->nextLeft = NULL;
    }
    if(targetNode->nextRight==newNode){
        targetNode->nextRight = NULL;
    }
    if(targetNode->type==4){
        for(int i=0;i<targetNode->option;i++){
            if(targetNode->hTable[i]==newNode){
                targetNode->hTable[i] = NULL;
            }
        }
    }
    delete newNode;
}

/* checkHash()

   Checks the hash of some string.

   Ex. checkHash(), then entering some string.

   Pre-condition: Nothing, though the user is expected to input a string.
   Post-condition: The hash is returned via cout.
*/
void Content::checkHash(){
    cout<<"Enter a string: ";
    string addName;
    getline(cin,addName);
    cout<<"Hash is "<<getHash(addName)<<endl;
}

/* doTraverse()

   Performs a traverse without affecting the structure.

   Ex. doTraverse()

   Pre-condition: There exists some main structure starting at root.
   Post-condition: The state remains unchanged.
*/
void Content::doTraverse(){
    Node* newNode = new Node;
    Node* targetNode = new Node;
    targetNode = traverse(root,newNode,0); // traverse, then wipe the new node added by it
    if(targetNode->nextLeft==newNode){
        targetNode->nextLeft = NULL;
    }
    if(targetNode->nextRight==newNode){
        targetNode->nextRight = NULL;
    }
    if(targetNode->type==4){
        for(int i=0;i<targetNode->option;i++){
            if(targetNode->hTable[i]==newNode){
                targetNode->hTable[i] = NULL;
            }
        }
    }
    delete newNode;
}
