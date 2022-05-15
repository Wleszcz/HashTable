#include <iostream>
#include <string.h>
#include "List.h"


int hashWord(string word);

using namespace std;

#define HASH_LENGTH 1000


int main() {
    List hashTable[HASH_LENGTH];
    string word;
    while (cin>>word){
        if(word[0]=='?'){
            word.erase(word.begin());
            int index = hashWord(word);
            int listIndex=hashTable[index].ifExistReturnIndex(word);
            if(listIndex==-1){
                cout<<0<<endl;
            }
            else{
                cout<<hashTable[index].get_elementAmount(listIndex)<<endl;
            }
        }
        else if(word[0]=='-'){
            word.erase(word.begin());
            int index = hashWord(word);
            int listIndex=hashTable[index].ifExistReturnIndex(word);
            if(listIndex!=-1){
                hashTable[index].set_elementAmount(listIndex,0);
            }
        }
        else if(word[0]=='q'){
            for (int i = 0; i < HASH_LENGTH; i++) {
                hashTable[i].free_memory();
            }
            return 0;
        }
        else{
            int index = hashWord(word);
            int listIndex=hashTable[index].ifExistReturnIndex(word);
            if(listIndex==-1){
                hashTable[index].addLast(word);
                hashTable[index].set_elementAmount(hashTable[index].ifExistReturnIndex(word),1);
            }
            else{
                int amount = hashTable[index].get_elementAmount(listIndex)+1;
                hashTable[index].set_elementAmount(listIndex,amount);
            }
        }

    }
}

int hashWord(string word) {
    int sum;
    for (int i = 0; i < word.size(); ++i) {
        sum+=word[i];
    }
    return sum%HASH_LENGTH;
}
