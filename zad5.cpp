#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

auto predikat = [](int a) ->bool{
return a%2 == 0;
};

void unos(list<int>& lista){
cout << "Unesite elemente liste: " << endl;
int el;
while (cin>>el){
lista.push_back(el);
};
}

list<int> filter(const list<int>& lista, function<bool(int)> uslov){
list<int> novi;
for(int el : lista){
if(uslov(el)==true){
novi.push_back(el);
};
};
return novi;
}

int main()
{
list<int> lista,novi;
unos(lista);
novi = filter(lista,predikat);
for(int el : novi){
cout << el << "\t" ;
};
}
