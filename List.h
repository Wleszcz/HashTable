//
// Created by wiktoer on 15.05.2022.
//

#ifndef UNTITLED3_LIST_H
#define UNTITLED3_LIST_H

#include <string>

using namespace std;
struct List_element_t;

struct List_element_t {
    string key;
    int amount=0;
    List_element_t* next;
    List_element_t* previous;
};


class List {

private:
    List_element_t *head;
    List_element_t *tail;


public:

    List();

    string get_elementKey(int number);
    int get_elementAmount(int index);

    void addLast(string key);
    int ifExistReturnIndex(string key);
    void delete_last();
    void free_memory();

    int ifExist(string Skey);

    void set_elementAmount(int index, int value);
};



#endif //UNTITLED3_LIST_H
