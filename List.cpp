//
// Created by wikto on 15.05.2022.
//
using namespace std;
#include "List.h"

List::List() {
    head = new List_element_t;
    tail = new List_element_t;
    head = NULL;
    tail = NULL;
};


void List::addLast( string key) {
    if (head == NULL) {
        head = new List_element_t;
        (head)->key = key;
        (head)->next = NULL;
        (head)->previous = NULL;
        tail = head;

    }
    else {
        List_element_t* element = tail;

        element->next = new List_element_t;
        element->next->key = key;
        element->next->next = NULL;
        element->next->previous = element;
        tail = element->next;
    }
}

void List::delete_last() {
    if (head->next == NULL) {
        head = NULL;
        tail = NULL;
    }
    else {
        List_element_t* element =  ( tail->previous);

       // cout << element->next->key << endl;
        free(element->next);
        element->next = NULL;
        tail = element;
    }
}

string List::get_elementKey(int number) {
    List_element_t* element = head;
    int count = 0;
    while (element != NULL) {
        if (count == number) {
            return element->key;

        }
        count++;
        element = element->next;
    }
    return "?";
}

void List::free_memory() {
        List_element_t* tmp;

        while (head!= NULL)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }

}

int List::get_elementAmount(int index) {
    List_element_t* element = head;
    int count = 0;
    while (element != NULL) {
        if (count == index) {
            return element->amount;

        }
        count++;
        element = element->next;
    }
    return -1;
}
void List::set_elementAmount(int index,int value){
    List_element_t* element = head;
    int count = 0;
    while (element != NULL) {
        if (count == index) {
            element->amount=value;

        }
        count++;
        element = element->next;
    }
}

int List::ifExistReturnIndex(string SKey) {
    List_element_t* element = head;
    int count = 0;
    while (element != NULL) {
        if (element->key==SKey) {
            return count;
        }
        count++;
        element = element->next;
    }
    return -1;
}






