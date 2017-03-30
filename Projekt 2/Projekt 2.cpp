
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
                    if (not Stack.empty())
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


int ilosc_paczek;
float pojemnosc=0;
queue<float> kolejka;
vector<ciezarowki> stos_pojazdow;




void writeStack (ciezarowki, vector<ciezarowki>);
int start();
void tworzenie_kolejki();
void pisz_kolejke(queue<float>);
void dodaj_pojazd();
void ladowanie();
void pisz_pojazd(ciezarowki);



int main(void)
{
    srand(time(NULL));

    ilosc_paczek=start();

   /* float z;
    z=(stos_pojazdow.front()).getCapacity();
    cout<<setprecision(3)<<z<<endl<<endl;*/

    tworzenie_kolejki();
    cout<<endl<<endl;

    pisz_kolejke(kolejka);


    while(not kolejka.empty())
    {
        dodaj_pojazd();
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

void pisz_kolejke(queue<float> kolejka)
{
    int x=0;

    cout<<"     ";

    while(not kolejka.empty())
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

    int licznik=0;

    vector<float> buf;

    while(not kolejka.empty())
    {
        buf.push_back(kolejka.front());
        kolejka.pop();
    }

    while(x)
    {
        if(not buf.empty())
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

    while(not buf.empty())
        {
            kolejka.push(buf.front());
            buf.erase(buf.begin());
        }


    pisz_pojazd((stos_pojazdow.back()));

     cout<<setprecision(3)<<"  Zaladowano: "<<licznik<<" pacz. o masie: "<<(stos_pojazdow.back()).getWeight()<<endl<<endl<<endl;
}

void pisz_pojazd(ciezarowki pojazd)
{
    int licznik=0,x;

    cout<<"\n   /---| ";

    ciezarowki buf(pojazd.getCapacity());

     while(not pojazd.empty())
    {
        buf.doloz(pojazd.top());
        pojazd.zdejmij();
    }

    while(not buf.empty())
    {
       cout<<setprecision(3)<< setw(5)<<buf.top()<<" ";
       buf.zdejmij();
       licznik++;
    }

    x=licznik;

    cout<<"\n   |---| ";

    while(x)
    {
       cout<<"------";
       x--;
    }

    cout<<"\n   ";

    while(licznik+1)
    {
       cout<<" o  o ";
       licznik--;
    }

}


