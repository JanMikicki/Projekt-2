
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include <ctime>

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
                    if (weight+i<= capacity)
                        {
                            weight+=i;
                            Stack.push(i);
                            return 1;
                        }
                    else return 0;
            }

            float& top() { return Stack.top();}
            bool empty() {return Stack.empty();}
            size_t size() {return Stack.size();}

      private:
           stack<float> Stack;
           float weight;
           float capacity;
      };


int ilosc_paczek, licznik = 0;
float pojemnosc = 0;
queue<float> kolejka;
vector<ciezarowki> stos_pojazdow;




void writeStack (ciezarowki, vector<ciezarowki>);
int start();
void tworzenie_kolejki();
void pisz_kolejke(queue<float>,vector<ciezarowki>);
void dodaj_pojazd();
void ladowanie();
void pisz_pojazd(ciezarowki);



int main(void)
{
    srand(time(NULL));

    ilosc_paczek=start();

    tworzenie_kolejki();
    cout<<endl<<endl;

    while(! kolejka.empty())
    {
        pisz_kolejke(kolejka, stos_pojazdow);
    }

cout<<"\n                  Koniec zaladunku  ^_^  \n\n\n\n";

     system("pause");
     return 0;
}

int start()
{
    int x;
    cout<<"\n\n\n                                SORTOWNIA\n\n\n";
    cout<<"                  Podaj ilosc paczek do posortowania: ";
    cin>>x;
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


     while(! stos_pojazdow.empty())
     {
        pisz_pojazd((stos_pojazdow.front()));
        stos_pojazdow.erase(stos_pojazdow.begin());
     }

     dodaj_pojazd();
}

void dodaj_pojazd()
{
    cout<<"\n\n  Pojemnosc ciezarowki: ";
    cin>>pojemnosc;

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

    cout<<"\n                          /---| ";

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

	cout << setprecision(3) << "  Zaladowano: " << licznik << " pacz. o masie: " << setprecision(3) << waga << endl << endl << endl;
}


