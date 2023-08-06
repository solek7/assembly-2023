#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libs.h"

int main (int argc, char** argv) {
    CodeNode* code;
    Error error = NO_ERROR;
    LabelNode* labels = NULL;
    LabelNode* externals = NULL;
    short memory[MAX_MEMORY_SIZE];
    int memory_idx = MEMORY_INDEX;
    int DC, IC;
    int i;

    for (i = 1; i < argc; i++) {
        error = NO_ERROR;
        labels = NULL;
        memory_idx = MEMORY_INDEX;
        DC = IC = 0;

        code = preproccessor(argv[i], &error);
        if (error != NO_ERROR) continue;
        
        firstIteration(memory, &memory_idx, code, &labels, &DC, &IC, &error);
        if (error != NO_ERROR) continue;

        secondIteration(memory, &memory_idx, code, labels, &DC, &IC, &error, argv[i], externals);
        if (error != NO_ERROR) continue;
    }
    return 1;
}