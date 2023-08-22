#include "main.h"

char **token_input(char *input)
{
	char *split = NULL;
	char **tokens = NULL;
	char *input_copy = NULL;
	int index = 0;
	int nbr_tokens = 0;
	
	if (input == NULL)
	{
        	return NULL;
	}

	input_copy = malloc(strlen(input) + 1);
	strcpy(input_copy, input);

	split = strtok(input_copy, " ");

	while(split != NULL)
	{
		nbr_tokens++;
		split = strtok(NULL, " ");
	}
	free(input_copy);
	
	tokens = malloc(sizeof(char *) * (nbr_tokens + 1));

	if (tokens == NULL)
	{
		return(NULL);
	}

	split = strtok(input, " ");
	while (split != NULL)
	{
		tokens[index] = malloc(strlen(split) + 1);
		strcpy(tokens[index], split);
		index++;
		split = strtok(NULL, " ");
	}
	tokens[index] = NULL;
	return (tokens);
}
