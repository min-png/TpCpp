#include<iostream>
//#include"fichier.hpp"
#include<string>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class fichier
{
public:
const char w[2]="w";
const char wp[3]="w+";
const char r[2]="r";
const char rp[3]="r+";
const char a[2]="a";

char* Name;
char* Mode;
unsigned int size_len ;
FILE *fd; 
//public:
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
    void Lire();
    void charger();

    friend void afficher(FILE);
    friend string getText(FILE,unsigned int);
    friend char * str_c(string);
    fichier& operator+(fichier&);
    fichier& operator=(fichier&);
};

char* getText(FILE *fd,unsigned int  i)
{
    char *result=new char[sizeof i];
    char c;
    c=fgetc(fd);
    int j=0;
    while (!(c==EOF)&& (j<i))
    {
     *(result+j)=c;
      c=fgetc(fd);
      j++;
    }
    //result[j]='\0';
    string final;
    final=result;
    return result;
}


char* str_c(string s)
{
char* cha = new char[s.size() + 1];
std::copy(s.begin(), s.end(), cha);
cha[s.size()] = '\0';
return cha;
}
void afficher(FILE *fd)
{
    char c= fgetc(fd);
    while (!(c==EOF))
    {
     putchar(c);
     c=fgetc(fd);
    }
}

fichier& fichier::operator=(fichier & f){
 this->Set_Noun(f.Get_Noun());
 this->Set_Mode(f.Get_Mode());
 this->Set_Len(f.Get_len());
 this->fd=f.fd;
 return *this;
 }
 fichier& fichier::operator+(fichier& f1)
 {
    fichier *f=new fichier;
     f->Set_Len(f1.Get_len()+this->Get_len());
     f->Set_Mode(wp);
     f->Set_Noun(str_c("hello.txt"));
     f->fd=fopen(f->Get_Noun(),f->Get_Mode());
     f->Ecrire(getText(f1.fd,f1.size_len));
     return *f;
 }
//  fichier& operator+(fichier& f,fichier &g)
//  {
//      fichier *h=new fichier ;
     
//  fichier h;
//  int len=strlen(f->Name)-5;//5=sizeof ('txt')
//  char *c = new char[len+strlen(g.Name)];
//  for(size_t i=0;i<len;i++)
//  {
//  c[i]=f.Name[i];
//  }
//  c[len]='\0';
//  strcat(c.g.Name);
//  strcpy(h.Name,c);
//  free(c);
//  h.Mode="r+";
//  h.size_len=f.size_len+g.size_len;
//  cout<<"\nFile : "<<h.Name<<" size_len="<<h.size_len<<endl;
//  afficher(f.fd);
//  afficher(g.fd);
//  return h;
 //}

fichier::fichier()
{
this->size_len=0;
this->Name= str_c("");
this->Mode = str_c("");

// *this->Mode='\0';
 this->fd=NULL;
  cout<<"construction par defaut";
}

 fichier::fichier(string name,string mod  ,unsigned int size)
{
this->Name = str_c(name);

this->Mode = str_c(mod);
this->size_len=size;
  cout<<"construction specifique";
 this->fd=NULL;

// this->fd=fopen(Name,Mode);
// cout<<fd;
}

fichier::~fichier()
{
if (!(this->fd==__null))
    fclose(this->fd);
cout<<"\nbye bye";
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

// #### modifiers #######

void fichier::Ecrire( string key)
{ 
int result=strcmp(wp,this->Mode);
int result1=strcmp(this->Mode,w);
 if(!( (result==0)||(result1==0) ) )
  cout<< "erreur de mode d'ecriture"<<"\n";// avec w "<<result1<<w<<"\n avec wp "<<result<<wp << "  our suspect"<<this->Name;
 else
 {  cout<<"hi there \n";
    this->fd=fopen(this->Name,this->Mode);
    
    if (!(this->fd==__null))
    {
     char* s= new char [sizeof size_len];
     s =str_c(key);
     cout<<fd;
     puts(s);
     for (int i=0 ; i<size_len; i++)
     {
     fputc(s[i],this->fd);    
     }
     //fprintf(fd,"%-*.*s",size_len,size_len,s);
    }
    else
     cout<<" erreur de poiteur sur discripteur fichier";
 }
  
}

void fichier::Lire()
{
int result1=strcmp(rp,this->Mode);
int result=strcmp(r,this->Mode);
if(!( (result==0)||(result1==0) ) )
    cout<< "erreur de mode de lecture "<<"\n";
else 
{
    if (this->fd==__null)
    this->fd=fopen(this->Name,this->Mode);
//cout<<fd;
fseek(this->fd,0,SEEK_CUR);
cout<<"\n";
afficher(this->fd);

} 
}

void fichier::charger()
{
fichier::Set_Mode("r");
if (this->fd==__null)
    this->fd=fopen(this->Name,this->Mode);
fseek(this->fd,0,SEEK_SET);
cout<<"\nFile : "<<Name<<" size_len="<<size_len<<endl;
afficher(this->fd);
}



int main(){

fichier test("test.txt","r+",10);
test.Set_Mode("w");
////write only ammount speccified in size_len var
//test.Lire();
test.charger();
fichier f("hmid.txt","w+",5);
f.Ecrire("ba3bddddddddda5");
//f=test;
f.charger();
cout<<getText(f.fd,f.size_len)<<endl;
//  fichier baba;
//  baba=test+f;
//  cout<<baba.Get_Mode()<<endl;
//  baba.charger();
//  test.Set_Noun("ach.txt");
//  test.Set_Mode("r+");
//  test.Set_Len(5);
//  cout<<test.Get_Mode()   <<"mode    "<<test.Get_Noun()<<"noun   "<<test.Get_len()<<"length";
//   return 0 ;
// char c[5]="+++c";
// cout<<c;
}
