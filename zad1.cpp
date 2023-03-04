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
list<int>::const_iterator pom=a;
for(;;a++){
bool rez;
try {rez= predikat(*a);}
catch (const runtime_error& problem){
cout << problem.what();
for(;;pom++){
if(pom == b){break;};  
novi.push_back(*pom);
};
return novi;
exit(10);
};
if(a==b){
break;
}
else if(rez == true){
novi.push_front(*a);
}else {
novi.push_back(*a);};
};
//NACIN PREKO PETLJI ALI NIJE KORISTEN push front koji se koristi za list kontejner
/*for(;;a++){
if(a==b){ break; };
if((*a)%2 == 0){
novi.push_back(*a);
};
};
for(;;pomocni++){
if(pomocni==b){ break; };  
if((*pomocni)%2 != 0){
novi.push_back(*pomocni);
};
};*/
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
nova_lista= parni_neparni(pocetak,kraj,predicate);  
for(int el : nova_lista){
cout<< el << "\t" ;
};
}
