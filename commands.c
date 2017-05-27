#include "commands.h"

/**
 * Note this file is to contain console output,
 * meaning printf's are expected to be seen in this file.
 */

AddressBookList * commandLoad(char * fileName)
{
    /**
     * Loads the given file and returns a new AddressBookList.
     *
     * If the file doesn't exist or corruption is found in the file
     * then NULL is returned.
     */

    int i, j;
    FILE *data;
    printf("> Loading the file ... \n");
    if((data = fopen(fileName, "r")))
    {
        AddressBookList *abl;
        AddressBookNode *abn;
        int count = 0;
        if((abl = createAddressBookList()))
        {
            char parsedLine[MAX_LINE_LENGTH];
            while (fgets(parsedLine, MAX_LINE_LENGTH, data) != NULL)
            {
                if(parsedLine[strlen(parsedLine) - 1] == '\n') /* To remove '\n' character from string */
                    parsedLine[strlen(parsedLine) - 1] = '\0';
                if(parsedLine[0]=='#')
                    continue;
                else
                {
                    char *getId = strtok(parsedLine, ", ");
                    char *getName = strtok(NULL, ", ");
                    char *getTelephone[20];
                    count++;
                    i = 0;
                    while((getTelephone[i] = strtok(NULL, ", ")) != NULL)
                        i++;
                    if((abn = createAddressBookNode(atoi(getId), getName)))
                    {
                        for(j = 0; j <i ; j++)
                        {
                            addTelephone(abn -> array, getTelephone[j]);
                        }
                        insertNode(abl, abn);
                    }
                }
            }
            fclose(data);
            /* printf("\n\nFROM STRUCTURE OBJECT\n\n"); */
            
	    printf("> %d Phone book entries have been loaded from the file \n",count);
            return abl;
        }
        fclose(data);
        return NULL;
    }
    else
    {
        /*printf("> Error: The specified file is in the wrong format and cannot be loaded.\n");*/
        printf("> Error: File not found\n");
    }
    return NULL;
}

void commandUnload(AddressBookList * list)
{
    freeAddressBookList(list);
    printf("Successfully Unloaded\n");
}

void commandDisplay(AddressBookList * list)
{
    AddressBookNode *abn = NULL;
	int i = 1, j;
	printf("\n-------------------------------------------------------");
	printf("\n| Pos |  Serial  |   ID   |    Name    |  Telephones  |");
    printf("\n-------------------------------------------------------");
	if(list != NULL) /* Printing all data from AddressBookList object */
        abn = list -> head;
    while(abn != NULL)
    {
        if(abn == list -> current)
            printf("\n| CUR |");
        else
            printf("\n|     |");  
        printf(" %8d | %6d | %10s | ",i, abn -> id, abn -> name);
        for(j = 0; j < (abn -> array -> size); j++)
            printf("%s, ", abn -> array -> telephones[j]); /* Print telephone numbers with commas */
        if(abn -> array -> size > 0)
            printf("\b\b  "); /* Erase the last comma */
        abn = abn -> nextNode;
		i++;
    }
    printf("\n-------------------------------------------------------");
    printf("\n|\t Total no of book entries : %4d\t      |", i - 1);
    printf("\n-------------------------------------------------------\n\n");
}

void commandForward(AddressBookList * list, int moves)
{
    if(list == NULL)
        printf("\n> No file loaded\n");
    else if(!forward(list, moves))
        printf("\n> Can't forward out of bounds\n");
}

void commandBackward(AddressBookList * list, int moves)
{
    if(list == NULL)
        printf("\n> No file loaded\n");
    else if(!backward(list, moves))
        printf("\n> Can't backward out of bounds\n");
}

void commandInsert(AddressBookList * list, int id, char * name, char * telephone)
{
    if(list == NULL)
        printf("\n> File not loaded\n");
    else
    {
        AddressBookNode *abn;
        Boolean flag = TRUE;
        int i;
        if(id <= 0 || strlen(name) <= 0 || strlen(telephone) != TELEPHONE_LENGTH - 1)
            flag = FALSE;
        else
            for(i = 0; i < TELEPHONE_LENGTH - 1; i++)
                if(!isdigit(telephone[i]))
                    flag = FALSE;
        if(flag)
        {
            abn = createAddressBookNode(id, name);
            addTelephone(abn -> array, telephone);
            if(!insertNode(list, abn))
                printf("\n> Entry with same ID already exists\n");
        }
        else
            printf("\n> Invalid data entered\n");
    }
}

void commandAdd(AddressBookList * list, char * telephone)
{
    Boolean flag = TRUE;
    int i;
    if(list == NULL)
        printf("\n> File not loaded\n");
    else
    {
        if(strlen(telephone) != TELEPHONE_LENGTH - 1)
            flag = FALSE;
        else
            for(i = 0; i < TELEPHONE_LENGTH - 1; i++)
                if(!isdigit(telephone[i]))
                    flag = FALSE;
        if(flag)
        {
            if(!addTelephone(list -> current -> array, telephone))
                printf("\n> Number already exists\n");
        }
        else
            printf("\n> Wrong telephone number format\n");
    }
}

void commandFind(AddressBookList * list, char * name)
{
    AddressBookNode *abn = findByName(list, name);
    if(abn == NULL)
        printf("\n> Entry not found\n");
    else
        list -> current = abn;
}

void commandDelete(AddressBookList * list)
{
    if(!deleteCurrentNode(list))
        printf("\n> File not Loaded");
}

void commandRemove(AddressBookList * list, char * telephone)
{
    Boolean flag = TRUE;
    int i;
    if(list == NULL)
        printf("\n> File not loaded\n");
    else
    {
        if(strlen(telephone) != TELEPHONE_LENGTH - 1)
            flag = FALSE;
        else
            for(i = 0; i < TELEPHONE_LENGTH - 1; i++)
                if(!isdigit(telephone[i]))
                    flag = FALSE;
        if(flag)
        {
            if(!removeTelephone(list -> current -> array, telephone))
                printf("\n> Number doesn't exist\n");
        }
        else
            printf("\n> Wrong telephone number format\n");
    }
}

void commandSort(
    AddressBookList * list,
    int sort(const void * node, const void * otherNode))
{
    /* Sort the nodes within list in ascending order using the
     * provided sort function to compare nodes.
     */
}

int compareName(const void * node, const void * otherNode)
{
    /* Compare node name with otherNode name.
     *
     * return < 0 when node name is smaller than otherNode name.
     * return 0 when the names are equal.
     * return > 0 when node name is bigger than otherNode name.
     */
    return 0;
}

int compareID(const void * node, const void * otherNode)
{
    /* Compare node id with otherNode id.
     *
     * return < 0 when node id is smaller than otherNode id.
     * return 0 when the ids are equal.
     * return > 0 when node id is bigger than otherNode id.
     */
    return 0;
}

void commandSave(AddressBookList * list, char * fileName)
{
    FILE *data;
    char line[50];
    int i;
    if(list == NULL)
        printf("\n> File not loaded\n");
    printf("> Opening file ... \n");
    if((data = fopen(fileName, "w")))
    {
        AddressBookNode *abn = list -> head;
        printf("> Writing to file ... \n");
        while(abn != NULL)
        {
            sprintf(line, "%d,%s,", abn -> id, abn -> name);
            for(i = 0; i < (abn -> array -> size); i++)
            {
                strcat(line, abn -> array -> telephones[i]);
                strcat(line, ",");
            }
            line[strlen(line) - 1] = '\n';
            fputs(line, data);
            abn = abn -> nextNode;
        }
    }
    fclose(data);
}
