
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;


class ciezarowki {

      public:
            ciezarowki():weight(0),capacity(0){}
            ciezarowki(float c){weight = 0; capacity = c;}
            ~ciezarowki(){};
           float getWeight(){return weight;}
           float getCapacity(){return capacity;}
            void zdejmij()
            {
                    if (!Stack.empty())
                        {
                            weight -= Stack.top();
                            Stack.pop();
                        }

            }

            bool doloz(float i)
             {
                    if (weight+i <= capacity)
                        {
                            weight+=i;
                            Stack.push(i);
                            return 1;
                        }
                    else return 0;
            }

            float& top() { return Stack.top();}
            bool empty() {return Stack.empty();}

      private:
           stack<float> Stack;
           float weight;
           float capacity;
      };


int ilosc_paczek, licznik = 0,pojemnosc = 0;
queue<float> kolejka;
vector<ciezarowki> stos_pojazdow;


void writeStack (ciezarowki, vector<ciezarowki>);
int start();
void tworzenie_kolejki();
void pisz_kolejke(queue<float>,vector<ciezarowki>);
void dodaj_pojazd();
void ladowanie();
void pisz_pojazd(ciezarowki);
void pisz_wszystkie_pojazdy(vector<ciezarowki> &stos_pojazdow);
void odjazd(int);
void wyjscie();
void st();


int main(void)
{
    srand(time(NULL));

    ilosc_paczek=start();

    st();


     return 0;
}

void st()
{
    tworzenie_kolejki();
    cout<<endl<<endl;

    while(! kolejka.empty())
    {
        pisz_kolejke(kolejka, stos_pojazdow);
    }

    system("cls");
	pisz_wszystkie_pojazdy(stos_pojazdow);

    cout<<"\n                  Koniec zaladunku  ^_^  \n\n\n\n";
    int a;
    cout<<"            1) Sortuj kolejne paczki: 1\n";
    cout<<"            2) Wyjscie:               0\n";
    cin>>a;

    if(a==1)
    {
        start();
        st();
    }

    if(a==0)
    {
       int a=50 ;

        while(a+1)
        {
           odjazd(a);
           a--;
        }
    }

}

int start()
{
    system ("cls");

    int x;
    cout<<"\n\n\n                                SORTOWNIA\n\n                               Wyjscie - 0\n\n";
    cout<<"                  Podaj ilosc paczek do posortowania: ";

    while(!(cin>>x))
    {
        cout<<"\n\n          Zla wartosc! Podaj liczbe calkowita! : ";

        cin.clear();
        cin.sync();
    }

    if(x==0)
    {
        exit (2);
    }
     cin.sync();

    return x;
}

void tworzenie_kolejki()
{
    for(int i=0;i<ilosc_paczek;i++)
    {
        int z;
        z= (rand()%3)+1;
        float x=99.9,y;
        y = rand()%99;
        x = ( x / (y+1) ) * z;
       kolejka.push(x);
    }
}

void pisz_kolejke(queue<float> kolejka, vector<ciezarowki> stos_pojazdow )
{
     system ("cls");

    int x=0;

    cout<<"\n\n\n\n     ";

    while(! kolejka.empty())
    {
        cout<<"  "<<setprecision(3)<<kolejka.front()<<"  ";
        kolejka.pop();
        x++;
    }

    cout<<"\n   ";

    while(x)
    {
        cout<<"---------";
        x--;
    }
     cout<<">\n"<<endl;

	 pisz_wszystkie_pojazdy(stos_pojazdow);

     dodaj_pojazd();
}

void pisz_wszystkie_pojazdy(vector<ciezarowki> &stos_pojazdow)
{

	while (!stos_pojazdow.empty())
	{
		pisz_pojazd((stos_pojazdow.front()));
		stos_pojazdow.erase(stos_pojazdow.begin());
	}

}



