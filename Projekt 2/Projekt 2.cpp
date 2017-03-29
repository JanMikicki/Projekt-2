
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
                    if (Stack.size() > 0)
                        {
                            weight -= Stack.top();
                            Stack.pop();
                        }
                    else cerr<<"Empty"<<endl;

            }

            void doloz(int i)
             {
                    if (weight+i<= capacity)
                        {
                            weight+=i;
                            Stack.push(i);
                            cout<<"push"<<i<<endl;
                        }
                    else cerr<<"Full"<<endl;
            }

            float& top() { return Stack.top();}
            bool empty() {return Stack.empty();}
            size_t size() {return Stack.size();}

      private:
           stack<float> Stack;
           float weight;
           float capacity;
      };








void writeStack (ciezarowki*);
void writeStack (ciezarowki);
int start();
void tworzenie_kolejki(queue<float>,int);




int main(void)
{
    srand(time(NULL));

    int ilosc_paczek=start();

    queue<float> kolejka;

    float z;
    ciezarowki ciezarowka(99.9);
    z=ciezarowka.getCapacity();
    cout<<setprecision(3)<<z<<endl<<endl;

    tworzenie_kolejki(kolejka,ilosc_paczek);

    int x=2;

    cout<<endl<<endl;

     for (int i=1; i<=x; i++)
     {
        ciezarowka.doloz(i);
     }

      writeStack(ciezarowka);
     cout<<endl<<ciezarowka.size() << endl;

     writeStack(&ciezarowka);
     cout<<endl<<ciezarowka.size() << endl;

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

void tworzenie_kolejki(queue<float> kolejka,int ilosc)
{
    for(int i=0;i<ilosc;i++)
    {
        int z;
        z= (rand()%3)+1;
        float x=99.9,y;
        y = rand()%99;
        x = ( x / (y+1) ) * z;
       kolejka.push(x);
       cout<<setw(2)<<i+1<<"    "<<setprecision(3)<<x<<endl;
    }
}

void writeStack (ciezarowki ciezarowka)
{
   while ( not ciezarowka.empty())
   {
         cout<<setw(4)<<ciezarowka.top();
         ciezarowka.zdejmij();                   // operuje na kopii - nie zmienia oryginalu
   }
   cout<<endl;
}



void writeStack (ciezarowki *ciezarowka)
{
   while ( not (*ciezarowka).empty())
   {
         cout<<setw(4)<<(*ciezarowka).top();
         (*ciezarowka).zdejmij();                   // operuje na oryginale - oproznia stos
   }
   cout<<endl;
}

