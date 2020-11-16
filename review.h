#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED
#include <iostream>
#include "movie.h"

using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

//adt reviewer
typedef struct elmreview *addressreview;

struct isiuser{
    string username;
    string password;
};


typedef isiuser infotypeUser;
struct elmreview{
    infotypeUser info;
    addressreview next;
};
struct listreview{
    addressreview first;
};

void createList_RV(listreview &L);
void createNewElm(infotypeUser &XU, addressreview &P);
void insertFirst(listreview &L, addressreview P);
void insertAfter(listreview &L, addressreview Prec, addressreview P);
void insertLast(listreview &L, addressreview P);
void deleteFirst(listreview &L, addressreview &P);
void deleteLast_M(listmovie &L, addressmovie P);
void deleteAfter_M(addressmovie Prec, addressmovie P);
void deleteELM_M(listmovie &L, addressmovie P);
void printInfo_RV(listreview L);

addressreview searchElm(listreview L, infotypeUser X);
void insertAscending(listreview &L, infotypeUser X, addressreview P);



#endif // REVIEW_H_INCLUDED
