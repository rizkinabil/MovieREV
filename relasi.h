#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED


#include "movie.h"
#include "review.h"
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define movie(P) P->movie
#define review(P) P->review

typedef struct elmrelasi *addressrelasi;
struct isiUlasan{
    string ulasan;
    float rating;
};
typedef isiUlasan infotypeUlasan;

struct elmrelasi{
    infotypeUlasan info;
    addressmovie movie;
    addressreview review;
    addressrelasi next;

};

struct listrelasi{
    addressrelasi first;
};

void createlist(listrelasi &L);
addressrelasi alokasi(infotypeUlasan X, addressmovie P, addressreview RV);
void insertFirst(listrelasi &L, addressrelasi P);
void insertAfter(listrelasi &L, addressreview Prec, addressreview P);
void deleteFirst(listrelasi &L, addressrelasi &P);
void deleteAfter(addressrelasi prec, addressrelasi P);
void deleteLast(listrelasi &L, addressrelasi P);
void deleteElement(listrelasi &L, addressrelasi P);
addressrelasi findElm(listrelasi L, addressmovie M, addressreview RV);
addressrelasi findElm(listrelasi L, infotypemovie XM, infotypeUser XU);
void connect(listrelasi &LR, listmovie LM, listreview LRV, infotypemovie MX, infotypeUlasan XU, infotypeUser X);
void disconnect(listrelasi &LR, infotypemovie MX, infotypeUser XU);
void disconnect_add(listrelasi &LR, addressmovie M, addressreview U);
void printUrut_M(listmovie L);
void printrelasi(listrelasi LR, listmovie LM);
void printrelasi(listrelasi LR, listreview LRV);
void printmovie_HR(listrelasi L, listmovie LM, addressreview P);
void printSpesifik(listrelasi L, listreview LU, addressreview P);
//menu admin
int showPil1(listrelasi &L, listmovie &LM, listreview &LR);
//menu reviewer
int showPil2(listrelasi &L, listmovie &LM, listreview &LR, addressreview P);



#endif // RELASI_H_INCLUDED
