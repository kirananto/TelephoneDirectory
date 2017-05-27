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
	int count;
        if((abl = createAddressBookList()))
        {
            char parsedLine[MAX_LINE_LENGTH];
            while (fgets(parsedLine, MAX_LINE_LENGTH, data) != NULL)
            {
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
            abl -> current = abl -> head; /* Printing all data from AddressBookList object */
            while((abn = abl -> current))
            {
                /*printf("%d - %s\n", abn -> id, abn -> name);*/
                for(j = 0; j < (abn -> array -> size) ; j++)
                {
                   /*printf(" - %s\n", abn -> array -> telephones[j]);*/
                }
                abl -> current = abl -> current -> nextNode;
            }
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
	
}

void commandForward(AddressBookList * list, int moves)
{ }

void commandBackward(AddressBookList * list, int moves)
{ }

void commandInsert(AddressBookList * list, int id, char * name, char * telephone)
{ }

void commandAdd(AddressBookList * list, char * telephone)
{ }

void commandFind(AddressBookList * list, char * name)
{ }

void commandDelete(AddressBookList * list)
{ }

void commandRemove(AddressBookList * list, char * telephone)
{ }

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
{ }
