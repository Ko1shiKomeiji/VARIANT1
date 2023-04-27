#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funcs1.h"

int llength(node *head) {
    node *tmp = head;
    int len = 0;
    if (head == NULL) return 0;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
};

void lprint(node *head) {
    int i;
    node *tmp = head;
    printf("--- %4d ---\n", llength(head));
    if (head == NULL) {
        printf("[%p]\n", head);
        return;
    }
    while (tmp) {
        printf("[%14p]<-[%14p]->[%14p] ", tmp->prev, tmp, tmp->next);
        printf("data: [%f] s: [", tmp->data.f);
        for (i = 0; i < 2; i++)
            printf("%c", tmp->data.s[i]);
        printf("]\n");
        tmp = tmp->next;
    }
    printf("-----------\n");
};

node *add_head(node *head, struct Data *data) {
    node *new = NULL;
    if ((new = malloc(sizeof(node))) == NULL) {
        perror("malloc : NULL");
        exit(2);
    }
    if (data != NULL)
        memcpy(&(new->data), data, sizeof(struct Data));
    new->prev = NULL;
    if (head == NULL)
        new->next = head;
    else {
        new->next = head;
        head->prev = new;
    }
    return new;
};

node *reverse(node *head)
{
    if (head == NULL) return NULL;
    node *curr, *prev, *next = NULL;
    curr = head;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}