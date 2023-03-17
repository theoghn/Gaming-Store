#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include<windows.h>
using namespace std;

void ClearScreen()
{
    int n;
    for (n = 0; n < 3; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}
class Tastatura{
    private:
        const int IdProdus;
        static int contorID;
        string Nume;

        double LungimeCablu;
        int NrTaste;
        string TipSwitch;
        bool RGB;

    public:
        const int getIdProdus(){return IdProdus;};
        static int getContorId(){return Tastatura::contorID;};
        int getNrTaste(){return NrTaste;};
        string getNume(){return Nume;};
        double getLungimeCablu(){return LungimeCablu;};
        string getTipSwitch(){return TipSwitch;};
        bool getRGB(){return RGB;};

        void setNrTaste(int x){NrTaste = x;};
        void setNume(string x){this->Nume = x;};
        void setLungimeCablu(double x){LungimeCablu = x;};
        void setTipSwitch(string x){TipSwitch = x;};
        void setRGB(bool x){RGB = x;};

        Tastatura();
        Tastatura(string Nume,double LungimeCablu,string TipSwitch,bool RGB,int NrTaste);
        Tastatura(string Nume,string TipSwitch);
        Tastatura(string Nume);
        Tastatura(const Tastatura &obj);
        ~Tastatura();
        Tastatura &operator =(const Tastatura &obj);
        
        friend ostream& operator <<(ostream& out, const Tastatura& obj);
        friend istream& operator >>(istream& in, Tastatura& obj);
        Tastatura &operator++();
        Tastatura operator++(int);
        Tastatura operator+(int nr);
        friend Tastatura operator+(int nr, Tastatura &obj);
        operator string()const;
        friend bool operator<(const Tastatura &obj1, const Tastatura &obj2);
        friend bool operator==(const Tastatura &obj1, const Tastatura &obj2);
        //tip tastatura based pe nr de taste si tip switch lower()
        void TipTastatura();

        
};
void Tastatura::TipTastatura(){
    cout<< "Tastatura este ";
    int tip=0;
    if(NrTaste==88){
        cout<<"format TKL si ";
        tip=1;
    }
    else if(NrTaste>99 && NrTaste<104){
        cout<<"format 1800 si ";
        tip=1;
    }
    else if(NrTaste<88&& NrTaste>=84){
        cout<<"format Compact TKL si ";tip=1;
    }
    else if(NrTaste<70&& NrTaste>=62){
        cout<<"format 65'%' si ";tip=1;
    }
    else if(NrTaste==61){
        cout<<"format 60'%' si ";tip=1;
    }
    if(TipSwitch=="linear"){
        cout<<"silentioasa !"<<endl;tip=1;
    }
    if(TipSwitch=="tactil"){
        cout<<"zgomotoasa !"<<endl;tip=1;
    }
    if(TipSwitch=="clicky"){
        cout<<"foarte galagioasa !"<<endl;tip=1;
    }
    if(tip==0)
        cout<<"misterioasa."<<endl;
    


}
//constuctors Tastatura
Tastatura::Tastatura():IdProdus(contorID++){
    
    Nume = "Anonim";
    LungimeCablu = 0;
    TipSwitch = "Necunoscut";
    NrTaste = 0;
    RGB = NULL;
}
Tastatura::Tastatura(string Nume,double LungimeCablu,string TipSwitch,bool RGB,int NrTaste):IdProdus(contorID++){
    this->NrTaste = NrTaste;
    this->Nume = Nume;
    this->LungimeCablu = LungimeCablu;
    for(auto& c : TipSwitch)
    {
    c = tolower(c);
    };
    this->TipSwitch = TipSwitch;
    this->RGB = RGB;
}
Tastatura::Tastatura(string Nume,string TipSwitch):IdProdus(contorID++){
    this->Nume = Nume;
    this->TipSwitch = TipSwitch;
    RGB = NULL;
    LungimeCablu = 0;
    NrTaste = 0;

}
Tastatura::Tastatura(string Nume):IdProdus(contorID++){
    this->Nume = Nume;
    LungimeCablu = 0;
    NrTaste = 0;
    TipSwitch = "Necunoscut";
    RGB = NULL;
}
Tastatura::Tastatura(const Tastatura &obj):IdProdus(contorID++){
    this->NrTaste = obj.NrTaste;
    this->Nume = obj.Nume;
    this->LungimeCablu = obj.LungimeCablu;
    this->TipSwitch = obj.TipSwitch;
    this->RGB = obj.RGB;
}
//overloaded operators tastatura
Tastatura& Tastatura::operator =(const Tastatura &obj){
    if(this != &obj){
        this->NrTaste = obj.NrTaste;
        this->Nume = obj.Nume;
        this->LungimeCablu = obj.LungimeCablu;
        this->TipSwitch = obj.TipSwitch;
        this->RGB = obj.RGB;
    }
    return *this;
    
}
ostream& operator <<(ostream& out, const Tastatura&obj){
    out << "ID tastatura: " << obj.IdProdus << endl;
    out << "Nume tastatura: " << obj.Nume << endl;
    out << "Nr taste: "<< obj.NrTaste << endl;
    out << "Tip switch: " << obj.TipSwitch << endl;
    out << "Lungime cablu: " << obj.LungimeCablu << endl;
    if (obj.RGB == false){
        out << "RGB: Nu"<< endl;
    }
    else out << "RGB: Da" << endl;

    return out;
}
istream& operator >>(istream& in, Tastatura& obj){
    cout << "Nume tastatura: ";
    in >> obj.Nume;
    cout << "Tip switch: ";
    string tip;
    in >> tip;
    for(auto& c : tip)
    {
    c = tolower(c);
    };
    obj.TipSwitch=tip;
    cout << "Lungime cablu: ";
    in >> obj.LungimeCablu;
    cout << "Nr taste: ";
    in >> obj.NrTaste;
    cout << "(Introduceti [0/1]) RGB: ";
    in >> obj.RGB;
    return in;
}
Tastatura& Tastatura::operator++(){
    this -> NrTaste +=1;
    return *this;
}

Tastatura Tastatura::operator++(int){
    Tastatura copie = *this;
    this -> NrTaste +=1;
    return copie;
}
Tastatura Tastatura::operator+(int nr){
    this->NrTaste += nr;
    return *this;
}
Tastatura operator+(int nr , Tastatura &obj){
    obj.NrTaste+=nr;
    return obj;
};
Tastatura::operator string ()const{
    return this->Nume;
}
bool operator<(const Tastatura &obj1, const Tastatura &obj2){
    return (obj1.NrTaste<obj2.NrTaste);
}
bool operator==(const Tastatura &obj1, const Tastatura &obj2){
    if(obj1.NrTaste!=obj2.NrTaste||obj1.TipSwitch!=obj2.TipSwitch||obj1.LungimeCablu!=obj2.LungimeCablu||obj1.Nume!=obj2.Nume||obj1.RGB!=obj2.RGB)
        return 0;
    return 1;
}
Tastatura::~Tastatura(){
    Nume = "Anonim";
    LungimeCablu = 0;
    TipSwitch = "Necunoscut";
    NrTaste = 0;
    RGB = NULL;
}
class Mouse{
    private:
        const int IdProdus;
        static int contorID;
        string Nume;

        // S,M,L
        char Marime;
        int DPI;
        bool Wireless;

    public:
        const int getIdProdus(){return IdProdus;};
        static int getContorId(){return Mouse::contorID;};
        string getNume(){return Nume;};
        char getMarime(){return Marime;};
        int getDPI(){return DPI;};
        bool getWireless(){return Wireless;};

        void setNume(string x){Nume = x;};
        void setMarime(char x){Marime = x;};
        void setDPI(int x){DPI = x;};
        void setWireless(bool x){Wireless = x;};

        Mouse();
        Mouse(string Nume,char Marime,int DPI,bool Wireless);
        Mouse(string Nume,char Marime);
        Mouse(string Nume);
        Mouse(const Mouse &obj);
        ~Mouse();
        Mouse &operator =(const Mouse &obj);

        friend ostream& operator <<(ostream& out, const Mouse& obj);
        friend istream& operator >>(istream& out, Mouse& obj);
        Mouse &operator++();
        Mouse operator++(int);
        Mouse operator+(int nr);
        friend Mouse operator+(int nr, Mouse &obj);
        operator char()const;
        friend bool operator<(const Mouse &obj1, const Mouse &obj2);
        friend bool operator==(const Mouse &obj1, const Mouse &obj2);
        // daca dpi>20000 si wireless gama de top
        void isGOOD();

};
void Mouse::isGOOD(){
    if(DPI<20000)
        cout <<"Mouse-ul nu este in gama gaming de top"<<endl;
    else if(Wireless!=true)
        cout <<"Mouse-ul nu este in gama gaming de top"<<endl;
    else 
        cout <<"Mouse-ul este in gama gaming de top, optim pentru performante maxime in jocuri"<<endl;
}
//constuctors Mouse
Mouse::Mouse():IdProdus(contorID++){
    Nume = "Anonim";
    Marime = 'M';
    DPI = 0;
    Wireless = NULL;
}
Mouse::Mouse(string Nume,char Marime,int DPI,bool Wireless):IdProdus(contorID++){
    this->Nume = Nume;
    this->Marime = Marime ;
    this->DPI = DPI;
    this->Wireless = Wireless;
}
Mouse::Mouse(string Nume,char Marime):IdProdus(contorID++){
    this->Nume = Nume;
    this->Marime = Marime ;
    DPI = 0;
    Wireless = NULL;
}
Mouse::Mouse(string Nume):IdProdus(contorID++){
    this->Nume = Nume;
    Marime = 'M';
    DPI = 0;
    Wireless = NULL;
}
Mouse::Mouse(const Mouse &obj):IdProdus(contorID++){
    this->Nume = obj.Nume;
    this->Marime = obj.Marime;
    this->DPI = obj.DPI;
    this->Wireless = obj.Wireless;
}
//overloaded operators Mouse
Mouse& Mouse::operator =(const Mouse &obj){
    if(this != &obj){
        this->Nume = obj.Nume;
        this->Marime = obj.Marime;
        this->DPI = obj.DPI;
        this->Wireless = obj.Wireless;
    }
    return *this;
}
ostream& operator <<(ostream& out, const Mouse&obj){
    out << "ID mouse: " << obj.IdProdus << endl;
    out << "Nume mouse: " << obj.Nume << endl;
    out << "Marime mouse: " << obj.Marime << endl;
    out << "DPI: " << obj.DPI << endl;

    if (obj.Wireless == false){
        out << "Wireless: Nu"<< endl;
    }
    else out << "Wireless: Da" << endl;

    return out;
}
istream& operator >>(istream& in, Mouse& obj){
    cout << "Nume mouse: ";
    in >> obj.Nume;
    cout << "Marime mouse (S/M/L) : ";
    in >> obj.Marime;
    cout << "DPI: ";
    in >> obj.DPI;
    cout << "(Introduceti [0/1]) Wireless: ";
    in >> obj.Wireless;
    return in;
}
//+100 la Dpi
Mouse& Mouse::operator++(){
    this -> DPI +=100;
    return *this;
}

Mouse Mouse::operator++(int){
    Mouse copie = *this;
    this -> DPI +=100;
    return copie;
}
Mouse Mouse::operator+(int nr){
    this->DPI += nr;
    return *this;
}
Mouse operator+(int nr , Mouse &obj){
    obj.DPI+=nr;
    return obj;
};
Mouse::operator char()const{
    return this->Marime;
}
//compara alfabetic marimea S fiind cel mai mare de aia se produce inversiune la semne
bool operator<(const Mouse &obj1, const Mouse &obj2){
    return (obj1.Marime>obj2.Marime);
}
bool operator==(const Mouse &obj1, const Mouse &obj2){
    if(obj1.Nume!=obj2.Nume||obj1.Marime!=obj2.Marime||obj1.DPI!=obj2.DPI||obj1.Wireless!=obj2.Wireless)
        return 0;
    return 1;
}

Mouse::~Mouse(){
    Nume = "Anonim";
    Marime = 'M';
    DPI = 0;
    Wireless = NULL;
}

//note: 'MousePad::MousePad()' is implicitly deleted because the default definition would be ill-formed?????
class MousePad{
    private:
        const int IdProdus;
        static int contorID;
        string Nume;

        char *Culoare;
        // width , length ,height
        int *Dimensiuni;
    public:
        const int getIdProdus(){return IdProdus;};
        static int getContorId(){return MousePad::contorID;};
        string getNume(){return Nume;};
        char* getCuloare(){return Culoare;};
        int* getDimensiuni(){return Dimensiuni;};

        void setNume(string x){Nume = x;};
        void setDimensiuni(int* x);
        void setCuloare(char* x);

        MousePad();
        MousePad(string Nume,char *Culoare,int *Dimensiuni);
        MousePad(string Nume,int *Dimensiuni);
        MousePad(string Nume);
        MousePad(const MousePad &obj);
        ~MousePad();
        MousePad &operator =(const MousePad &obj);

        friend ostream& operator <<(ostream& out, const MousePad& obj);
        friend istream& operator >>(istream& out, MousePad& obj);
        MousePad &operator++();
        MousePad operator++(int);
        MousePad operator*(int nr);
        friend MousePad operator*(int nr, MousePad &obj);
        operator string()const;
        friend bool operator<(const MousePad &obj1, const MousePad &obj2);
        friend bool operator==(const MousePad &obj1, const MousePad &obj2);
        void isGaming();
        //gaming daca width si length mai mare de 30 mousepad gaming

};
void MousePad::isGaming(){
    if(Dimensiuni[0]>29&&Dimensiuni[1]>29&& Dimensiuni[2]>2){
        cout << "Mousepad bun pentru gaming!"<<endl;
    }
    else
        cout<<"Un mousepad office."<<endl;
    
}

//constuctors MousePad
MousePad::MousePad():IdProdus(contorID++){
    Nume = "Anonim";
    Culoare = new char[strlen("Necunoscut")+1];
    strcpy(Culoare,"Necunoscuta");
    Dimensiuni = NULL;
}
MousePad::MousePad(string Nume,char *Culoare,int *Dimensiuni):IdProdus(contorID++){
    this->Nume = Nume;
    this->Culoare = new char[strlen(Culoare)+1];
    strcpy(this->Culoare,Culoare);
    this->Dimensiuni = new int[3];
    this->Dimensiuni[0] = Dimensiuni[0];
    this->Dimensiuni[1] = Dimensiuni[1];
    this->Dimensiuni[2] = Dimensiuni[2];
}
MousePad::MousePad(string Nume,int *Dimensiuni):IdProdus(contorID++){
    this->Nume = Nume;
    Culoare = new char[strlen("Necunoscuta")+1];
    strcpy(Culoare,"Necunoscuta");
    this->Dimensiuni = new int[3];
    this->Dimensiuni[0] = Dimensiuni[0];
    this->Dimensiuni[1] = Dimensiuni[1];
    this->Dimensiuni[2] = Dimensiuni[2];
}
MousePad::MousePad(string Nume):IdProdus(contorID++){
    this->Nume = Nume;
    Culoare = new char[strlen("Necunoscuta")+1];
    strcpy(Culoare,"Necunoscuta");
    Dimensiuni = NULL;

}
MousePad::MousePad(const MousePad &obj):IdProdus(contorID++){
    this->Nume = obj.Nume;
    this->Culoare = new char[strlen(obj.Culoare)+1];
    strcpy(this->Culoare,obj.Culoare);
    for(int i=0;i<3;i++){
        this->Dimensiuni[i] = obj.Dimensiuni[i];
    }
}
//overloaded operators pentru Mousepad
MousePad& MousePad::operator =(const MousePad &obj){
    if(this != &obj){
        if (this->Culoare != NULL){
            delete[] this->Culoare;
            this->Culoare = NULL;
        }
        if (this->Dimensiuni != NULL){
            delete[] this->Dimensiuni;
            this->Dimensiuni = NULL;
        }

        this->Nume = obj.Nume;
        this->Culoare = new char[strlen(obj.Culoare)+1];
        strcpy(this->Culoare,obj.Culoare);
        this->Dimensiuni =  new int[3];
        for(int i=0;i<3;i++){
            this->Dimensiuni[i] = obj.Dimensiuni[i];
        }
    }
    return *this;
}
ostream& operator <<(ostream& out, const MousePad&obj){
    out << "ID mousepad: " << obj.IdProdus << endl;
    out << "Nume mousepad: " << obj.Nume << endl;
    out << "Culoare: " << obj.Culoare << endl;

    out << "Latime" << ": " << obj.Dimensiuni[0] << endl;
    out << "Lungime" << ": " << obj.Dimensiuni[1] << endl;
    out << "Grosime" << ": " << obj.Dimensiuni[2] << endl;

    return out;
}
istream& operator >>(istream& in, MousePad& obj){
    cout << "Nume mousepad: ";
    in >> obj.Nume;
    cout << "Culoare: ";
    char aux[30];
    in >> aux;
    if (obj.Culoare != NULL){
        delete[] obj.Culoare;
        obj.Culoare = NULL;
    }
    obj.Culoare = new char[strlen(aux)+1];
    strcpy(obj.Culoare,aux);


    if (obj.Dimensiuni != NULL){
        delete[] obj.Dimensiuni;
        obj.Dimensiuni = NULL;
    }
    obj.Dimensiuni = new int[3];
    cout <<"Latime, Lungime, Grosime " << endl;
    for (int i = 0; i < 3; i++){
        cout << "Dimensiunea " << i+1 << ": ";
        in >> obj.Dimensiuni[i];
    }
    

    return in;
}
//1 mm la grosime
MousePad& MousePad::operator++(){
    this -> Dimensiuni[2] +=1;
    return *this;
}

MousePad MousePad::operator++(int){
    MousePad copie = *this;
    this -> Dimensiuni[2] +=1;
    return copie;
}
MousePad MousePad::operator*(int nr){
    for (int i = 0; i < 3; i++)
    {
        this->Dimensiuni[i] *=nr;
    }
    return *this;
}
MousePad operator*(int nr , MousePad &obj){
    for (int i = 0; i < 3; i++)
    {
        obj.Dimensiuni[i] *=nr;
    }
    return obj;
};
MousePad::operator string()const{
    return this->Nume;
}
//length x width sa vada care e mai mare ca si suprafata
bool operator<(const MousePad &obj1, const MousePad &obj2){
    return ((obj1.Dimensiuni[0]*obj1.Dimensiuni[1])<(obj2.Dimensiuni[0]*obj2.Dimensiuni[1]));
}
bool operator==(const MousePad &obj1, const MousePad &obj2){
    if(strcmp(obj1.Culoare,obj2.Culoare)!=0)
        return 0;
    for (int i = 0; i < 3; i++)
    {
        if(obj1.Dimensiuni[i]!=obj2.Dimensiuni[i])
            return 0;
    }
    if(obj1.Nume!=obj2.Nume)
        return 0;
    
    return 1;
}

//destructor Mousepad
MousePad::~MousePad(){
    if (this->Culoare != NULL){
        delete[] this->Culoare;
        this->Culoare = NULL;
    }
    if (this->Dimensiuni != NULL){
        delete[] this->Dimensiuni;
        this->Dimensiuni = NULL;
    }
}


class Casti{
    private:
        const int IdProdus;
        static int contorID;
        string Nume;

        bool Microfon;
        double Sensibilitate_dB;
    public:
        const int getIdProdus(){return IdProdus;};
        static int getContorId(){return Casti::contorID;};
        string getNume(){return Nume;};
        bool getMicrofon(){return Microfon;};
        double getSensibilitate_dB(){return Sensibilitate_dB;};

        void setNume(string x){Nume = x;};
        void setMicrofon(bool x){Microfon = x;};
        void setSensibilitate_dB(double x){Sensibilitate_dB = x;};

        Casti();
        Casti(string Nume,bool Microfon,double Sensibilitate_dB);
        Casti(string Nume,double Sensibilitate_dB);
        Casti(string Nume);
        Casti(const Casti &obj);
        ~Casti(){};
        Casti &operator =(const Casti &obj);

        friend ostream& operator <<(ostream& out, const Casti& obj);
        friend istream& operator >>(istream& out, Casti& obj);
        Casti &operator++();
        Casti operator++(int);
        Casti operator+(int nr);
        friend Casti operator+(int nr, Casti &obj);
        operator double()const;
        friend bool operator<(const Casti &obj1, const Casti &obj2);
        friend bool operator==(const Casti &obj1, const Casti &obj2);
    //sensibilitate >40 si microfon sunt casti de streaming
        void isStreaming();
};
void Casti::isStreaming(){
    if(Sensibilitate_dB>40 && Microfon==true)
        cout<<"Casti profesionale pentru Streaming!"<<endl;
    else 
    cout<<"Casti normale."<<endl;
}
//setteri pt pointeri
void MousePad::setDimensiuni(int* x){
    Dimensiuni = new int[3];
    for(int i=0;i<3;i++){
        this->Dimensiuni[i] = x[i];
    }
}
void MousePad::setCuloare(char* x){
    Culoare = new char[strlen(x)+1];
    strcpy(Culoare,x);
}
int MousePad::contorID = 1;
int Casti::contorID = 1;
int Tastatura::contorID = 1;
int Mouse::contorID = 1;


//constuctors Casti
Casti::Casti():IdProdus(contorID++){
    Nume = "Anonim";
    Microfon = NULL;
    Sensibilitate_dB = 0;
}
Casti::Casti(string Nume,bool Microfon,double Sensibilitate_dB):IdProdus(contorID++){
    this->Nume = Nume;
    this->Microfon = Microfon;
    this->Sensibilitate_dB = Sensibilitate_dB;
}
Casti::Casti(string Nume,double Sensibilitate_dB):IdProdus(contorID++){
    this->Nume = Nume;
    this->Microfon = NULL;
    this->Sensibilitate_dB = Sensibilitate_dB;
}
Casti::Casti(string Nume):IdProdus(contorID++){
    this->Nume = Nume;
    this->Microfon = NULL;
    this->Sensibilitate_dB = 0;
}
Casti::Casti(const Casti &obj):IdProdus(contorID++){
    this->Nume = obj.Nume;
    this->Microfon = obj.Microfon;
    this->Sensibilitate_dB = obj.Sensibilitate_dB;
}
//overloaded operators Casti
Casti& Casti::operator =(const Casti &obj){
    if(this != &obj){
        this->Nume = obj.Nume;
        this->Microfon = obj.Microfon;
        this->Sensibilitate_dB = obj.Sensibilitate_dB;
    }
    return *this;
}
ostream& operator <<(ostream& out, const Casti&obj){
    out << "ID Casti: " << obj.IdProdus << endl;
    out << "Nume Casti: " << obj.Nume << endl;

    if (obj.Microfon == false){
        out << "Microfon: Nu"<< endl;
    }
    else out << "Microfon: Da" << endl;
    out << "Sensibilitate dB: " << obj.Sensibilitate_dB << endl;

    return out;
}
istream& operator >>(istream& in, Casti& obj){
    cout << "Nume Casti: ";
    in >> obj.Nume;
    cout << "Sensibilitate_dB: ";
    in >> obj.Sensibilitate_dB;
    cout << "(Introduceti [0/1]) Microfon: ";
    in >> obj.Microfon;
    return in;
}
Casti& Casti::operator++(){
    this -> Sensibilitate_dB +=0.1;
    return *this;
}

Casti Casti::operator++(int){
    Casti copie = *this;
    this -> Sensibilitate_dB +=0.1;
    return copie;
}
Casti Casti::operator+(int nr){
    this->Sensibilitate_dB += nr;
    return *this;
}
Casti operator+(int nr , Casti &obj){
    obj.Sensibilitate_dB+=nr;
    return obj;
};
Casti::operator double ()const{
    return this->Sensibilitate_dB;
}
bool operator<(const Casti &obj1, const Casti &obj2){
    return (obj1.Sensibilitate_dB<obj2.Sensibilitate_dB);
}
bool operator==(const Casti &obj1, const Casti &obj2){
    if(obj1.Sensibilitate_dB!=obj2.Sensibilitate_dB||obj1.Microfon!=obj2.Microfon||obj1.Nume!=obj2.Nume)
        return 0;
    return 1;
}


///int Tastatura::getContorId() {return Tastatura::contorID;}
/// conteaza daca e int sau static int avand in vedere ca tot ce face metoda mea e sa dea return?|||| also nu merge sa i dau static int
class Client{
    private:
        vector<Tastatura> Tastaturi;
        vector<Mouse> Mouseuri;
        vector<MousePad> MousePaduri;
        vector<Casti> VCasti;
    public:
        Client operator+(const Tastatura& t);
        Client operator+(const Mouse &m);
        Client operator+(const MousePad &mp);
        Client operator+(const Casti &c);
        friend Client operator+(const Tastatura& t, Client c);
        friend Client operator+(const Mouse &m, Client c);
        friend Client operator+(const MousePad &mp, Client c);
        friend Client operator+(const Casti &casti, Client c);
        friend ostream &operator<<(ostream &out, const Client &obj);
        
};
Client operator+(const Tastatura& t, Client c){
    return c+t;
};
Client operator+(const Mouse& m, Client c){
    return c+m;
};
Client operator+(const MousePad& mp, Client c){
    return c+mp;
};
Client operator+(const Casti& casti, Client c){
    return c+casti;
};
Client Client::operator+(const Tastatura &t)
{
    this->Tastaturi.push_back(t);
    return *this;
}
Client Client::operator+(const Mouse &m)
{
    this->Mouseuri.push_back(m);
    return *this;
}
Client Client::operator+(const MousePad &mp)
{
    this->MousePaduri.push_back(mp);
    return *this;
}
Client Client::operator+(const Casti &c)
{
    this->VCasti.push_back(c);
    return *this;
}
ostream &operator<<(ostream &out, const Client &obj)
{
    out << "\n Tastaturi:";
    for (auto i : obj.Tastaturi)
    {
        out << endl;
        out << i;
    }
    out << "\n\n Mouse-uri:";
    for (auto i : obj.Mouseuri)
    {
        out << endl;
        out << i;
    }
    out << "\n\n MousePad-uri:";
    for (auto i : obj.MousePaduri)
    {
        out << endl;
        out << i;
    }
    out << "\n\n Casti:";
    for (auto i : obj.VCasti)
    {
        out << endl;
        out << i;
    }
    out << endl;

    return out;
}

int main(){

    
    Casti listaCasti[100];
    MousePad listaMousePad[100];
    Mouse listaMouse[100];
    Tastatura listaTastatura[100];

    int contorTastatura=1;
    int contorCasti=1;
    int contorMousePad=1;
    int contorMouse=1;

    double k=0;
    
    Tastatura t1,t2("Razer Huntsman",3,"Linear",true,80);
    Mouse m1("Razer Deathaddder",'M',28000,true);
    listaMouse[0]= m1;
    listaTastatura[0]= t2;
    int nr[] =  {45,40,3};
    char c[] = "Red";
    MousePad mp1("Artisan",c,nr);
    listaMousePad[0] = mp1;
    Casti casti1("Steelseries",true,50);
    listaCasti[0]=casti1;

    
    Client c1;
    cout<<c1;
    int contorClienti=1;
    int indexClienti=0;

    t2.TipTastatura();
    while(k==0){
        ClearScreen();
        int meniu;
        cout<<"\n1-Client;";
        cout<<"\n2-Admin;";
        cin>>meniu;
        if(meniu==1){
            k=1;
        }
        if(meniu==2){
            k=2;
        }

    while(k==1){
        ClearScreen();
        int comanda;
        cout<<"\n1-Adauga Tastatura in cos;";
        cout<<"\n2-Adauga Casti in cos;";
        cout<<"\n3-Adauga MousePad in cos;";
        cout<<"\n4-Adauga Mouse in cos;";
        cout<<"\n5-Vezi cos;";
        cout<<"\n0-Return;"<<endl;

        cin>>comanda;
        switch(comanda){
            case 1:{
                ClearScreen();
                cout<<"\nLista Tastatura:"<<endl;
                for(int i=0; i<contorTastatura;i++)
                    cout<<listaTastatura[i]<<endl;
                int idd;
                cout<<"\n Adauga Tastatura cu id:";
                cin>> idd;
                c1+listaTastatura[idd-1];    
                break;
                }
            case 2:{
                ClearScreen();
                cout<<"\nLista Casti:"<<endl;
                for(int i=0; i<contorCasti;i++)
                    cout<<listaCasti[i]<<endl;
                int idd;
                cout<<"\n Adauga Casti cu id:";
                cin>> idd;
                c1+listaCasti[idd-1];           
                break;
                }
            case 3:{
                ClearScreen();
                cout<<"\nLista Mouse:"<<endl;
                for(int i=0; i<contorMouse;i++)
                    cout<<listaMouse[i]<<endl;
                int idd;
                cout<<"\n Adauga Mouse cu id:";
                cin>> idd;
                c1+listaMouse[idd-1];   

                
                break;
                }
            case 4:{
                ClearScreen();
                cout<<"\nLista MousePad:"<<endl;
                for(int i=0; i<contorMousePad;i++)
                    cout<<listaMousePad[i]<<endl;
                int idd;
                cout<<"\n Adauga MousePad cu id:";
                cin>> idd;
                c1+listaMousePad[idd-1];   
                break;
            }
            case 5:{
                ClearScreen();
                cout<<c1;
                cout<<endl<<"0-Meniu"<<endl;
                string arrr;
                cin>>arrr;
                  
                break;
            }
            case 0:{
                
                k=0;
                break;
            }
            default:{
                cout<<"\n\tComanda Necunoscuta";
            }
            break;
        }
        

    }

    while(k==2){
        ClearScreen();
        int comanda;
        cout<<"\n1-Citeste obiect;";
        cout<<"\n2-Afiseaza Lista Obiecte;";
        cout<<"\n3-Modifica Obiect;";
        cout<<"\n4-Sterge Obiect;";
        cout<<"\n0-STOP"<<endl;
        cin>>comanda;
        switch (comanda){
        case 1:{
            ClearScreen();
            int comanda2;
            cout<<"\n1-Citeste Detalii Tastatura;";
            cout<<"\n2-Citeste Detalii Casti;";
            cout<<"\n3-Citeste Detalii MousePad;";
            cout<<"\n4-Citeste Detalii Mouse;"<<endl;
            cin>>comanda2;
            switch(comanda2){
                case 1:{
                    Tastatura c;
                    cin>>c;
                    listaTastatura[contorTastatura]=c;
                    contorTastatura++;
                    break;
                }
                case 2:{
                    Casti c;
                    cin>>c;
                    listaCasti[contorCasti]=c;
                    contorCasti++;
                    break;
                }
                case 3:{
                    MousePad c;
                    cin>>c;                  
                    listaMousePad[contorMousePad]=c;
                    contorMousePad++;
                    
                    break;
                }
                case 4:{
                    Mouse c;
                    cin>>c;
                    listaMouse[contorMouse]=c;
                    contorMouse++;
                    break;
                }
                default:{
                    cout<<"\n\tComanda Necunoscuta";
                }
            }
            break;
            }
        case 2:{

            ClearScreen();
            
            cout<<"Lista Tastatura:"<<endl;
            for(int i=0; i<contorTastatura;i++)
                cout<<listaTastatura[i]<<endl;
            cout<<"Lista Casti:"<<endl;
            for(int i=0; i<contorCasti;i++)
                cout<<listaCasti[i]<<endl;
            cout<<"Lista MousePad:"<<endl;
            for(int i=0; i<contorMousePad;i++)
                cout<<listaMousePad[i]<<endl;
            cout<<"Lista Mouse:"<<endl;
            for(int i=0; i<contorMouse;i++)
                cout<<listaMouse[i]<<endl;
            string p;
            cin >>p;

            
            break;
            }
        case 3:{
            ClearScreen();
            int comanda3;
            cout<<"\n1-Modifica Detalii Tastatura;";
            cout<<"\n2-Modifica Detalii Casti;";
            cout<<"\n3-Modifica Detalii MousePad;";
            cout<<"\n4-Modifica Detalii Mouse;"<<endl;
            cin>>comanda3;
            switch(comanda3){
                case 1:{
                    ClearScreen();
                    cout<<"\nLista Tastatura:"<<endl;
                    for(int i=0; i<contorTastatura;i++)
                        cout<<listaTastatura[i]<<endl;
                    int idd;
                    cout<<"\n Modifica Tastatura cu id:";
                    cin>> idd;
                    cout<<"\n Nume nou:";
                    string nume;
                    cin >> nume;
                    
                    listaTastatura[idd-1].setNume(nume);
                    cout<< "pr";
                    
                    break;
                }
                case 2:{
                    ClearScreen();
                    cout<<"Lista Casti:"<<endl;
                    for(int i=0; i<contorCasti;i++)
                        cout<<listaCasti[i]<<endl;
                    int idd;
                    cout<<"\n Modifica Casti cu id:";
                    cin>> idd;
                    cout<<"\n Nume nou:";
    
                    string nume;
                    cin >> nume;
                    
                    listaCasti[idd-1].setNume(nume);
                    cout<< "pr";
                    
                    break;
                }
                case 3:{
                    ClearScreen();
                    cout<<"Lista MousePad:"<<endl;
                    for(int i=0; i<contorMousePad;i++)
                        cout<<listaMousePad[i]<<endl;
                    int idd;
                    cout<<"\n Modifica MousePad cu id:";
                    cin>> idd;
                    cout<<"\n Nume nou:";
                    
                    string nume;
                    cin >> nume;
                    
                    listaMousePad[idd-1].setNume(nume);
                    cout<< "pr";
                    
                    break;
                }
                case 4:{
                    ClearScreen();
                    cout<<"Lista Mouse:"<<endl;
                    for(int i=0; i<contorMouse;i++)
                        cout<<listaMouse[i]<<endl;
                    int idd;
                    cout<<"\n Modifica Mouse cu id:";
                    cin>> idd;
                    cout<<"\n Nume nou:";
    
                    string nume;
                    cin >> nume;
                    
                    listaMouse[idd-1].setNume(nume);
                    cout<< "pr";
                    
                    break;
                }
                default:{
                    cout<<"\n\tComanda Necunoscuta";
                }
            }
            
            break;
            }
        case 4:{
            ClearScreen();
            int comanda2;
            cout<<"\n1-Sterge Detalii Tastatura;";
            cout<<"\n2-Sterge Detalii Casti;";
            cout<<"\n3-Sterge Detalii MousePad;";
            cout<<"\n4-Sterge Detalii Mouse;"<<endl;
            cin>>comanda2;
            switch(comanda2){
                case 1:{
                    ClearScreen();
                    cout<<"\nLista Tastatura:"<<endl;
                    for(int i=0; i<contorTastatura;i++)
                        cout<<listaTastatura[i]<<endl;
                    int idd;
                    cout<<"\n Sterge Tastatura cu id:";
                    cin>> idd;
                    if(idd>0&&idd<=contorTastatura){
                        for (size_t i = idd-1; i < contorTastatura-1; i++)
                        {
                            listaTastatura[i] = listaTastatura[i+1];
                        }
                        
                        contorTastatura--;

                    }
                    cout<< "pr";

                    
                    
                    break;
                }
                case 2:{
                    ClearScreen();
                    cout<<"Lista Casti:"<<endl;
                    for(int i=0; i<contorCasti;i++)
                        cout<<listaCasti[i]<<endl;
                    int idd;
                    cout<<"\n Modifica Casti cu id:";
                    cin>> idd;
                    if(idd>0&&idd<=contorCasti){
                        for (size_t i = idd-1; i < contorCasti-1; i++)
                        {
                            listaCasti[i] = listaCasti[i+1];
                        }
                        
                        contorCasti--;

                    }
                    
                    
                    break;
                }
                case 3:{
                    ClearScreen();
                    cout<<"Lista MousePad:"<<endl;
                    for(int i=0; i<contorMousePad;i++)
                        cout<<listaMousePad[i]<<endl;
                    int idd;
                    cout<<"\n Modifica MousePad cu id:";
                    cin>> idd;
                    if(idd>0&&idd<=contorMousePad){
                        for (size_t i = idd-1; i < contorMousePad-1; i++)
                        {
                            listaMousePad[i] = listaMousePad[i+1];
                        }
                        
                        contorMousePad--;

                    }
                    
                    
                    break;
                }
                case 4:{
                    ClearScreen();
                    cout<<"Lista Mouse:"<<endl;
                    for(int i=0; i<contorMouse;i++)
                        cout<<listaMouse[i]<<endl;
                    int idd;
                    cout<<"\n Modifica Mouse cu id:";
                    cin>> idd;
                    if(idd>0&&idd<=contorMouse){
                        for (size_t i = idd-1; i < contorMouse-1; i++)
                        {
                            listaMouse[i] = listaMouse[i+1];
                        }
                        
                        contorMouse--;

                    }
                    
                    break;
                }
                default:{
                    cout<<"\n\tComanda Necunoscuta";
                }
                
            }
            break;
        }   
        case 0:{
            ClearScreen();
            k=0;
            break;
            }
        default:{
            cout<<"\n\tComanda Necunoscuta";
        }


       }

    }

    }
    return 0;
}