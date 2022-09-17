#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL, **tmp = NULL;
	int nread;
	size_t len = 0;
	unsigned long long int i, nbr;

	i = 2;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	nread = getline(&line, &len, stream);
	while (nread != -1)
	{
		i = 2;
		nbr = strtoull(line, tmp, 10);
		while (1)
		{
			if (nbr % i == 0)
			{
				printf("%llu=%llu*%llu\n", nbr, (nbr / i), i);
				break;
			}
			i++;
		}
		nread = getline(&line, &len, stream);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
