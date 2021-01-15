#include<iostream>
//#include"fichier.hpp"
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class fichier
{
private:
string Name;
string Mode;
char* NameChar;
char* ModeChar;
unsigned int size_len ;
FILE *fd; 

public:
    fichier();
    fichier(string, string ,unsigned int);
    ~fichier();
    void Set_Noun(string );
    void Set_Mode(string );
    void Set_Len(unsigned int);

    string  Get_Noun();
    string  Get_Mode();
    unsigned int Get_len();

    void openFile();

    void Ecrire(string ,bool);
    void Lire(bool mod);// if true :>> SEEK_SET else 0:>>SEEK_CUR
};

fichier::fichier(){
 this->Name="";
 this->Mode="";
 this->fd=NULL;
}
fichier::~fichier(){//
    cout<<"\n bye bye";
    fclose(this->fd);
}
//#### getters####
string fichier::Get_Noun(){
if((this->Name)!="") return this->Name;
else return" still uNamed";
}
string  fichier::Get_Mode(){
return Mode;
}
unsigned int fichier::Get_len(){
return size_len;
}

//#########################setters#######################

void fichier::Set_Noun(string a){
Name=a;
this->NameChar = new char[this->Name.size() + 1];
std::copy(this->Name.begin(), this->Name.end(), NameChar);
NameChar[this->Name.size()] = '\0'; 
//cout<<"name"<<NameChar<<endl;
}
void fichier::Set_Mode(string a){
Mode=a;
//concersion des deusx string en char
this->ModeChar = new char[a.size() + 1];
std::copy(a.begin(), a.end(), ModeChar);
ModeChar[a.size()] = '\0';
//cout<<"Mode"<<ModeChar<<endl;
}
void fichier::openFile(){
this->fd=fopen(this->NameChar,ModeChar);
}
void fichier::Set_Len(unsigned int num){
this->size_len=num;
}

//#########################editors####################""

void fichier::Ecrire(string  s,bool mod){
//cout<<"probleme de mode d'ouverture \n essayer avec w ou encore w+";
char * strChar = new char[s.size() + 1];
std::copy(s.begin(), s.end(), strChar);
strChar[s.size()] = '\0'; 

fseek(this->fd,0,int(mod));

for (size_t i = 0; i <(s.size()); i++)
{
   fputc(strChar[i],this->fd);
}

//fprintf(this->fd,"%-*.*s ",size_len,size_len,strChar);
}

// string fichier::Lire(){
// // //if(this->ModeChar!="r"||"r+")
// // //cout<<"probleme de mode de lecture \n essayer avec r ou encore r+";
// // fscanf(this->fd,c);
// // string s=c;
// // return s ; 
//  char* c = new char[size_len]; //Malloc way to define 
// rewind(this->fd);
//  while ((*c=fgetc(this->fd))!=EOF)
//         {  
//             cout<<*c;
//             string chari=+c;
//             return chari;
//         }
// }

void fichier::Lire(bool mod) // if true :>> SEEK_SET else 0:>>SEEK_CUR
{
    char c;
    fseek(this->fd,0,int(mod));
        c = fgetc(this->fd);
    int counter = 0;
    while (c != EOF) {
        c = fgetc(this->fd);
        putchar(c);
       //fgets(bb,255,this->fd);
        //puts(bb);
        // return bb;
        }
}

//*************

int main(){
//  FILE *fp;
// fp=fopen("text.txt","r+");
 char *c= new char[50];
// while ((*c=fgetc(fp))!=EOF)
// {
// cout<<"\n here "<<*c;
// }
// fputs_unlocked("&nbs& ",fp);
// bool mod= true;
// fseek(fp,0,int(mod));
//     char buffer[255];
//     *c = fgetc(fp);
//     int counter = 0;
//     string test;
//     while (*c != EOF) {
//         *c = fgetc(fp);
//         putchar(*c);
//     }
    
// size_t i=0;
// while ((c+i)!=(char*)("\n"));
// {i++;
// putc(*c+i,stdout);
// }


fichier test;
test.Set_Noun("ach.txt");
test.Set_Mode("r+");
test.Set_Len(5);
test.openFile();
test.Lire(false);
test.Ecrire("new word /n",true); 
//cout<<test.Lire();//probleme du curseur;
//new.name="hammadi"

//string to char

/*char * strChar = new char[str.size() + 1];
std::copy(str.begin(), str.end(), strChar);
strChar[str.size()] = '\0'; */
//string str="test.txt";
//test.Set_Noun(str);
return 0;
} 