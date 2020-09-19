#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (q == NULL)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (q == NULL)
        return;
    // if head exists, we keep on searching

    while (q->head) {
        // Update tmp by head
        list_ele_t *tmp = q->head;
        q->head = q->head->next;
        free(tmp->value);
        free(tmp);
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    /* TODO: What should you do if the q is NULL? */
    /* What if either call to malloc returns NULL? */
    if (q == NULL) {
        return false;
    }

    // New head to be allocated memory
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) {
        return false;
    }

    /* Don't forget to allocate space for the string and copy it */
    // Allocate space for string to checok
    int length = strlen(s) + 1;
    newh->value = malloc(sizeof(char) * (length));
    if (newh->value == NULL) {
        free(newh);
        return false;
    }
    // Copy from the source to the newly allocated space
    strncpy(newh->value, s, length);

    newh->next = q->head;
    // Move head in front of newh
    q->head = newh;
    // If No any element
    if (q->tail == NULL) {
        q->tail = newh;
    }
    // Queue size grows, thus plus one
    q->size++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) {
        return false;
    }

    // New head to be allocated memory
    list_ele_t *newt;  // newt represents new tail
    newt = malloc(sizeof(list_ele_t));
    if (newt == NULL) {
        return false;
    }

    /* Don't forget to allocate space for the string and copy it */
    // Allocate space for string to checok
    int length = strlen(s) + 1;
    newt->value = malloc(sizeof(char) * (length));
    if (newt->value == NULL) {
        free(newt);
        return false;
    }
    // Copy from the source to the newly allocated space
    strncpy(newt->value, s, length);
    // Set this element to the last one
    newt->next = NULL;
    // See if the queue is empty or not. If yes, the head is the new tail, if
    // not, put the new tail in the next of the original tail
    if (q->size == 0) {
        q->head = newt;
    } else {
        q->tail->next = newt;
    }
    // Move q->tail to newt
    q->tail = newt;

    // Queue size grows, thus plus one
    q->size++;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q == NULL || q->head == NULL) {
        return false;
    }
    list_ele_t *tmp = q->head;
    // If sp is not NULL copy the string to sp
    if (sp != NULL) {
        snprintf(sp, sizeof(bufsize), "%s", tmp->value);
    }
    // Update head to next node
    q->head = q->head->next;
    free(tmp->value);
    free(tmp);
    // Minus one in aize
    q->size--;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
