#include "main.h"

/**
 * executable - Execute a file if it has executable permissions
 * @path_file: Path to the executable file
 */
void executable(char *path_file)
{
	char *argv[WORDS] = {NULL};
	int status;
	pid_t child;

	child = fork();
	argv[0] = path_file;

	if (child == -1)
	{
		perror("Fail Fork\n");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (access(path_file, X_OK) == 0)
		{
			execve(path_file, argv, NULL);
			perror("Execve Error");
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("File not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("WAIT ERROR");
		}
	}
}
