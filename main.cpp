#include <iostream>
#include <string.h>
using namespace std;

class Agenda
{
    public:
 virtual void citire(istream & i)=0;
 virtual void afisare(ostream & o)=0;
 virtual char* get_nume()=0;
};

class Persoana:public Agenda
{
    int id;
    char nume[30];
    public:
    Persoana(int id1=0,char nume1[30]=" ")
    {
        id=id1;
        strcpy(nume,nume1);
    }
    Persoana(const Persoana &ob)
    {
        id=ob.id;
        strcpy(nume,ob.nume);
    }
    ~Persoana();
    char* get_nume()
    {
        return nume;
    }
    void citire(istream &i)
    {
        cout<<"id=";
        i>>id;
        cout<<"nume=";
        i>>nume;
    }
    void afisare(ostream &o)
    {
        o<<id<<" "<<nume<<" ";
    }



};

class Abonat:public Persoana
{
    int nr_tel;
    public:
    Abonat(int nr_tel1=0):Persoana()
    {
        nr_tel=nr_tel1;
    }
   Abonat(const Abonat &ob):Persoana(ob)
   {
       nr_tel=ob.nr_tel;
   }
   ~Abonat();
    void citire(istream &i)
    {
        Persoana::citire(i);
        cout<<"nr_telefon=";
        i>>nr_tel;
    }
    void afisare(ostream &o)
    {
        Persoana::afisare(o);
        o<<nr_tel<<" ";
    }
};

class Abonat_Skype:public Abonat
{
    int id_skype;
    public:
    Abonat_Skype(int id_skype1=0):Abonat()
    {
        id_skype=id_skype1;
    }
       Abonat_Skype(const Abonat_Skype &ob):Abonat_Skype(ob)
   {
       id_skype=ob.id_skype;
   }
   ~Abonat_Skype();
    void citire(istream &i)
    {
        Abonat::citire(i);
        cout<<"id_skype=";
        i>>id_skype;
    }
     void afisare(ostream &o)
    {
        Abonat::afisare(o);
        o<<id_skype<<" ";
    }
};

class Abonat_Skype_Romania:public Abonat_Skype
{
    char adresa_mail[30];
    public:
    Abonat_Skype_Romania(char adresa[30]=" "):Abonat_Skype()
    {
        strcpy(adresa_mail,adresa);
    }
     Abonat_Skype_Romania(const Abonat_Skype_Romania &ob):Abonat_Skype_Romania(ob)
   {
       strcpy(adresa_mail,ob.adresa_mail);
   }
   ~Abonat_Skype_Romania();
    void citire(istream &i)
    {
        Abonat_Skype::citire(i);
        cout<<"adresa_mail=";
        i>>adresa_mail;
    }
     void afisare(ostream &o)
    {
        Abonat_Skype::afisare(o);
        o<<adresa_mail<<" ";
    }
};

class Abonat_Skype_Extern:public Abonat_Skype
{

    char tara[30];
    public:
    Abonat_Skype_Extern(char tara1[30]=" "):Abonat_Skype()
    {
        strcpy(tara,tara1);
    }
     Abonat_Skype_Extern(const Abonat_Skype_Extern &ob):Abonat_Skype(ob)
   {
       strcpy(tara,ob.tara);
   }
   ~Abonat_Skype_Extern();
    void citire(istream &i)
    {
        Abonat_Skype::citire(i);
        cout<<"tara=";
        i>>tara;
    }
     void afisare(ostream &o)
    {
        Abonat_Skype::afisare(o);
        o<<tara<<" ";
    }
};


istream& operator >>(istream &i,Agenda &ob)
{
    ob.citire(i);
    return i;
}

ostream & operator <<(ostream &o,Agenda &ob)
{
    ob.afisare(o);
    return o;
}

 Agenda *Vob[5];

int index(char* s,int n)
{
    int i;
    char s2[20];
    for(i=0;i<n;i++)
    {
            strcpy(s2,Vob[i]->get_nume());
        if(strcmp(s,s2)==0)
            return i;
    }
    return -1;
}


int main()
{

     cout<<"Persoana: \n";
    Vob[0]=new Persoana();
    cin>>(*Vob[0]);
    cout<<(*Vob[0]);
    cout<<"\n";
    cout<<"Abonat: \n";
    Vob[1]=new Abonat();
    cin>>(*Vob[1]);
    cout<<(*Vob[1]);
    cout<<"\n";
    cout<<"Abonat_Skype: \n";
    Vob[2]=new Abonat_Skype();
    cin>>(*Vob[2]);
    cout<<(*Vob[2]);
    cout<<"\n";
    cout<<"Abonat_Skype_Romania: \n";
    Vob[3]=new Abonat_Skype_Romania();
    cin>>(*Vob[3]);
    cout<<(*Vob[3]);
    cout<<"\n";
    cout<<"Abonat_Skype_Extern: \n";
    Vob[4]=new Abonat_Skype_Extern();
    cin>>(*Vob[4]);
    cout<<(*Vob[4]);
    cout<<"\n";
    cout<<"ob: ";
    Agenda *ob;
    ob=Vob[0];
    cout<<(*ob);
    cout<<"\n";
    char nume_cautat[20];
    cout<<"Nume cautat: ";
    cin>>nume_cautat;
    int rez;
    rez=index(nume_cautat,5);
    if(rez==-1)
        cout<<"nu exista persoana cautata";
    else
        cout<<"id-ul persoanei cautate este "<<rez;
    return 0;
}
