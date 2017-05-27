#include "addressbook_list.h"

/**
* Note this file is *NOT* to contain console output,
* meaning printf's are *NOT* to be present in this file.
*/

AddressBookList * createAddressBookList()
{
    /**
    * Allocates and initialises a new AddressBookList.
    * malloc or calloc are expected to be used to create the
    * AddressBookList memory.
    * 
    * If memory cannot be allocated for the list NULL is returned.
    * 
    * Note head, tail and current should all be initialised to NULL.
    */

    AddressBookList *abl;
    if((abl = malloc(sizeof(AddressBookList))))
    {
       abl -> size = 0;
       abl -> head = abl -> tail = abl -> current = NULL;
       return abl;
    }
    return NULL;
}

void freeAddressBookList(AddressBookList * list)
{
    /**
     * Free's all nodes within the list and the AddressBookList itself.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     */

    AddressBookNode *abn, *next;
    abn = list -> head;
    while(abn)
    {
        next = abn -> nextNode;
        free (abn);
        abn = next;
    }
}

AddressBookNode * createAddressBookNode(int id, char * name)
{
    /**
    * Allocates and initialises a new AddressBookNode.
    * malloc or calloc are expected to be used to create the
    * AddressBookNode memory.
    * 
    * Note the array of the node should also be created and initialised,
    * which should be done with the createAddressBookArray(...) function.
    * 
    * If memory cannot be allocated for the node or array NULL is returned.
    * 
    * Note previousNode and nextNode should both be initialised to NULL.
    */

    AddressBookNode *abn;
    if((abn = malloc(sizeof(AddressBookNode))))
    {
       abn -> id = id;
       strcpy(abn -> name, name);
       if((abn -> array = createAddressBookArray()))
       {
            abn -> previousNode = abn -> nextNode = NULL;
            return abn;
       }
    }
    return NULL;
}

void freeAddressBookNode(AddressBookNode * node)
{
    /**
    * Free's the array within the node and the AddressBookNode itself.
    * 
    * Note the freeAddressBookArray(...) function is used to free the array.
    */

    freeAddressBookArray(node -> array);
    free(node);
}

Boolean insertNode(AddressBookList * list, AddressBookNode * node)
{
    /**
     * Inserts the node into the list and returns TRUE.
     * 
     * If the list already contains a node with the same id
     * then FALSE is returned and the node is not inserted.
     */

    /* TODO - Check if node with same id exists */
    if(list -> head == NULL)
    {
        list -> head = list -> tail = list -> current = node;
        node -> previousNode = node -> nextNode = NULL;
        return TRUE;
    }
    else
    {
        list -> tail -> nextNode = node;
        node -> previousNode = list -> tail;
        list -> tail = list -> tail -> nextNode;
        return TRUE;
    }
    return FALSE;
}

Boolean deleteCurrentNode(AddressBookList * list)
{
    /**
     * Delete's and free's the current node in the list and returns TRUE.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     * 
     * If the list has no nodes (i.e., there is no current node)
     * then FALSE is returned.
     */
    
    return FALSE;
}

Boolean forward(AddressBookList * list, int forward)
{
    /**
     * Moves the current node forward in the list by the number provided
     * and returns TRUE.
     * 
     * If the current node cannot be moved forward by that many positions
     * then FALSE is returned and current remains unchanged.
     */

    AddressBookNode *abn = list -> current;
    int i;
    if(list == NULL)
        return FALSE;
    else
    {
        for (i = 0; i < forward; i++)
            if(abn -> nextNode)
                abn = abn -> nextNode;
            else
                return FALSE;
        list -> current = abn;
        return TRUE;
    }
    return FALSE;
}

Boolean backward(AddressBookList * list, int backward)
{
    /**
    * Moves the current node backward in the list by the number provided
    * and returns TRUE.
    * 
    * If the current node cannot be moved backward by that many positions
    * then FALSE is returned and current remains unchanged.
    */

    AddressBookNode *abn = list -> current;
    int i;
    if(list == NULL)
        return FALSE;
    else
    {
        for (i = 0; i < backward; i++)
            if(abn -> previousNode)
                abn = abn -> previousNode;
            else
                return FALSE;
        list -> current = abn;
        return TRUE;
    }
    return FALSE;
}

AddressBookNode * findByID(AddressBookList * list, int id)
{
    /**
     * Returns the node that matches the id provided.
     * 
     * If no node with a matching id exists then NULL is returned.
     */

    return NULL;
}

AddressBookNode * findByName(AddressBookList * list, char * name)
{
    /**
    * Sets current to the first node that matches the name provided
    * and returns this node.
    * 
    * If no node with a matching name exists then NULL is returned
    * and current remains unchanged.
    */

    return NULL;
}
