#include "addressbook.h"

/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
*
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/
char line [128];
char *pch;
char words[6][20]; // 6 words, 20 characters
int x;
AddressBookList a;
int main(int argc, char ** argv)
{
    // ----------------------------Format-------------------------------
    // -----------------------------------------------------------------
    // Student name: Firstname Lastname
    // Student number: 1234567
    // Advanced Programming Techniques, Assignment Two, Semester 1, 2017
    // -----------------------------------------------------------------
    printf("-----------------------------------------------------------------\n");
    printf("Student name: Ashish John\n");
    printf("Student number: s3624455\n");
    printf("Advanced Programming Techniques, Assignment Two, Semester 1, 2017\n");
    printf("----------------------------------------------------------------- \n");
    do
    {
      printf("Enter your command : ");
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
           pch = strtok (line," ");
           while (pch != NULL)
           {
              strcpy(words[x], pch);
              pch = strtok (NULL, " ");
           }
           x++;

          /*
             At this point, the array "words" has all the words in the line
           */

        }
        if(strcmp(words[0],COMMAND_LOAD) {
            printf("> Opening the file %s\n",words[1]);
            printf("%s\n",words[1]);
            //  a = commandLoad(words[1]);
        }
    } while(words[0] != NULL && strcmp(words[0],COMMAND_QUIT));
    printf("> Goodbye. \n\n");
    return EXIT_SUCCESS;
}
