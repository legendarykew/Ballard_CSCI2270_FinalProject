#ifndef CONTENT_H
#define CONTENT_H

#include <string>

struct Node{
    std::string name = "INIT";
    int type = -1;
    int option = -1;
    Node *nextRight;
    Node *prev;
    Node *nextLeft;
    Node **hTable;

    Node(){};

    Node(int in_type, std::string in_name, int option)
    {
        type = in_type;
        name = in_name;
        if(type==1){ //singly linked list
            nextRight = NULL;
        }
        if(type==2){ //doubly linked list
            nextRight = NULL;
            prev = NULL;
        }
        if(type==3){ //binary tree
            nextRight = NULL;
            nextLeft = NULL;
        }
        if(type==4){
            hTable = new Node*[option]; // hash table
            for (int i = 0;i<option;i++){
                hTable[i] = NULL;
            }
        }
    }
};

class Content
{
    public:
        Content();
        ~Content();
        Node* traverse(Node* currentNode, Node* newNode, int level);
        void insertNodeStruct();
        void insertNodeData();
        void deleteNode();
        int getHash(std::string in_title);
        void changeName();
        void checkHash();
        void doTraverse();
    protected:
    private:
        Node* root;
};

#endif // HASHTABLE_H
