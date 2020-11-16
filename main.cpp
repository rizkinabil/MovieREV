#include <iostream>
#include <stdio.h>
#include "movie.h"
#include "review.h"
#include "relasi.h"

    listmovie film;
    listrelasi ulasan;
    listreview user;

using namespace std;

int main()
{
    createList(film);
    createlist(ulasan);
    createList_RV(user);

    infotypemovie X;
    infotypeUlasan Y;
    infotypeUser U;

    addressmovie M;
    addressreview Rv;
    addressrelasi Rl;

    string id,pw,yesno;
    int menu1,answ;

    X.namafilm="stranger_things";
    X.tahun=2018;
    createNewElm(X, M);
    insertFirst(film, M);

    X.namafilm="avengers";
    X.tahun=2015;
    createNewElm(X, M);
    insertFirst(film, M);

    X.namafilm="spider_man";
    X.tahun=2007;
    createNewElm(X, M);
    insertFirst(film, M);

    U.username="@rizki_";
    U.password="qwerty";
    createNewElm(U,Rv);
    insertAscending(user,U,Rv);

    U.username="rizki";
    U.password="qwerty";
    createNewElm(U,Rv);
    insertAscending(user,U,Rv);

    U.username="Azriel";
    U.password="qwerty";
    createNewElm(U,Rv);
    insertAscending(user,U,Rv);


    do
    {
        cout << "Please choose an option" << endl << endl
            << "1. login as admin" << endl
            << "2. login as user " << endl
            << "3. non login user" << endl
            << "4. exit program" << endl << endl;
        cout<<"pilih opsi : ";
        cin>>menu1;
        while(menu1<1 || menu1>4){
            cout << "Please enter a valid menu choice: ";
            cin >> menu1;
        }
        if(menu1!=4){
            switch (menu1)
            {
            case 1:
                int counter;
                cout<<"--admin--"<<endl;
                cout<<"masukkan ID : ";
                cin>>id;
                cout<<"masukkan password : ";
                cin>>pw;
                cout<<endl;
                counter=1;
                while(id!="Admin"&&pw!="Admin"){
                    if(counter<3){

                        cout<<"username or password incorrect"<<" ("<<counter+1<<") "<<endl;
                        cout<<"masukkan ID : ";
                        cin>>id;
                        cout<<"masukkan password : ";
                        cin>>pw;
                        cout<<endl;
                        counter++;
                    }else{
                        break;
                    }

                }
                if(id=="Admin"&&pw=="Admin"){
                    cout<< "---------- selamat datang ----------" <<endl<<endl;
                    showPil1(ulasan,film,user);

                }else{
                    cout<<"username or password not found"<<endl<<endl;

                    cout<<"------------ GAGAL LOGIN -----------"<<endl;
                    break;
                }
                break;


            case 2:
                cout<<"---------- Log In User ----------"<<endl;
                cout << "sudah punya akun?"<<endl
                     << "1. sudah"<<endl
                     << "2. belum"<<endl
                     << "jika belum punya akun, silakan sign up di menu utama->pilih opsi 3"<<endl;
                cout<<"pilih opsi : ";
                cin>>answ;
                while(answ<1||answ>2){
                    cout << "Please enter a valid menu choice: ";
                    cin >> answ;
                }
                if(answ==1){
                    int counterR = 1;
                    addressreview ketemu;
                    cout<<"( "<<counterR<<" )"<<endl;
                    cout<<"masukkan Username : ";
                    cin>>U.username;
                    cout<<"masukkan password : ";
                    cin>>U.password;
                    ketemu = searchElm(user,U);
                    cout<<endl;
                    while(!ketemu && counterR<=2){
                        cout<<"username/password salah ( "<<counterR+1<<" )"<<endl;
                        cout<<"masukkan Username : ";
                        cin>>U.username;
                        cout<<"masukkan password : ";
                        cin>>U.password;
                        ketemu = searchElm(user,U);
                        cout<<endl;
                        counterR++;

                    }
                    if(ketemu){
                    cout<< "----- selamat datang, "<<info(ketemu).username<<" -----" <<endl<<endl;
                    showPil2(ulasan,film,user,ketemu);


                    break;
                    }else{
                        cout<<"Username atau password tidak ditemukan/salah"<<endl;
                        cout<<"periksa kembali username & password anda !"<<endl<<endl;
                        cout<<"----------- SYSTEM OUT ----------"<<endl<<endl;
                        break;
                    }
                }if(answ==2){
                    cout<<"====== Please Sign Up first! ======"<<endl<<endl;
                }
                break;
            case 3:
                cout <<"================================="<<endl
                     <<"== Daftar film trending review =="<<endl
                     <<"================================="<<endl;
                     printUrut_M(film);
                cout<< "sign up? (yes/no)"<<endl;
                cout<< "ketik yes/no: ";
                cin>>yesno;
                cout<<endl;
                while(yesno!="yes"&&yesno!="no"){
                    cout << "Please type correctly: "<<endl;
                    cin >> yesno;
                }
                if(yesno=="yes"){
                    cout<<"--------- sign up ---------"<<endl;
                    cout<<"masukkan Username : ";
                    cin>>U.username;
                    cout<<"masukkan password : ";
                    cin>>U.password;
                    cout<<endl;
                    createNewElm(U,Rv);
                    insertAscending(user,U,Rv);
                    printInfo_RV(user);
                    cout<<"Silahkan login"<<endl;
                    int counterRS;
                    counterRS=1;
                    addressreview ketemu;
                    cout<<"( "<<counterRS<<" )"<<endl;
                    cout<<"masukkan Username : ";
                    cin>>U.username;
                    cout<<"masukkan password : ";
                    cin>>U.password;
                    ketemu = searchElm(user,U);
                    cout<<endl;
                    while(!ketemu && counterRS<=2){
                        cout<<"username/password salah ( "<<counterRS+1<<" )"<<endl;
                        cout<<"masukkan Username : ";
                        cin>>U.username;
                        cout<<"masukkan password : ";
                        cin>>U.password;
                        ketemu = searchElm(user, U);
                        cout<<endl;
                        counterRS++;

                    }
                    if(ketemu){
                        cout<< "----- selamat datang, "<<info(ketemu).username<<" ------" <<endl<<endl;
                        showPil2(ulasan,film,user,ketemu);


                        break;
                        }else{
                            cout<<"Username atau password tidak ditemukan/salah"<<endl;
                            cout<<"periksa kembali username & password anda !"<<endl<<endl;
                            cout<<"---------- SYSTEM OUT ----------"<<endl<<endl;
                            break;
                        }

                }else{
                    break;
                }






            default:
                break;
            }

        }


    } while (menu1!=4);
    cout<<"===================="<<endl
        <<"=== TERIMA KASIH ==="<<endl
        <<"===================="<<endl;
    return 0;
}

