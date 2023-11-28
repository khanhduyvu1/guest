#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "read_line.h"

struct guest *add_guest(struct guest *list) {
    char phone[PHONE_LEN+1];
    char last[NAME_LEN+1];
    char first[NAME_LEN+1];
    int party_size;
    struct guest *current = list;
    struct guest *new = (struct guest *)malloc(sizeof(struct guest));

    //enter phone number and check for if it exists or not
    printf("Enter phone number: ");
    scanf("%s", phone);
    while (current != NULL){
        if (strcmp(current->phone,phone)==0){
            printf("guest already exists.");
            free(new);
            return list;
        }
        current = current->next;
    }
    strcpy(new->phone,phone);
    //enter first and last name and party size
    printf("Enter guest's last name: ");
    read_line(last,NAME_LEN+1);
    strcpy(new->last,last);
    printf("Enter guest's first name: ");
    read_line(first,NAME_LEN+1);
    strcpy(new->first,first);
    printf("Enter party size: ");
    scanf("%d", &party_size);
    new->party_size = party_size;
    new->next = NULL;

// move to the end of the list
    if (list == NULL){
        return new;
    }
    else{
        current = list;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
        return list;
    }
}


struct guest *remove_guest(struct guest *list) {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN + 1);

    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN + 1);

    struct guest *current = list;
    struct guest *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0 && strcmp(current->last, last) == 0 &&
            strcmp(current->first, first) == 0) {
            if (prev == NULL) {
                list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return list;
        }
        prev = current;
        current = current->next;
    }
    printf("Guest does not exist.\n");
    return list;
}

void print_list(struct guest *list) {
    while (list != NULL) {
        printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
        list = list->next;
    }
}

void clear_list(struct guest *list) {
    struct guest *current = list;
    struct guest *next;
    //clear the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

