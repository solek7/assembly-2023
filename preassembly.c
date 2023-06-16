#include <stdio.h>
#include <stdlib.h>
#include "headers/nodes.h"
#include "headers/constants.h"

/**
 * @brief Create a Linked List From File object
 * 
 * @param file 
 * @return CodeNode* 
 */
CodeNode* createLinkedListFromFile(FILE* file) {
    char buffer[MAX_LINE_LEN + 1];
    CodeNode *head = NULL, *temp = NULL, *node = NULL;
    
    while(fgets(buffer, MAX_LINE_LEN + 1, file) != NULL) {
        /*Create a new node*/
        node = (CodeNode*)malloc(sizeof(CodeNode));
        if(node == NULL) {
            printf("Error allocating memory for new node.\n");
            return NULL;
        }
        
        /* Copy the string from buffer to the new node*/
        strncpy(node->code_row, buffer, MAX_LINE_LEN + 1);
        node->next = NULL;
        
        /* If this is the first node, it is the head of the list*/
        if(head == NULL) {
            head = node;
        } else {
            /* Otherwise, add the new node to the end of the list*/
            temp->next = node;
        }
        
        /* Move the temporary pointer to the new node*/
        temp = node;
    }
    
    return head;
}

/**
 * @brief frees all the memmory allocated to the linked list ( code rows)
 * 
 * @param head 
 */
void freeLinkedList(CodeNode* head) {
    CodeNode* tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

MacroNode* scanCodeForMacros(CodeNode* code) {
    
}