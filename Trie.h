#ifndef _Trie_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CASE 'a'
#define ALPHABET 26


typedef enum {FALSE = 0, TRUE = 1} boolean;
//structor for Node:
typedef struct Node {
   boolean Word ;
   long unsigned int counter;
   struct Node* parent;
   struct Node* children[ALPHABET];

}Node;

Node* newNode();
void addNode(Node* tree, char* word);
void  print_Trie(Node* root, char str[], int level);
void  print_Trie_Reverse(Node* root, char str[], int level);
void freeTrie(Node* root);
boolean checkChar(char* c);

#endif
