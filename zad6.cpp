#include <iostream>
#include <list>
#include <functional>

using namespace std;

auto transformacija = [](int n){ return n * 2 + 1;};

void unos(list<int>& lista){
cout << "Unesite elemente liste: " << endl;
int el;
while (cin>>el){
lista.push_back(el);
};
}

list<int> Map(const list<int>& lista, function<int(int)> transform){
list <int> novi;
for(int el: lista){
novi.push_back(transform(el));
};  
return novi;
}

int main()
{
list <int> lista,novi;
unos(lista);
novi= Map(lista, transformacija);
for(int el: novi){
cout << el << "\t" ;

};
}
