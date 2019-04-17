//Tuan Lai
//301 section 2
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct PERSON{
  char Name[20];
  float Balance;
};

void Display(PERSON a[],int N);
void FindRichest(PERSON a[],int N);
void Deposit(PERSON a[], int N, string custName, float amount);
void NewCopy(PERSON a[], int N);
int readData(PERSON a[]);

int main()
{int N;
PERSON* P = new PERSON[N];

N = readData(P);
PERSON * readData(int & N);
Display(P, N-1);
FindRichest(P, N-1);
int i=0,j=0;
float nBalance;
string name1, name2, sName2;
char cName[20];
cout<<"Enter name"<<endl;
cin>>name1>>name2;
sName2 = name1+" "+name2;
strcpy(cName, sName2.c_str());
while (i<=N)
{
  if(strcmp(P[i].Name,cName)==0)
  {
    j=i;
  }
  i++;
}
  cout<<"Amount: ";
  cin>>nBalance;
  cout<<endl;
Deposit(P, j, sName2, nBalance);
NewCopy(P, N-1);

return 0;
}

int readData(PERSON a[])
{
  string fname;
  string lname;
  string sName;
  int i=0,n;
  ifstream inData ("data.txt");

  while (inData)
  {
  do{
  inData>>fname;
  inData>>lname;
}while(fname.size()<9 || lname.size()<10);
  inData>>a[i].Balance;
  sName = fname+" "+lname;
  strcpy(a[i].Name, sName.c_str());
  i++;
  }
  inData.close();
  return i;
}

void Display(PERSON a[], int N)
{
  int i=0;
  cout<<"Name"<<"\t\t"<<"Balance"<<endl;
  cout<<"-----------------------"<<endl;
  while(i<=N)
  {
  cout<<a[i].Name<<" "<<a[i].Balance<<endl;
  i++;
  }
}

void FindRichest(PERSON a[],int N)
{
  int i=0;
  string rName;
  while(i<=N)
  {
    if(a[i].Balance > a[i+1].Balance)
    {
      rName = a[i].Name;
    }else
    {
      rName = a[i+1].Name;
    }
    i++;
  }
  cout<<"The richest person is " + rName<<endl;
}

  void Deposit(PERSON a[], int N, string custName, float amount)
  {
    a[N].Balance+=amount;
    cout<<"Enter name: "<<custName<<endl;
    cout<<"Amount: "<<amount<<endl;
    cout<<"New Balance: "<<a[N].Balance<<endl;
  }

  void NewCopy(PERSON a[],int N)
  {
    ofstream outData;
    outData.open("data.txt");

    for(int i=0;i<=N;i++)
    {
    outData<<a[i].Name<<" "<<a[i].Balance<<endl;
    }
    outData.close();

  }
