#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <functional>

// Program w założeniaach ma zarządzać pracami dyplomowymi studentów 

using namespace std;

class praca
{
    int id;
    int rok;
    char typPracy[4];
    char tytul[100];
    char nazwiskoAutora[30];
    char imionaAutora[40];
    char nazwiskoPromotora[30];
    char imionaPromotora[40];
    char slowaKluczowe[150];
    char streszczenie[1000];

public:
    praca()
    {

    }
    praca(int id, string a, string b, string c, string d, int rok, string e, string f, string g, string h)
    {
        this->id = id;
        this->rok = rok;
        strcpy(typPracy, a.c_str());
        strcpy(tytul, b.c_str());
        strcpy(nazwiskoAutora, c.c_str());
        strcpy(imionaAutora, d.c_str());
        strcpy(nazwiskoPromotora, e.c_str());
        strcpy(imionaPromotora, f.c_str());
        strcpy(slowaKluczowe, g.c_str());
        strcpy(streszczenie, h.c_str());
    }

    int getID() { return id; }
    int getRok() { return rok; }
    string getTypPracy() { return typPracy; }
    string getTytul() { return tytul; }
    string getImieAutora() { return imionaAutora; }
    string getNazwiskoAutora() { return nazwiskoAutora; }
    string getImiePromotora() { return imionaPromotora; }
    string getNazwiskoPromotora() { return nazwiskoPromotora; }
    string getSlowaKluczowe() { return slowaKluczowe; }
    string getStreszczenie() { return streszczenie; }

    void setID(int id) { this->id = id; }
    void setRok(int rok) { this->rok = rok; }
    void setTypPracy(string a) { strcpy(typPracy, a.c_str()); }
    void setTytul(string b) {  strcpy(tytul, b.c_str()); }
    void setNazwiskoAutora(string c) {  strcpy(nazwiskoAutora, c.c_str()); }
    void setImieAutora(string d) { strcpy(imionaAutora, d.c_str());}
    void setNazwiskoPromotora(string e) { strcpy(nazwiskoPromotora, e.c_str());}
    void setImionaPromotora(string f) { strcpy(imionaPromotora, f.c_str()); }
    void setSlowaKluczowe(string g) { strcpy(slowaKluczowe, g.c_str()); }
    void setStreszczenie(string h) { strcpy(streszczenie, h.c_str()); }

    void wyswietlSkrt()
    {
        cout << id << ". " << typPracy << " " << imionaAutora[0] << ". " << nazwiskoAutora << " ,," << tytul << "'' " << rok << endl;
    }
};

class biblioteka
{   
    vector<praca> p;
    int ilePrac = p.size();

