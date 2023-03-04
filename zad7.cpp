#include <iostream>
#include <list>
#include <functional>

using namespace std;

auto transformacija = [](int a, int b){ return a + b + 1;};

void unos(list<int>& lista){
cout << "Unesite elemente liste: " << endl;
int el;
while (cin>>el){
if(el == 0){break;}  
lista.push_back(el);
};
}

int reduce(const list<int>& lista, function<int(int,int)> transform, int start){
int output=0;
for(int el: lista){
output= transform(start,el);
start=output;
};
return start;
}

int main()
{
  list<int> lista;
  unos(lista);
  int start;
  cout << "Unesite start" << endl;
  cin>>start;
  int out= reduce(lista,transformacija,start);
  cout << out << endl;
}

