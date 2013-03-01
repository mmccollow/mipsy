#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "mem.h"

FILE *binfile;

/**
 * Loads a binary file into memory
 */
void load(char *filename) {
	binfile = fopen(filename, "r");
	if (sizeof(binfile) > sizeof(mainMemory)) {
		fprintf(stderr, "Insufficient memory.");
		fclose(binfile);
		exit(EXIT_FAILURE);
	}
	fread(mainMemory, sizeof(u32), sizeof(binfile) / 4, binfile);
	fclose(binfile);
}