    public:
    void des()
    {
        fstream file;
        string typPracy;
        string tytul;
        string nazwiskoAutora;
        string imieAutora;
        int rok, id;
        string nazwiskoPromotora;
        string imionaPromotora;
        string slowaKluczowe;
        string streszczenie;        

        file.open("prace.txt");
        do{
        file>>id>>typPracy>>tytul>>imieAutora>>nazwiskoAutora>>rok>>imionaPromotora>>nazwiskoPromotora>>slowaKluczowe>>streszczenie;
        for(int i=0; i<streszczenie.length(); i++){
                if(streszczenie[i]=='_'){
                    streszczenie[i]=' ';
                }
            }
            for(int i=0; i<slowaKluczowe.length(); i++){
                if(slowaKluczowe[i]=='_'){
                    slowaKluczowe[i]=' ';
                }
            }
            for(int i=0; i<tytul.length(); i++){
                if(tytul[i]=='_'){
                    tytul[i]=' ';
                }
            }
            for(int i=0; i<imieAutora.length(); i++){
                if(imieAutora[i]=='_'){
                    imieAutora[i]=' ';
                }
            }
            for(int i=0; i<imionaPromotora.length(); i++){
                if(imionaPromotora[i]=='_'){
                    imionaPromotora[i]=' ';
                }
            }
            p.push_back({id, typPracy, tytul, nazwiskoAutora, imieAutora, rok, nazwiskoPromotora, imionaPromotora, slowaKluczowe, streszczenie});   
        }while(!file.eof());
        file.close();
    }
    void ser()
    {
        ofstream { "prace.txt" };
        fstream file;
        string streszczenietmp , slowatmp, tytultmp,imionaAtmp, imionaPtmp;
        file.open("prace.txt");
        for(int i = 0; i<p.size(); i++){
            streszczenietmp=p[i].getStreszczenie();
            slowatmp = p[i].getSlowaKluczowe();
            tytultmp = p[i].getTytul();
            imionaAtmp = p[i].getImieAutora();
            imionaPtmp=p[i].getImiePromotora();
            for(int i=0; i<streszczenietmp.length(); i++){
                if(streszczenietmp[i]==' '){
                    streszczenietmp[i]='_';
                }
            }
            for(int i=0; i<slowatmp.length(); i++){
                if(slowatmp[i]==' '){
                    slowatmp[i]='_';
                }
            }
            for(int i=0; i<tytultmp.length(); i++){
                if(tytultmp[i]==' '){
                    tytultmp[i]='_';
                }
            }
            for(int i=0; i<imionaAtmp.length(); i++){
                if(imionaAtmp[i]==' '){
                    imionaAtmp[i]='_';
                }
            }
            for(int i=0; i<imionaPtmp.length(); i++){
                if(imionaPtmp[i]==' '){
                    imionaPtmp[i]='_';
                }
            }
            file<<p[i].getID()<<" "<<p[i].getTypPracy()<<" "<<tytultmp<<" "<<imionaAtmp<<" "<<p[i].getNazwiskoAutora()<<" "<<p[i].getRok()<<" "<<imionaPtmp<<" "<<p[i].getNazwiskoPromotora()<<" "<<slowatmp<<" "<<streszczenietmp; 
            if(i!=p.size()-1){
                file<<endl;
            }
        }
        file.close();
    }
    void dane()
    {
        p.push_back({1,"mgr", "Algorytmy genetyczne w problemie TSP", "Nowak", "Adam",2009, "Kowalski", "Jan", "algorytmy genetyczne; problem komiwojazera; TSP", "Praca porownuje wplyw wybranych metod kodowania osobnikow w klasycznym algorytmie genetycznym."  });
        p.push_back({2,"mgr", "Implementing a GPU-based parallel MAX–MIN Ant System","Bedkowski", "Emilian",2007, "Kowalski", "Jan", "Ant System; GPU", "Praca praca omawia optymalizacje algorytmow dzialajacych w sposob podobny do kolonii mrowek."  });
        p.push_back({3,"lic", "Aplikacja obsługująca strumieniowanie danych GPS", "Kolodziej", "Jakub",2007, "Bedkowski", "Robert", "GPS", "W ramach pracy stworzona zostanie aplikacja obsługująca połączenia i strumieniowanie danych z rejestratora GPS."  });
        p.push_back({4,"mgr", "Analiza danych w nowoczesnym futbolu", "Sikora", "Piotr",2011, "Kowalski", "Jan", "dane; data", "Stworzenie bazy danych parametrów powiązanych z wybranymi zawodnikami. Analiza danych na podstawie technik stosowanych przez scouting największych klubów na świecie."});
        p.push_back({5,"inz", "Aplikacja webowa służąca do rekomendacji oparta na metodach sztucznej inteligencji.", "Nowak", "Katarzyna",2012, "Bedkowski", "Robert", "SI; Web", "Celem pracy jest opracowanie aplikacji internetowej posiadającej system rekomendacji. Rekomendacja wesprze użytkownika w wyborze odpowiedniej pozycji."  });
        p.push_back({6,"inz", "Konteneryzacja aplikacji bazodanowych w chmurze", "Bedkowska", "Anna",2006, "Bedkowski", "Robert", "chmura; Azure", "Celem pracy jest stworzenie systemu bazodanowego w oparciu o chmurę Azure"  });
        p.push_back({7,"lic", "Zastosowanie sztucznej inteligencji w rozgrywce gry „League of Legends”", "Bedkowski", "Dariusz",2011, "Nowak", "Arkadiusz", "SI; gry", "Stworzenie systemu sztucznej inteligencji rozgrywającego gry w „League of Legends”."  });
        p.push_back({8,"mgr", "Interfejs do systemu użytkowników w projekcie CREDO", "Gil", "Marta",2015, "Nowak", "Arkadiusz", "UI; aplikacje", "W ramach pracy stworzony zostanie interfejs dla użytkowników projektu CREDO. Zadaniem dyplomanta jest przeprowadzenie analizy potrzeb wśród grupy użytkowników i implementacja zadanych funkcjonalności. "  });
        p.push_back({9,"inz", "Automaty komórkowe w zagadnieniach symulacji", "Nowak", "Oliwia",2010, "Kowalski", "Jan", "algorytmy; automatyka", "Wykorzystanie automatów komórkowych w różnych zagadnieniach symulacji (transport ciepła, wrost kryształów)"  });
        p.push_back({10,"lic", "Linux kernel guidelines", "Torvalds", "Linus",2015, "Nowak", "Arkadiusz", "kernel; linux", "How to properly write code for linux kernel"  });
        
    
    }
    void wyswietlListe()
    {
        for (int i = 0; i < p.size(); i++)
        {
            p[i].wyswietlSkrt();
        }
    }

