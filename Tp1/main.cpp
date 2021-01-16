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
    fichier(string,string,unsigned int);
    ~fichier();

    void Set_Noun(string);
    void Set_Mode(string );
    void Set_Len(unsigned int);

    char*  Get_Noun();
    char*  Get_Mode();
    unsigned int Get_len();

    void Ecrire(char*);
    void lire();

};

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
this->Name = new char[name.size() + 1];
std::copy(name.begin(), name.end(), Name);
this->Name[name.size()] = '\0';

this->Mode = new char[mod.size() + 1];
std::copy(mod.begin(), mod.end(), Mode);
this->Mode[mod.size()] = '\0';

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

void fichier::Set_Noun(string name){
this->Name=new char [sizeof name];
//this->Name=*name;

 
//cout<<"name"<<Name<<endl;
}
void fichier::Set_Mode(string mode){
this->Mode=new char [sizeof mode];
//this->Mode=mode;

//cout<<"Mode"<<Mode<<endl;
}

void fichier::Set_Len(unsigned int num){
this->size_len=num;
}

int main(){
fichier test("test.txt","r+",10);

//fichier test;
// test.Set_Noun("ach.txt");
// test.Set_Mode("r+");
// test.Set_Len(5);
 cout<<test.Get_Mode()   <<"mode    "<<test.Get_Noun()<<"noun   "<<test.Get_len()<<"length";
    return 0 ;

}
