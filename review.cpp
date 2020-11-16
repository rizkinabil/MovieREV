#include "review.h"
#include <iostream>

using namespace std;

void createList_RV(listreview &L) {
    first(L) = NULL;
}
void createNewElm(infotypeUser &XU, addressreview &P) {
    P = new elmreview;
    info(P).username=XU.username;
    info(P).password = XU.password;
    next(P) = NULL;

}

void insertFirst(listreview &L, addressreview P) {
    next(P) = first(L);
    first(L) = P;
}
void insertAfter(listreview &L, addressreview Prec, addressreview P){
    next(P)=next(Prec);
    next(Prec)=P;


}

void insertLast(listreview &L, addressreview P) {
    addressreview last = first(L);
    if(first(L)==NULL){
        first(L) = P;
    }else {
        while(next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}
void deleteFirst(listreview &L, addressreview &P) {
    P = first(L);
    if(P != NULL) {
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLast_M(listmovie &L, addressmovie P){
    addressmovie Q = first(L);
    while(next(Q)!=NULL){
        Q=next(Q);
    }
    next(Q)=NULL;
}
void deleteAfter_M(addressmovie Prec, addressmovie P) {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}
void deleteELM_M(listmovie &L, addressmovie P){
    if(first(L)==NULL) {
        cout<<"list kosong"<<endl;
    }else {
        if(P==first(L)){
            deleteFirst(L, P);
        }else if(next(P)==NULL){
            deleteLast_M(L, P);
        }else{
            addressmovie Prec=first(L);
            while(next(Prec)!=P){
                Prec=next(Prec);
            }
            deleteAfter_M(Prec, P);
        }


    }
}
void printInfo_RV(listreview L) {
    addressreview P = first(L);
    cout <<"============================"<<endl
         <<"===== daftar nama user ====="<<endl
         <<"============================"<<endl;
    while(P!=NULL) {
        cout<<"- "<<info(P).username<<endl;

        P = next(P);
    }
    cout<<endl<<endl;
}

addressreview searchElm(listreview L, infotypeUser X) {
    addressreview P = first(L);
    while(P!=NULL) {
        if(info(P).username==X.username&&info(P).password==X.password) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAscending(listreview &L, infotypeUser X, addressreview P){
    addressreview Prec = first(L);

    if(first(L)!=NULL){
        if(info(P).username<info(Prec).username){
            insertFirst(L,P);
        }else{
            while(next(Prec)!=NULL){
                if(info(P).username>info(Prec).username && info(P).username<info(next(Prec)).username){
                insertAfter(L,Prec,P);
            }
                Prec=next(Prec);
            }
            if(info(P).username>info(Prec).username){
                insertLast(L,P);
            }

        }

    }else{
        insertFirst(L,P);
    }
}

/*
1.
if(next(Prec)==NULL){
            if(info(Prec).username<info(P).username){
                insertAfter(L,Prec,P);
            }else{
                insertFirst(L,P);
            }
        }
        while(next(Prec)!=NULL){
            if(info(Prec).username<info(P).username && info(next(Prec)).username>info(P).username){
                insertAfter(L,Prec,P);
            }else if(info(Prec).username>info(P).username){
                insertFirst(L,P);
            }else if(info(next(Prec)).username<info(P).username){
                insertLast(L,P);
            }
            Prec=next(Prec);
        }
2.
            if(next(Prec)!=NULL){
                while(info(P).username>info(Prec).username){
                    if(info(P).username>info(last).username){
                        insertLast(L,last);
                    }
                    insertAfter(L, Prec, P);
                }
                Prec=next(Prec);


            }else if(next(Prec)==NULL) {
                if(info(P).username>info(first(L)).username){
                    insertLast(L,P);
                }
                last = next(Prec);
            }
        }
*/