    void wyswietl(int i)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Id:             " << p[i].getID() << endl;
        cout << "Typ:            " << p[i].getTypPracy() << endl;
        cout << "Autor:          " << p[i].getImieAutora() << " " << p[i].getNazwiskoAutora() << endl;
        cout << "Tytuł:          " << p[i].getTytul() << endl;
        cout << "Slowa kluczowe: " << p[i].getSlowaKluczowe() << endl;
        cout << "Rok:            " << p[i].getRok() << endl;
        cout << "Promotor:       " << p[i].getImiePromotora() << " " << p[i].getNazwiskoPromotora() << endl;
        cout << "Streszczenie:   " << p[i].getStreszczenie() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void wyswietlPelna()
    {
        for (int i = 0; i < p.size(); i++)
        {
            wyswietl(i);
        }
    }

    void dodajPrace()
    {
        bool check;
        int id = p.size()+1;
        string typPracy;
        string tytul;
        string nazwiskoAutora;
        string imieAutora;
        int rok;
        string nazwiskoPromotora;
        string imionaPromotora;
        string slowaKluczowe;
        string streszczenie;
        check = false;
            while(!check){
                cout<< "Dopuszczalne typy to lic/inz/mgr"<<endl;
                cout << "Prosze podac typ pracy: ";
                cin >> typPracy;
                if((typPracy.compare("lic")==0)||(typPracy.compare("mgr")==0)||(typPracy.compare("inz")==0)){
                    check = true;
                    break;
                }
                cout<<"Bledny typ,\nProsze sprobowac ponownie. "<<endl;
            }
        cin.ignore();
        cout << "Prosze podac tytul: ";
        getline(cin, tytul);
        cout << "Prosze podac imiona autora: ";
        getline(cin, imieAutora);
        cout << "Prosze podac nazwisko autora: ";
        getline(cin, nazwiskoAutora);
        check = false;
            while(!check){
                cout << "Prosze wpisac rok: ";
                cin >> rok;
                if(rok>2000){
                    check = true;
                    break;
                }
                cout<<"Bledny rok,\nProsze sprobowac ponownie. "<<endl;
            }
        cout << "Prosze podac imiona promotora: ";
        cin.ignore();
        getline(cin, imionaPromotora);
        cout << "Prosze podac nazwisko promotora: ";
        getline(cin, nazwiskoPromotora);
        cout << "Prosze podac slowa kluczowe: ";
        getline(cin, slowaKluczowe);
        cout << "Prosze napisac streszczenie: ";
        getline(cin,streszczenie);
        p.push_back({id, typPracy, tytul, nazwiskoAutora, imieAutora, rok, nazwiskoPromotora, imionaPromotora, slowaKluczowe, streszczenie});
        cin.ignore();
        cout << "Praca dodana pomyślnie!" << endl;
    }

