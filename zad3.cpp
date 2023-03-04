#include <iostream> 
#include <list>
#include <functional>
#include <stdexcept>
using namespace std;

auto predicate= [](int broj) -> bool{ if (broj==0) throw runtime_error{"Nemoguce raditi sa nulom"};
  return broj%2 == 0; };

void unos(list<int>& lista_za_unos){
int broj=0;
cout << "Unesite brojeve za listu(0 za kraj unosa): " << endl;
while(cin >> broj){
lista_za_unos.push_back(broj);
};

} 

list<int> parni_neparni(list<int>::const_iterator a, list<int>::const_iterator b, function<bool(int)> predikat){
list<int> novi;
for(;;a++){
if(a==b){ 
break;
}else if(predikat(*a)==true){
novi.push_front(*a);
}else{
novi.push_back(*a);
};
};
return novi;

}

int main()
{
list<int> lista_brojeva;
list<int> nova_lista;
unos(lista_brojeva);
list<int>::const_iterator pocetak;
list<int>::const_iterator kraj;
pocetak= lista_brojeva.begin();
kraj= lista_brojeva.end();
try{
nova_lista= parni_neparni(pocetak,kraj,predicate);  
}
catch(runtime_error a){
cout << a.what() << endl;
nova_lista= lista_brojeva;
}
for(int el : nova_lista){
cout<< el << "\t" ;
};
}
