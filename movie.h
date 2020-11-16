#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;
// adt movie
typedef struct elmmovie *addressmovie;

struct isimovie{
    string namafilm;
    int tahun;
    int jml;
};

typedef isimovie infotypemovie;
struct elmmovie{
    infotypemovie info;
    addressmovie next;
};

struct listmovie{
    addressmovie first;
};

void createList(listmovie &L);
void createNewElm(infotypemovie X, addressmovie &P);
void insertFirst(listmovie &L, addressmovie P);
void insertAfter(listmovie &L, addressmovie Prec, addressmovie P);
void insertLast(listmovie &L, addressmovie P);
void insertDescending(listmovie &LM, infotypemovie XM, addressmovie P);
void deleteFirst(listmovie &L, addressmovie &P);
void printInfo_M(listmovie L);
addressmovie searchElm(listmovie L, infotypemovie X);




#endif // MOVIE_H_INCLUDED
