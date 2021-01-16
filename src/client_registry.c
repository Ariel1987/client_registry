/*
 ============================================================================
 Name        : client_registry.c
 Author      : ariel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "client_registry.txt"

typedef struct {
	char name[30];
	int yearOfBirth;
	float expenses;
}Registry;

int addClient();
int editAndShowList();
int growArray(Registry **clients, int currentSize, int numNewElems);
int arraySize();


int main(void) {

	int option;

	printf("**********Client Registry**********\n");
	printf("Choose one of the options\n");
	printf("1- Add client to list\n");
	printf("2- Read or edit clients' list\n");
	printf("Option: ");
	scanf("%d", &option);

	switch(option)
	{
	case 1:
		addClient();
		break;
	case 2:
		editAndShowList();
		break;
	default:
		printf("\nInexistent option\n");
	}
	return 0;
}

int addClient()
{
	FILE *fp = NULL;
	Registry * clients = (Registry *)calloc(10, sizeof(Registry));
	int i, size = 10;

	if (clients == NULL)
	{
		printf("It is not possible to allocate memory for data\n");
		exit(1);
	}
	size = growArray(&clients, size, 10);

	fp = fopen(FILENAME, "w");

	if (fp == NULL)
	{
		perror("Error opening file");
		return -1;
	}

	for (i = 0; i < size; i++)
	{
		printf("\nInsert client's name: ");
		scanf("%s", clients[i].name);
		printf("\nInsert client's birth year: ");
		scanf("%d", &clients[i].yearOfBirth);
		printf("\nInsert client's total expenses: ");
		scanf("%f", &clients[i].expenses);

		fprintf(fp, "%s %d %.2f\n", clients[i].name, clients[i].yearOfBirth, clients[i].expenses);
	}

	fclose(fp);
	fp = NULL;

	return 0;
}

int growArray(Registry **clients, int currentSize, int numNewElems)
{
	const int totalSize = currentSize + numNewElems;
	Registry *temp = (Registry*)realloc(*clients, totalSize * sizeof(Registry));

	if(temp == NULL)
	{
		printf("It is not possible to allocate more memory\n");
		return 0;
	}
	else
	{
		*clients = temp;
	}
	return totalSize;
}

int arraySize()
{
	FILE *fp = NULL;
	char ch;
	int linesCount = 0;

	fp = fopen(FILENAME, "r");

	if(fp == NULL)
	{
		printf("Inexistent file\n");
	}

	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
			linesCount++;
	}
	fclose(fp);
	fp = NULL;

	return linesCount;
}

int editAndShowList()
{
	FILE *fp = NULL;

	int size = arraySize();
	Registry clients[size];
	char token[121];
	char * item;
	int i = 0, option = 0;
	int client;
	float expense;

	fp = fopen(FILENAME, "r");

	if (fp == NULL)
	{
		perror("Error opening file");
		return -1;
	}

	while (fgets(token, 120, fp))
	{
		item = strtok(token, " ");
		strncpy(clients[i].name, item, sizeof(clients[i].name));

		item = strtok(NULL, " ");
		clients[i].yearOfBirth = atoi(item);

		item = strtok(NULL, " ");
		clients[i].expenses = atof(item);

		i++;
	}
	fclose(fp);
	fp = NULL;

	printf("Choose one of the options bellow\n");
	printf("1- Remove client or update his/her expenses\n");
	printf("2- Zero client's expenses\n");
	printf("3- Show best buyer\n");
	printf("4- Show a client's expenses\n");
	printf("Option: ");
	scanf("%d", &option);


	switch(option)
	{
	case 1:
		printf("**********List of Clients**********\n");
		for(i = 0; i < size; i++)
		{
			printf("%d- %s\n", i + 1, clients[i].name);
		}

		printf("Insert the client's number: ");
		scanf("%d", &client);

		printf("1- Delete client\n");
		printf("2- Update client's expenses\n");
		printf("Option: ");
		scanf("%d", &option);

		if(option == 1)
		{
			for(i = client; i < size; i++)
			{
				clients[i - 1] = clients[i];
			}
			size--;

			fp = fopen(FILENAME, "w");

			for(i = 0; i < size; i++)
			{
				fprintf(fp, "%s %d %.2f\n", clients[i].name, clients[i].yearOfBirth, clients[i].expenses);
			}
			fclose(fp);
			fp = NULL;
		}
		else if (option == 2)
		{
			printf("How much are the client's new expenses?: ");
			scanf("%f", &expense);
			for (i = 0; i < size; i++)
			{
				if (i + 1 == client)
				{
					clients[i].expenses = expense;
				}
			}
			fp = fopen(FILENAME, "w");

			for(i = 0; i < size; i++)
			{
				fprintf(fp, "%s %d %.2f\n", clients[i].name, clients[i].yearOfBirth, clients[i].expenses);
			}
			fclose(fp);
			fp = NULL;
		}
		else
		{
			printf("Invalid option");
		}
		break;

	case 2:
		for (i = 0; i < size; i++)
		{
			clients[i].expenses = 0.0;
		}
		fp = fopen(FILENAME, "w");

		for(i = 0; i < size; i++)
		{
			fprintf(fp, "%s %d %.2f\n", clients[i].name, clients[i].yearOfBirth, clients[i].expenses);
		}
		fclose(fp);
		fp = NULL;

		break;

	case 3:
		for (i = 0; i < size; i++)
		{
			if (clients[0].expenses < clients[i].expenses)
			{
				clients[0].expenses = clients[i].expenses;
				clients[0].yearOfBirth = clients[i].yearOfBirth;
				strncpy(clients[0].name, clients[i].name, 30);
			}
		}
		printf("%s %d %.2f\n", clients[0].name, clients[0].yearOfBirth, clients[0].expenses);
		break;

	case 4:
		printf("**********List of Clients**********\n");
		for(i = 0; i < size; i++)
		{
			printf("%d- %s\n", i + 1, clients[i].name);
		}
		printf("Insert client's number: ");
		scanf("%d", &client);

		printf("\n%s's expenses were: %.2f\n", clients[client - 1].name, clients[client - 1].expenses);

		break;

	default:
		printf("Invalid option\n");
	}

	return 0;
}
