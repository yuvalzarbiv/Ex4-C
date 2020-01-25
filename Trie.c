#include "Trie.h"



//initiate Node:
Node* newNode(){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("malloc failed");
    }
    newNode -> Word = FALSE;
    newNode -> counter = 0;
    newNode -> parent = NULL;
    for (int i=0;i<ALPHABET;i++){
        newNode -> children[i] = NULL;
    }
    return newNode;
}

void addNode(Node* tree, char* word){
   if (checkChar(word)){
    Node* currentNode = tree;
    while (*word != '\t' &&*word != '\0'&& *word != '\n' && *word != ' ')
{
        if ((*word >= 65 && *word <= 90) || (*word >= 97 && *word <= 122))
	{  
            *word = tolower(*word);
            if (currentNode -> children[*word - CASE] == NULL)
		{
            currentNode -> children[*word - CASE] = newNode();
            currentNode -> children[*word - CASE] -> parent = currentNode;
            }
            currentNode = currentNode -> children[*word - CASE];
        }
        word++;
    }
    currentNode -> counter++;
    currentNode -> Word = TRUE;
   }
}

void  print_Trie(Node* root, char str[], int level){
    
    if (root -> Word){
        str[level] ='\0';
        printf("%s", str);
        printf(" %lu\n", root -> counter);
    }
    int i;
    for(i = 0; i < ALPHABET; i++){
        if (root -> children[i]){
            str[level] = i + 'a';
             print_Trie((root -> children[i]),str,level + 1);
        }
    }
}

void  print_Trie_Reverse(Node* root, char str[], int level){
    
    if (root -> Word){
        str[level] ='\0';
        printf("%s", str);
        printf(" %lu\n", root -> counter);
    }
    int i;
    for(i = ALPHABET-1; i >= 0; i--){
        if (root -> children[i]){
            str[level] = i + 'a';
             print_Trie_Reverse((root -> children[i]),str,level + 1);
        }
    }
}
void freeTrie(Node* root){
    for (int i = 0; i < ALPHABET; i++ ){
        if(root -> children[i] != NULL){
            freeTrie(root -> children[i]);
        }
    }
    if (root != NULL){
        free(root);
    }
}
//checks if the letter is a valid one (from a-z)
boolean checkChar(char* c){
    if (*c != '\0' && *c != '\t' && *c != '\n' && *c != ' ' && *c != '_'){
        //if (*c>= 65 && *c <= 122){
            return TRUE;
      //  }
    }
    return FALSE;
}
