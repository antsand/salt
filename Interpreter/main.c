#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <string.h>

/* document for using queue
   https://linux.die.net/man/3/queue
   http://www.manpagez.com/man/3/queue/
   http://infnis.wikidot.com/list-from-sys-queue-h

   file is located at: /usr/include/x86_64-linux-gnu/sys/queue.h 
    
*/

struct listhead *headp;                 /* List head. */
struct entry {
    char node[10];
    LIST_ENTRY(entry) entries;          /* List. */
//    ...
} *n1, *n2, *np;

void main() {
LIST_HEAD(listhead, entry) head;

LIST_INIT(&head);                       /* Initialize the list. */

n1 = malloc(sizeof(struct entry));      /* Insert at the head. */
strncpy(n1->node, "Node 1", 10);
LIST_INSERT_HEAD(&head, n1, entries);

n2 = malloc(sizeof(struct entry));      /* Insert after. */
strncpy(n2->node, "Node 2", 10);
LIST_INSERT_AFTER(n1, n2, entries);
                                        /* Forward traversal. */
for (np = head.lh_first; np != NULL; np = np->entries.le_next) {
    printf("This is %s \n", np->node);
    //np-> ...
}

//LIST_FOREACH(np, &head, entries);

    while (head.lh_first != NULL)    {       /* Delete. */
        printf("Removing %s \n", head.lh_first->node);
        LIST_REMOVE(head.lh_first, entries);
    }
    free(n1);
    free(n2);
}