void dodaj_pojazd()
{
    cout<<"\n\n        Wyjscie - 0\n\n\n        Pojemnosc ciezarowki: ";

    while(!(cin>>pojemnosc))
    {
        cout<<"\n\n          Zla wartosc! Podaj liczbe calkowita! : ";

        cin.clear();
        cin.sync();
    }

     if(pojemnosc==0)
    {
        exit (3);
    }

    cin.sync();

    ciezarowki ciezarowka(pojemnosc);

    stos_pojazdow.push_back(ciezarowka);

    ladowanie();
}

void ladowanie()
{
    bool x=1;

    vector<float> buf;

    while(! kolejka.empty())
    {
        buf.push_back(kolejka.front());
        kolejka.pop();
    }

    while(x)
    {
        if(! buf.empty())
        {
            x=(stos_pojazdow.back()).doloz(buf.back());

            if (x==1)
                {
                    licznik++;
                    buf.pop_back();
                }
        }

       else x=0;
    }

    while(! buf.empty())
        {
            kolejka.push(buf.front());
            buf.erase(buf.begin());
        }

}

void pisz_pojazd(ciezarowki pojazd)
{
    int licznik2 = 0, licznik3;
    float waga=pojazd.getWeight();


    cout<<"\n\n\n\n                          /---| ";

    ciezarowki buf(pojazd.getCapacity());

     while(! pojazd.empty())
    {
        buf.doloz(pojazd.top());
        pojazd.zdejmij();
    }

    while(! buf.empty())
    {
       cout<<setprecision(3)<< setw(5)<<buf.top()<<" ";
       buf.zdejmij();
       licznik2++;
    }

    licznik3=licznik2;
	licznik = licznik2;

    cout<<"\n                          |---| ";

    while(licznik3)
    {
       cout<<"------";
      licznik3--;
    }

	cout << "\n   Pojemnosc: " << setw(4) << pojazd.getCapacity() << "        ";

    while(licznik2 + 1)
    {
       cout<<" o  o ";
       licznik2--;
    }

	cout << setprecision(3) << "  Zaladowano: " << licznik << " pacz. o masie: " << setprecision(5) << waga << endl << endl << endl;
}

void odjazd(int a)
{
    system ("cls");

    int x=a;

    cout<<"\n";
    while(x)
    {
        cout<<" ";
        x--;
    }

    cout<<"/---| Dowidzenia  \n";

    x=a;
    while(x)
    {
        cout<<" ";
        x--;
    }

    cout<<"|---|-------------- \n";

    x=a;
    while(x)
    {
        cout<<" ";
        x--;
    }

    cout<<" o   o   o   o   o \n\n\n";

    Sleep(30);

    if(a==0)
    {
        system ("cls");

        cout<<"\n---| Dowidzenia  \n";
        cout<<"---|-------------- \n";
        cout<<"o   o   o   o   o   \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n--| Dowidzenia  \n";
        cout<<"--|-------------- \n";
        cout<<"   o   o   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n-| Dowidzenia  \n";
        cout<<"-|-------------- \n";
        cout<<"  o   o   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n| Dowidzenia  \n";
        cout<<"|-------------- \n";
        cout<<" o   o   o   o  \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n Dowidzenia  \n";
        cout<<"-------------- \n";
        cout<<"   o   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nDowidzenia \n";
        cout<<"------------- \n";
        cout<<"   o   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nowidzenia \n";
        cout<<"------------ \n";
        cout<<"  o   o   o  \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nwidzenia \n";
        cout<<"----------- \n";
        cout<<"o   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nidzenia \n";
        cout<<"---------- \n";
        cout<<"   o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\ndzenia \n";
        cout<<"--------- \n";
        cout<<"  o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nzenia \n";
        cout<<"-------- \n";
        cout<<" o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nenia \n";
        cout<<"------- \n";
        cout<<"o   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nnia \n";
        cout<<"------ \n";
        cout<<"   o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\nia \n";
        cout<<"----- \n";
        cout<<"  o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\na \n";
        cout<<"---- \n";
        cout<<" o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n \n";
        cout<<"--- \n";
        cout<<"o \n\n\n";

        Sleep(30);

        system ("cls");

        cout<<"\n\n";
        cout<<"-- \n";
        cout<<" \n\n\n";

        Sleep(30);

        system ("cls");
    }
}


