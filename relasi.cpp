#include "relasi.h"

void createlist(listrelasi &L) {
    first(L) = NULL;
}
addressrelasi alokasi(infotypeUlasan X, addressmovie P, addressreview RV) {
    addressrelasi RL = new elmrelasi;
    info(RL).ulasan = X.ulasan;
    info(RL).rating = X.rating;
    movie(RL) = P;
    review(RL) = RV;
    next(RL) = NULL;

    return RL;

}
void insertFirst(listrelasi &L, addressrelasi P) {
    if(first(L)==NULL) {
        first(L) = P;
    }else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(listrelasi &L, addressrelasi Prec, addressrelasi P){
    if(first(L)!=NULL){
        next(P)=next(Prec);
        next(Prec)=P;
    }else {
        first(L)=P;
    }
}
void deleteFirst(listrelasi &L, addressrelasi &P) {
    P = first(L);
    if(P != NULL) {
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteAfter(addressrelasi Prec, addressrelasi P) {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}
void deleteLast(listrelasi &L, addressrelasi P) {
    addressrelasi q;

    q = first(L);
    while (next(q) != P) {
        q = next(q);
    }
    next(q)=NULL;

}
void deleteElement(listrelasi &L, addressrelasi P) {
    if(first(L)==NULL) {
        cout<<"list kosong"<<endl;
    }else {
        if(first(L)==P){
            deleteFirst(L, P);
        }else if(next(P)==NULL){
            deleteLast(L, P);
        }else{
            addressrelasi Prec=first(L);
            while(next(Prec)!=P){
                Prec=next(Prec);
            }
            deleteAfter(Prec, P);
        }
    }
}

addressrelasi findElm(listrelasi L, addressmovie M, addressreview RV) {
    addressrelasi RL = first(L);
    if(RL != NULL) {
        do {
            if(movie(RL) == M && review(RL) == RV) {
                return RL;
            }
            RL=next(RL);
        }while(RL!=first(L));
    }
    return NULL;
}
addressrelasi findElm(listrelasi L, infotypemovie XM, infotypeUser XU){

    addressrelasi RL = first(L);
    if(RL != NULL) {
        do {
            if( info(movie(RL)).namafilm == XM.namafilm) {
                return RL;
            }else if(info(review(RL)).username == XU.username && info(review(RL)).password == XU.password) {
                return RL;
            }
            RL=next(RL);
        }while(RL!=first(L));
    }
    return NULL;

}
void connect(listrelasi &LR, listmovie LM, listreview LRV, infotypemovie MX, infotypeUlasan XU, infotypeUser X) {
    addressmovie mov = searchElm(LM,MX);
    addressreview rev = searchElm(LRV, X);
    if( mov != NULL && rev != NULL) {
        info(mov).jml++;
        addressrelasi RL = alokasi(XU, mov, rev);
        insertFirst(LR, RL);
    }
}
void disconnect(listrelasi &LR, infotypemovie MX, infotypeUser XU) {
    addressrelasi RL = findElm(LR,MX,XU);
    if(RL != NULL) {
        deleteElement(LR, RL);
        delete RL;
    }
}
void disconnect_add(listrelasi &LR, addressmovie M, addressreview U) {
    addressrelasi RL = findElm(LR,M,U);
    if(RL != NULL) {
        deleteElement(LR, RL);
        delete RL;
    }
}

void printUrut_M(listmovie L){
    addressmovie maks,Q;

    maks=first(L);
    Q=next(maks);

    while(Q!=NULL){
        if(info(Q).jml>info(maks).jml){
            maks=Q;
        }
        Q=next(Q);
    }
    if(info(maks).jml!=0){
        cout<<"- "<<info(maks).namafilm<<endl;
    }else{
        cout<<"belum ada yang mengulas ~~~~"<<endl;
    }
    cout<<endl;
}

void printrelasi(listrelasi LR, listmovie LM) {
    addressmovie mov = first(LM);

    while(mov!=NULL) {
        cout<<info(mov).namafilm<<" - ";
        addressrelasi RL = first(LR);
        if(RL!=NULL) {
            do{
                if(movie(RL)==mov){
                    cout<<"("<<info(RL).rating<<" dari 10.0)--> ";
                    cout<<info(RL).ulasan<<". ";
                    cout<<"<tahun rilis: "<<info(movie(RL)).tahun<<">, ";
                }
                RL = next(RL);
            }while(next(RL)!=NULL);
        }
        cout<<endl;
        mov=next(mov);
    }
    cout<<endl<<endl;
}

void printrelasi(listrelasi LR, listreview LRV) {
    addressreview rev = first(LRV);

    while(rev!=NULL) {
        cout<<"- "<<info(rev).username<<", dalam ulasannya : ";
        addressrelasi RL = first(LR);
        if(RL!=NULL) {
            do{
                if(review(RL)==rev){
                    cout<<"'"<<info(RL).ulasan<<"',"<<" Dengan rating ("<<info(RL).rating<<"/10.0) ==> ";
                    cout<<"judul film ("<<info(movie(RL)).namafilm<<"). "<<endl;

                }
                RL = next(RL);
            }while(next(RL)!=NULL);
        }
        cout<<endl;
        rev=next(rev);
    }
    cout<<endl<<endl;
}



void printmovie_HR(listrelasi L, listmovie LM, addressreview RV ){
    addressrelasi Q;
    addressmovie P = first(LM);
    cout<<"===================================="<<endl;
    cout<<"== list film yang belum di review =="<<endl;
    cout<<"===================================="<<endl;

    if(first(LM)!=NULL){
        while(P!=NULL){
            Q=first(L);
            while(Q!=NULL){
                if(movie(Q)==P && review(Q)==RV){
                    P=next(P);
                    Q=first(L);
                }
                Q=next(Q);
            }
            if(P==NULL&&Q==NULL){
                cout<<"======= sudah di ulas semua ========"<<endl;
            }else if(P!=NULL){
                cout<<"- "<<info(P).namafilm<<" (rilis "<<info(P).tahun<<")"<<endl;
                P=next(P);
            }
        }


    }else{
        cout<<"belum terdaftar"<<endl;
    }
    cout<<endl<<endl;
}
void printSpesifik(listrelasi L, listreview LU, addressreview P){
    addressrelasi Q=first(L);
    if(first(L)!=NULL){
        while(Q!=NULL){
            if(review(Q)==P){
                cout<<info(movie(Q)).namafilm<<" ("<<info(movie(Q)).tahun<<")"<<" - ";
                cout<<"'"<<info(Q).ulasan<<"'"<<", rating = "<<info(Q).rating<<endl;
            }
            Q=next(Q);

        }
    }else{
        cout<<"belum ada ulasan"<<endl;
    }
    cout<<endl;
}
int showPil1(listrelasi &L, listmovie &LM, listreview &LR){
    int pilmenu;
    const int satu=1,
              dua=2,
              tiga=3;

    do
    {
        cout << "---------- Menu Admin ----------"<<endl
            << "1. update"<<endl
            << "2. informasi film"<<endl
            << "3. view data user"<<endl
            << "4. Log Out"<<endl<<endl;
        cout<<"pilih opsi : ";
        cin>>pilmenu;
        cout<<endl;
        while(pilmenu<1||pilmenu>4){
            cout << "Please enter a valid menu choice: ";
            cin >> pilmenu;
        }
        if(pilmenu!=4){
            //atribut movie
                infotypemovie XM;
                addressmovie P;
                string hasil;
                int jwbMenu;
            //atribut review
                infotypeUser XRV;
                int menuR;
            //atribut relasi


            switch (pilmenu)
            {
            case satu:
                cout<< "1. input data (movie)"<<endl
                    << "2. edit data (movie)"<<endl
                    << "3. delete data (movie)"<<endl
                    << "4. back"<<endl<<endl;
                cout<<"pilih opsi : ";
                cin>>jwbMenu;
                cout<<endl;
                while(jwbMenu<1||jwbMenu>4){
                    cout << "Please enter a valid menu choice: ";
                    cin >> jwbMenu;
                }
                if(jwbMenu==1){
                    cout<<"---------- input data ----------"<<endl<<endl;
                    cout<<"masukkan nama film : ";
                    cin>>XM.namafilm;
                    cout<<"rilis tahun : ";
                    cin>>XM.tahun;
                    createNewElm(XM, P);
                    if(first(LM)==NULL){
                        insertFirst(LM,P);
                    }else{
                        insertLast(LM, P);
                    }
                    printInfo_M(LM);
                }if(jwbMenu==2){
                    printInfo_M(LM);
                    cout<<"---------- edit data -----------"<<endl<<endl;
                    cout<<"data film apa yang ingin diganti : ";
                    cin>>hasil;
                    XM.namafilm=hasil;
                    cout<<endl;
                    P = searchElm(LM, XM);
                    if(P!=NULL){
                        cout<<"ganti nama film menjadi : ";
                        cin>>XM.namafilm;
                        cout<<"rilis tahun : ";
                        cin>>XM.tahun;
                        info(P).namafilm=XM.namafilm;
                        info(P).tahun=XM.tahun;
                        printInfo_M(LM);


                    }
                    if(P==NULL){
                        cout<<"--nama film tidak ditemukan di list--"<<endl<<endl;
                    }
                }if(jwbMenu==3){
                    cout<<"---------- delete film ---------"<<endl<<endl;
                    cout<<"film apa yang ingin dihapus : ";
                    cin>>hasil;
                    XM.namafilm=hasil;
                    cout<<endl;
                    P = searchElm(LM, XM);
                    if(P!=NULL){
                        deleteELM_M(LM, P);
                        printInfo_M(LM);
                    }
                    if(P==NULL){
                        cout<<"--nama film tidak ditemukan di list--"<<endl<<endl;
                    }
                }if(jwbMenu==4){
                    return 0;
                }

                break;
            case dua:
                cout  <<"--informasi film--"<<endl<<endl
                      <<"1. daftar semua film"<<endl
                      <<"2. lihat film & ulasannya"<<endl
                      <<"3. back"<<endl<<endl;
                cout<<"pilih opsi: ";
                cin>>menuR;
                cout<<endl;
                while(menuR<1||menuR>3){
                    cout << "Please enter a valid menu choice: ";
                    cin >> menuR;
                }
                if(menuR==1){
                    cout<<"---------- film yang ada di list ---------"<<endl;
                    printInfo_M(LM);
                }if(menuR==2){
                    cout<<"==================================="<<endl;
                    cout<<"==daftar semua film dan ulasannya=="<<endl;
                    cout<<"==================================="<<endl;

                    printrelasi(L,LM);
                }if(menuR==3){
                    break;
                }


                break;
            case tiga:
                cout  <<"---------- data user ----------"<<endl
                      <<"1. informasi reviewer"<<endl
                      <<"2. lihat reviewer & film yang diulas"<<endl
                      <<"3. back"<<endl<<endl;
                cout<<"pilih opsi: ";
                cin>>menuR;
                cout<<endl;
                while(menuR<1||menuR>3){
                    cout << "Please enter a valid menu choice: ";
                    cin >> menuR;
                }
                if(menuR==1){
                    cout<<"--reviewer yang ada di list--"<<endl; //masih kureng
                    printInfo_RV(LR);
                }if(menuR==2){
                    cout<<"======================="<<endl;
                    cout<<"==daftar semua ulasan=="<<endl;
                    cout<<"======================="<<endl;

                    printrelasi(L,LR);
                }if(menuR==3){
                    break;
                }
            default:
                break;
            }

        }
    } while (pilmenu!=4);
        return 0;



}

int showPil2(listrelasi &L, listmovie &LM, listreview &LR, addressreview P){
    int pilmenu, jwbmenu2;
    string filmApa, yesno, hasil;

    addressmovie M;
    infotypemovie MX;

    addressrelasi R;
    infotypeUlasan XU;

    infotypeUser X;

    const int satu=1,
              dua=2,
              tiga=3;

    do
    {
        cout << "--Menu User--"<<endl
            << "1. Account"<<endl
            << "2. Update ulasan"<<endl
            << "3. Delete ulasan anda"<<endl
            << "4. Log Out"<<endl<<endl;
        cout<<"pilih opsi: ";
        cin>>pilmenu;
        cout<<endl;
        while(pilmenu<1||pilmenu>4){
            cout << "Please enter a valid menu choice: ";
            cin >> pilmenu;
        }if(pilmenu!=4){
            switch (pilmenu)
            {
            case satu:

                cout << "============== Data Akun ==============="<<endl
                     << "online user -> "<<info(P).username <<endl
                     << "password sekarang: "<<info(P).password<<endl
                     << "========================================"<<endl
                     << "edit data? (yes/no)"<<endl
                     << "ketik yes/no: "<<endl;
                cin>>yesno;
                while(yesno != "yes" && yesno != "no"){
                    cout << "Please type correctly: "<<endl;
                    cin >> yesno;
                }
                if(yesno=="yes"){
                    cout<<"masukkan username baru: ";
                    cin>>X.username;
                    cout<<"masukkan password baru: ";
                    cin>>X.password;
                    info(P).username=X.username;
                    info(P).password=X.password;
                    cout << "=============== Data Baru ==============="<<endl
                         << "online user-> "<<info(P).username <<endl
                         << "password baru: "<<info(P).password<<endl
                         << "========================================="<<endl;
                }
                break;
            case dua:
                cout<< "---------- Update ulasan ----------"<<endl
                    << "1. beri ulasan"<<endl
                    << "2. tampil semua film yg sudah anda review"<<endl
                    << "3. back"<<endl<<endl;
                cout<<"pilih opsi: ";
                cin>>jwbmenu2;
                cout<<endl;
                while(jwbmenu2<1||jwbmenu2>3){
                    cout << "Please enter a valid menu choice: ";
                    cin >> jwbmenu2;
                }if(jwbmenu2==1){
                    printmovie_HR(L,LM,P);
                    cout<<"~~ULASAN HARUS DI ISI TERURUT MULAI DARI ATAS SAMPAI BAWAH~~"<<endl<<endl;
                    cout<<"film apa yang ingin anda ulas : ";
                    cin>>filmApa;
                    MX.namafilm=filmApa;
                    M=searchElm(LM,MX);
                    if(M!=NULL){
                        cout<<"beri ulasan : ";
                        cin>>XU.ulasan;
                        cout<<"beri rating : ";
                        cin>>XU.rating;
                        connect(L,LM,LR,MX,XU,info(P));
                        cout<<endl;

                    }else{
                        cout<<"===film tidak ditemukan==="<<endl<<endl;
                    }
                }if(jwbmenu2==2){
                    cout <<"========================================"<<endl
                         <<"=== Daftar film yang sudah anda ulas ==="<<endl
                         <<"========================================"<<endl;
                    printSpesifik(L,LR,P);
                }if(jwbmenu2==3){
                    break;
                }
                break;
            case tiga:
                cout <<"=========================="<<endl
                     <<"=== daftar ulasan anda ==="<<endl
                     <<"=========================="<<endl;
                printSpesifik(L,LR,P);
                cout << "hapus ulasan? (yes/no)"<<endl
                     << "ketik yes/no: "<<endl;
                cin>>yesno;
                while(yesno!="yes"&&yesno!="no"){
                    cout << "Please type correctly: "<<endl;
                    cin >> yesno;
                }
                if(yesno=="yes"){
                    cout<<"ulasan film apa yang ingin dihapus: ";
                    cin>>MX.namafilm;
                    cout<<endl;
                    M=searchElm(LM,MX);
                    if(M!=NULL){
                        disconnect_add(L,M,P);
                        cout <<"============"<<endl
                             <<"= UPDATED =="<<endl
                             <<"=========================="<<endl
                             <<"=== daftar ulasan anda ==="<<endl
                             <<"=========================="<<endl;
                        printSpesifik(L,LR,P);
                    }else{
                        cout<<"film tidak ditemukan"<<endl;
                    }
                }
                break;

            default:
                break;
            }
        }
    }while(pilmenu!=4);
        return 0;
}



