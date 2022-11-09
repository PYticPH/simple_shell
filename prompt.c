#include "shell.h"

/**
 * prompt - Function to display shell prompt screen
 */

void prompt(void)
{
	char *linePtr = NULL;
	int line = 0;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(&linePtr, &len, stdin);
		if (line == -1)
		{
			free(linePtr);
			perror("Error: \n");
			exit(-1);
		}

		write(STDOUT_FILENO, linePtr, line);
		free(linePtr);
		linePtr = NULL;
	}
}
