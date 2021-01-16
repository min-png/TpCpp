#include<iostream>
//#include"fichier.hpp"
#include<string>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class fichier
{
private:
const char w[2]="w";
const char wp[3]="w+";
const char r[2]="r";
const char rp[3]="r+";
const char a[2]="a";

char* Name;
char* Mode;
unsigned int size_len ;
FILE *fd; 
public:
    fichier(/* args */);
    fichier(string,string,unsigned int);
    ~fichier();

    void Set_Noun(string);
    void Set_Mode(string );
    void Set_Len(unsigned int);

    char*  Get_Noun();
    char*  Get_Mode();
    unsigned int Get_len();

    void Ecrire(string);
    void lire();
    friend char * str_c(string);
};

char* str_c(string s)
{
char* cha = new char[s.size() + 1];
std::copy(s.begin(), s.end(), cha);
cha[s.size()] = '\0';
return cha;
}

fichier::fichier(/* args */)
{
 this->Name=new char[1];
 Name='\0';
 this->Mode=new char[1];
 Mode='\0';
 this->fd=NULL;
 cout<<"construction par defaut";
}

 fichier::fichier(string name,string mod  ,unsigned int size)
{
this->Name = str_c(name);

this->Mode = str_c(mod);
this->size_len=size;
  cout<<"construction specifique";
// this->fd=fopen(Name,Mode);
// cout<<fd;
}

fichier::~fichier()
{
cout<<"\n bye bye";
//fclose(this->fd);
}
//Getters###
unsigned int fichier::Get_len(){
    return this->size_len;
}
char * fichier::Get_Noun(){
return(this->Name);
}
char * fichier::Get_Mode(){
return(this->Mode);
}

void fichier::Set_Noun(string name)
{
    this->Name=str_c(name);
}

void fichier::Set_Mode(string mod)
{
    this->Mode=str_c(mod);
}

void fichier::Set_Len(unsigned int num){
this->size_len=num;
}

void fichier::Ecrire(string key)
{
int result=strcmp(this->Name,wp);
int result1=strcmp(this->Name,w);
 if(!( (result==0)||(result1==0) ) )
  cout<< "erreur de mode d'ecriture";
 else
 {
    this->fd=fopen(this->Name,this->Mode);
    if (!(this->fd=__null))
    {
     char* s= new char [sizeof size_len];
     s =str_c(key);
     fprintf(fd,"%-*.*s",size_len,size_len,s);
    }
    else
     cout<<"erreur de poiteur sur discripteur fichier";
 }
  
}

int main(){

fichier test("test.txt","r+",10);
test.Ecrire("1234567891011");
// fichier test;
//  test.Set_Noun("ach.txt");
//  test.Set_Mode("r+");
//  test.Set_Len(5);
//  cout<<test.Get_Mode()   <<"mode    "<<test.Get_Noun()<<"noun   "<<test.Get_len()<<"length";
//   return 0 ;
}
