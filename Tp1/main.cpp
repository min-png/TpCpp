#include<iostream>
//#include"fichier.hpp"
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class fichier
{
private: 
char* Name;
char* Mode;
unsigned int size_len ;
FILE *fd; 
public:
    fichier(/* args */);
    ~fichier();

    void Set_Noun(char* );
    void Set_Mode(char* );
    void Set_Len(unsigned int);

    char*  Get_Noun();
    char*  Get_Mode();
    unsigned int Get_len();

    void Ecrire(char*);
    void lire();

};

fichier::fichier(/* args */)
{
 this->Name="";
 this->Mode="";
 this->fd=NULL;
 cout<<"construction par defaut";
}

fichier::~fichier()
{
cout<<"\n bye bye";
fclose(this->fd);
}

