#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libs.h"

void tokenizeInput(char *input, char **tokens, int *num_tokens);

void tokenizeInput(char *input, char **tokens, int *num_tokens) {
    size_t length = strlen(input);
    char *token = NULL;
    char *temp = NULL;
    temp = malloc((length + 1) * sizeof(char));
    strcpy(temp, input);  /* Copy input string into temp */

    token = strtok(temp, " ");
    *num_tokens = 0;
    while (token != NULL && *num_tokens < MAX_TOKENS) {
        tokens[*num_tokens] = my_strdup(token);  /* Duplicate and store token */
        (*num_tokens)++;
        token = strtok(NULL, " ");
    }

    free(temp);
}

char *my_strdup(const char *str) {
    size_t length = strlen(str);
    char *duplicate = malloc(length + 1);  /* Allocate memory for the duplicate string*/
    if (duplicate != NULL) {
        strcpy(duplicate, str);  /* Copy the string into the allocated memory*/
    }
    return duplicate;
}

void* allocateMemory(size_t size, Error* error) {
    void* ptr = calloc(1, size);
    if (ptr == NULL) {
        *error = ERROR_NO_MEMORY;
        handleError(error);
    }
    return ptr;
}

bool validateVariableName (char *name) {
    int i;

    for (i = 0; i < strlen(name); i++) {
        if (i == 0 && !isalpha(name[i])) {
            return false;
        }
        if ((name[i] >= 0 && name[i] <= 57) || (name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || (name[i] == 45)) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void handleError(Error* error) {

}