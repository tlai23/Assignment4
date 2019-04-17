//Tuan Lai
//CPSC 301 section2
#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>

int readData(vector<Person>&employee);
void writeData(vector<Person>&employee, int n);

int main()
{
int N =0;
vector<Person> employee;
N = readData(employee);
writeData(employee, N-1);
}


int readData(vector<Person> &employee)
{
  string first, last;
  float payR, hr;
  int i=0;
  ifstream inData ("input.txt");
  if (inData.is_open())
  {
  while (inData)
  {
    inData>> first;
    inData>> last;
    inData>> payR;
    inData>> hr;
    employee.emplace_back(first, last, payR,hr);
    i++;
  }
  inData.close();
}
  return i;
}

void writeData(vector<Person>&employee, int n)
{
  ofstream outData;
  outData.open("output.txt");
  for(int i=0; i<=n; i++)
  {
    outData<<employee.at(i).fullName()<<" ";
    outData<<employee.at(i).totalPay()<<endl;
  }
  outData.close();
}
