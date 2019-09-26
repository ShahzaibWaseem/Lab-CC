#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 10

int size=0;

typedef struct node{
	char *value;
	struct node *left, *right;
} treeNode;

void insertLeftNode(treeNode *, char *);
void insertRightNode(treeNode *, char *);
void postOrderTraversal(treeNode *);

int main(int argc, char const *argv[]){
	treeNode *parseTree = malloc(sizeof(treeNode));
	parseTree->value="";
	parseTree->left=NULL;
	parseTree->right=NULL;

	return 0;
}

void insertLeftNode(treeNode *parseTree, char *term){
	if (parseTree->left == NULL){
        parseTree->value = term;
        parseTree->left = parseTree->value;
    }
    else{
        struct node *insNode = {term, NULL, NULL};
        insNode->left = parseTree->left;
        parseTree->left = insNode;
    }
}

void insertRightNode(treeNode *parseTree, char *term){
	if (parseTree->right == NULL){
        parseTree->value = term;
        parseTree->right = parseTree->value;
    }
    else{
        struct node *insNode = {term, NULL, NULL};
        insNode->right = parseTree->right;
        parseTree->right = insNode;
    }
}

void postOrderTraversal(treeNode *parseTree){
    while(parseTree != NULL){
        postOrderTraversal(parseTree->left);
        postOrderTraversal(parseTree->right);
        printf("%s\n", parseTree->value);
    }
}