    void edytujPrace(int i)
    {
        wyswietl(i);
        cout << "Ktora skladowa chcesz edytowac?" << endl;
        int wybor=0;
        int tmpInt;
        bool check;
        string tmpString;
        cout << "1. Id\n2. Typ pracy\n3. Tytul\n4. Imiona autora\n5. Nazwisko autora\n6. Rok\n7. Imiona protektora\n8. Nazwisko protektora\n9. Slowa kluczowe\n10. Streszczenie." << endl;
        cout << "Prosze wybrac numer: ";
        cin>>wybor;
        cin.ignore();
        switch (wybor)
        {
        case 1:
            cout << "Prosze wpisac nowe Id: ";
            cin >> tmpInt;
            p[i].setID(tmpInt);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 2:
            check = false;
            while(!check){
                cout<< "Dopuszczalne typy to lic/inz/mgr"<<endl;
                cout << "Prosze wpisac nowy typ: ";
                cin >> tmpString;
                if((tmpString.compare("lic")==0)||(tmpString.compare("mgr")==0)||(tmpString.compare("inz")==0)){
                    check = true;
                    break;
                }
                cout<<"Bledny typ,\nProsze sprobowac ponownie. "<<endl;
            }
            p[i].setTypPracy(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 3:
             cout << "Prosze wpisac nowy tytul: ";
            getline(cin, tmpString);
            p[i].setTytul(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 4:
            cout << "Prosze wpisac nowe imiona autora: ";
            getline(cin, tmpString);
            p[i].setImieAutora(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 5:
            cout << "Prosze wpisac nowe nazwisko autora: ";
            getline(cin, tmpString);
            p[i].setNazwiskoAutora(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 6:
            check = false;
            while(!check){
                cout << "Prosze wpisac nowy rok: ";
                cin >> tmpInt;
                if(tmpInt>2000){
                    check = true;
                    break;
                }
                cout<<"Bledny rok,\nProsze sprobowac ponownie. "<<endl;
            }
            p[i].setRok(tmpInt);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 7:
            cout << "Prosze wpisac nowe imiona promotora: ";
            getline(cin, tmpString);
            p[i].setImionaPromotora(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 8:
            cout << "Prosze wpisac nowe nazwisko promotora: ";
            getline(cin, tmpString);
            p[i].setNazwiskoPromotora(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 9:
            cout << "Prosze wpisac nowe slowa kluczowe: ";
            getline(cin, tmpString);
            p[i].setSlowaKluczowe(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        case 10:
            cout << "Prosze wpisac nowe streszczenie: ";
            getline(cin, tmpString);
            p[i].setStreszczenie(tmpString);
            cout << "Operacja zakonczona pomyslnie" << endl;
            break;
        }
    }

    void wyszukajPrace()
    {
        cout << "Po jakim kryterium chcesz szukać?" << endl;
        int wybor = 0;
        bool check;
        int tmpInt;
        string tmp;
        string tmpString;
        cout << "1. Nazwisko autora\n2. Nazwisko protektora\n3. Tytul\n4. Slowa kluczowe\n5. Streszczenie\n6. Rok powstania" << endl;
        cout << "Prosze wybrac numer: ";
        cin >> wybor;
        cin.ignore();
        switch (wybor)
        {
        case 1:
        {
            cout << "Prosze wpisac szukane nazwisko autora: ";
            getline(cin, tmpString);
            cin.ignore();
            for (auto w : p)
            {
                tmp = w.getNazwiskoAutora();
                if (tmp.compare(0,tmpString.length()-1, tmpString, 0 ,tmpString.length()-1 )==0)
                {
                    w.wyswietlSkrt();
                }
            }
            break;
        }
        case 2:
        {
            cout << "Prosze wpisac szukane nazwisko promotora: ";
            getline(cin, tmpString);
            for (auto w : p)
            {
                tmp = w.getNazwiskoPromotora();
                if (tmp.compare(0,tmpString.length()-1, tmpString, 0 ,tmpString.length()-1 )==0)
                {
                    w.wyswietlSkrt();
                }
            }
            break;
        }
        case 3:
        {
            cout << "Prosze wpisac szukany tytul: ";
            cin >> tmpString;
            for (auto w : p){
                check = false;
                tmp = w.getTytul();
                for(int i = 0; i<tmp.length(); i++){
                    if(tmp[i]==tmpString[0]){
                        if(tmp.compare(i, tmpString.length()-1, tmpString, 0, tmpString.length()-1)==0){
                            check=true;
                        }
                    }
                }
                if(check){
                    w.wyswietlSkrt();
                }
            }
            
            break;
        }
        case 4:
        {
            cout << "Prosze wpisac szukane słowa kluczowe: ";
            cin >> tmpString;
            check = false;
            for (auto w : p)
            {
                check = false;
                tmp = w.getSlowaKluczowe();
                for(int i = 0; i<tmp.length(); i++){
                    if(tmp[i]==tmpString[0]){
                        if(tmp.compare(0, tmpString.length(), tmpString, 0, tmpString.length())){
                            check=true;
                        }
                    }
                }
                if(check){
                    w.wyswietlSkrt();
                }
            }
            break;
        }
        case 5:
        {
            cout << "Prosze wpisac slowa zawarte w streszczeniu: ";
            cin >> tmpString;
            check = true;
            for (auto w : p)
            {
                check = false;
                tmp = w.getStreszczenie();
                for(int i = 0; i<tmp.length(); i++){
                    if(tmp[i]==tmpString[0]){
                        if(tmp.compare(0, tmpString.length(), tmpString, 0, tmpString.length())){
                            check=true;
                        }
                    }
                }
                if(check){
                    w.wyswietlSkrt();
                }
            }
            break;
        }
        case 6:
        {
            cout << "Prosze wpisac rok: ";
            cin >> tmpInt;
            for (auto w : p)
            {
                if (w.getRok() == tmpInt)
                {
                    w.wyswietlSkrt();
                }
            }
            break;
        }
        }
    }

    void wyswietlIlosc()
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Ilosc prac ogolem: " << p.size()<<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int mgr = 0, inz = 0, lic = 0, niezdefiniowany = 0;
        string typ;
        for (auto w : p)
        {
            typ = w.getTypPracy();
            if (typ == "mgr")
            {
                mgr++;
            }
            else if (typ == "inz")
            {
                inz++;
            }
            else if (typ == "lic")
            {
                lic++;
            }
            else
            {
                niezdefiniowany++;
            }
        }
        cout << "Ilosc prac licencjackich: " << lic << endl;
        cout << "Ilosc prac inzynierskich: " << inz << endl;
        cout << "Ilosc prac magisterskich: " << mgr << endl;
        if (niezdefiniowany)
        {
            cout << "Ilosc prac niesklasyfikowanych: " << niezdefiniowany << endl;
        }
    }

    void wyswietlPromotorow()
    {
        vector<pair<string, int>> promotors;
        bool check=false;
        for (auto a : p)
        {
            check = false;
            for (auto &b : promotors)
            {
                if (b.first.compare(a.getNazwiskoPromotora())==0)
                {
                    check = true;
                    b.second++;
                    break;
                }
            }
            if (!check)
            {
                promotors.push_back(make_pair(a.getNazwiskoPromotora(), 1));
            }
        }
        sort(promotors.begin(), promotors.end());
        for (int i = 0; i<promotors.size(); i++)
        {
            cout << "Promotor " << promotors[i].first << " nadzoruje " << promotors[i].second << " prac" << endl;
        }
    }

    void rankingSlow()
    {
        vector<pair<int, string>> words;
        string tmpr = "";
        bool check;
        for (auto a : p)
        {
            for (int i = 0; i < a.getSlowaKluczowe().length(); i++)
            {
                if (a.getSlowaKluczowe()[i]==';'||i==a.getSlowaKluczowe().length()-1)
                {
                    check = false;
                    for (auto &w : words)
                    {
                        if (w.second.compare(tmpr)==0)
                        {
                            check = true;
                            w.first++;
                        }
                    }
                    if(i==a.getSlowaKluczowe().length()-1){
                        tmpr+=a.getSlowaKluczowe()[i];
                    }
                    if (!check)
                    {
                        words.push_back(make_pair(1, tmpr));
                    }
                    tmpr="";
                    continue;
                }
                if(!isspace(a.getSlowaKluczowe()[i])){
                    tmpr += a.getSlowaKluczowe()[i];
                }
            }
        }
        sort(words.begin(), words.end()); // sortbysec juz niepotrzebne8
        cout << "Ranking 10 najpopularniejszych slow: " << endl;
        int count=0;
        for (int i = words.size(); i>0; i--)
        {
            cout << ++count << ". " << words[i-1].second << " pojawilo sie: " << words[i-1].first << " razy." << endl;
            if(count==10){
                break;
            }
        }
    }

};

class menu
{   
    biblioteka b;
    public:
        void Menu()
        {
            int wybor;
            int praca;
            bool f=false;
            fstream file;
            file.open("prace.txt");
            if(file.is_open()){
                f=true;
            }
            file.close();
            if(f){
                b.des();
            }else{
                b.dane();
            }
            cout<<"Witamy w bibliotece prac dyplomowych!"<<endl;
            cout<<"Co chciałbyś zrobić?"<<endl; 
            do{
            cout<<"1. Wyswietl skrocona liste\n2. Wyswietl pelna liste\n3. Dodaj prace\n4. Edytuj prace\n5. Wyszukaj prace\n6. Wyswietl liczbe wszystkich prac\n7. Wyswietl liczbe prac poszczegolnych promotorow\n8. Wyswietl 10 najczesciej powtarzajacych sie slow"<<endl;  
            cout<<"Twoj wybor: ";
            cin>>wybor;
            system("clear");
            switch(wybor){
                case 1:{
                    b.wyswietlListe();
                    break;
                    }
                case 2:{
                    b.wyswietlPelna();
                    break;
                }
                case 3:{
                    b.dodajPrace();
                    break;
                }
                case 4:{
                    b.wyswietlListe();
                    cout<<"Ktora prace chcesz edytowac?"<<endl;
                    cin>>praca;
                    b.edytujPrace(praca-1);
                    break;
                }
                case 5:{
                    b.wyszukajPrace();
                    break;
                }
                case 6:{
                    b.wyswietlIlosc();
                    break;
                }
                case 7:{
                    b.wyswietlPromotorow();
                    break;
                }
                case 8:{
                    b.rankingSlow();
                    break;
                }
                default:{

                }
            }
            cin.ignore();
            cout<<"Kliknij enter by kontynuowac"<<endl;
            cin.get();
            system("clear");
            }while(wybor);
            b.ser();
        }

};
int main()
{
    menu m;
    m.Menu();
    return 0;
}
