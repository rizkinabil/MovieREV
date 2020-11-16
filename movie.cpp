#include "movie.h"
#include <iostream>
using namespace std;

void createList(listmovie &L) {
    first(L) = NULL;
}
void createNewElm(infotypemovie X, addressmovie &P) {
    P = new elmmovie;
    info(P).namafilm = X.namafilm;
    info(P).tahun = X.tahun;
    info(P).jml = 0;
    next(P) = NULL;
}
void insertFirst(listmovie &L, addressmovie P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfter(listmovie &L, addressmovie Prec, addressmovie P){
    if(first(L)!=NULL){
        next(P)=next(Prec);
        next(Prec)=P;
    }else {
        first(L)=P;
    }
}

void insertLast(listmovie &L, addressmovie P) {
    addressmovie last = first(L);
    if(first(L)==NULL){
        first(L) = P;
    }else {
        while(next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}
void insertDescending(listmovie &LM, infotypemovie XM, addressmovie P){
    addressmovie Prec = first(LM);

    if(first(LM)==NULL){
        if(info(P).jml==0&&info(Prec).jml==0){
            insertFirst(LM,P);
        }
        if(info(P).jml<info(Prec).jml){
            insertFirst(LM,P);
        }else {
            while(next(Prec)!=NULL){
                if(info(P).jml>info(Prec).jml&&info(P).jml<info(next(Prec)).jml){
                    insertAfter(LM,Prec,P);
                }
                Prec=next(Prec);
            }
            if(info(P).jml>info(Prec).jml){
                insertLast(LM,P);
            }
        }
    }else{
        insertFirst(LM,P);
    }
}
void deleteFirst(listmovie &L, addressmovie &P) {
    P = first(L);
    if(P != NULL) {
        first(L) = next(P);
        next(P) = NULL;
    }
}
void printInfo_M(listmovie L) {
    addressmovie P = first(L);
    cout <<"=================="<<endl
         <<"=== list movie ==="<<endl
         <<"=================="<<endl;
    while(P!=NULL){
        cout<<"- ";
        cout<<info(P).namafilm<<" rilis tahun :";
        cout<<info(P).tahun<<endl;
        P = next(P);
    }
    cout<<endl<<endl;
}
addressmovie searchElm(listmovie L, infotypemovie X) {
    addressmovie P = first(L);
    while(P!=NULL){
        if(info(P).namafilm==X.namafilm) {
            return P;
        }
        P=next(P);
    }
    return NULL;
}



