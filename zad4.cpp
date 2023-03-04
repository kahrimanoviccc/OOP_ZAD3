#include <iostream>
#include <vector>
#include <functional>

using namespace std;

auto uslov1 = [](int a) -> bool{
return a>0;
};

auto uslov2 = [](int a) -> bool{
return a%2==0;
};

auto uslov3 = [](int a) -> bool{
return a<100;  
};

typedef vector<function<bool(int)>> funkcije;

void unos(vector<int>& brojevi){
int uneseni_broj;
cout << "Unesite brojeve u vektor: " << endl;
while(cin >> uneseni_broj){
brojevi.push_back(uneseni_broj);
};

}

void implementacija ( vector<int>& lista ,  funkcije provjeri , int br= -1){
for(int& el : lista){
for(function<bool(int)> fja : provjeri){
if(fja(el) == false){
el = br;
};
};
};
}



int main()
{
vector<int> brojevi;
funkcije obradi{uslov1,uslov2,uslov3};
unos(brojevi);
implementacija(brojevi,obradi);
for(int element: brojevi){
cout << element << "\t" ;
};
}
