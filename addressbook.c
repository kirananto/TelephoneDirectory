#include "addressbook.h"

/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
*
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/
char array_of_string[10][12]; /* 10 strings of a maximum of 11 characters each, plus the NUL */
char msg[50];
/* now split the msg and put the words in array_of_string */
int string_num = 0;
int word_size = 0;
int msg_index = 0;
int x;
AddressBookList *a = NULL;
int main(int argc, char ** argv)
{
  /** ----------------------------Format-------------------------------
    * -----------------------------------------------------------------
    * Student name: Firstname Lastname
    * Student number: 1234567
    * Advanced Programming Techniques, Assignment Two, Semester 1, 2017
    * -----------------------------------------------------------------
  */
    printf("-----------------------------------------------------------------\n");
    printf("Student name: Ashish John\n");
    printf("Student number: s3624455\n");
    printf("Advanced Programming Techniques, Assignment Two, Semester 1, 2017\n");
    printf("----------------------------------------------------------------- \n");
    if(argc == 2)
        a = commandLoad(argv[1]);
    do
    {
        printf("Enter your command : ");
        scanf(" %100[^\n]",msg);
        string_num=0;
        word_size=0;
        msg_index=0;
        while (msg[msg_index] != '\0') {
            if (msg[msg_index] != ' ') {
                /* add the character to the proper place in array_of_string */
                array_of_string[string_num][word_size] = msg[msg_index];
                /* and update word_size for next time through the loop */
                word_size++; /* needs check for reserved word size (5) */
            } else {
                /* a space! */
                /* first, terminate the current word */
                array_of_string[string_num][word_size] = '\0';
                /* prepare to start the next word */
                string_num++; /* needs check for reserved number of "strings" (10) */
                word_size = 0;
            }
            msg_index++;
        }
        array_of_string[string_num][word_size] = '\0';
        if(strcmp(array_of_string[0],COMMAND_LOAD)==0)
        {
            if(a != NULL)
                printf("> File already loaded in memory\n");
            else
            {
                printf("> Opening the file %s\n",array_of_string[1]);
                a = commandLoad(array_of_string[1]);
            }
        }
        else if(strcmp(array_of_string[0],COMMAND_UNLOAD)==0)
        {
            printf("> Unloading from memory...\n");
            commandUnload(a);
            a = NULL; /* To empty list */
        }
        else if(strcmp(array_of_string[0],COMMAND_DISPLAY)==0)
            commandDisplay(a);
        else if(strcmp(array_of_string[0],COMMAND_FORWARD)==0)
            commandForward(a, atoi(array_of_string[1]));
        else if(strcmp(array_of_string[0],COMMAND_BACKWARD)==0)
            commandBackward(a, atoi(array_of_string[1]));
        else if(strcmp(array_of_string[0],COMMAND_INSERT)==0)
        {
            int id;
            char *name, *telephone;
            strtok(msg, " ");
            id = atoi(strtok(NULL, ","));
            name = strtok(NULL, ",");
            telephone = strtok(NULL, "");
            commandInsert(a, id, name, telephone);
        }
        else
		  continue;
    } while(msg != NULL && strcmp(array_of_string[0],COMMAND_QUIT));
    printf("> Goodbye. \n\n");
    return EXIT_SUCCESS;
}
