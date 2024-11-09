// Posible forma de implementar las clases polinomios con vectors.

#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string str, char pattern) {
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while ((posFound = str.find(pattern, posInit)) != string::npos) {
      splitted = str.substr(posInit, posFound - posInit);
      results.push_back(splitted);
      posInit = posFound + 1;
  }
  if (posInit < str.size()) {
      results.push_back(str.substr(posInit)); 
  }
  return results;
}//José Flores, hecho miércoles 6/11

double evaluar(vector <double> factores, double x){
  vector <double> evaluado(factores.size());
  double suma=0;
  for(int i(0); i<factores.size();i++){
    if(i==0){evaluado.push_back(factores[i](pow(x, 3)));}//multiplicar factores por las x's
    if(i==1){evaluado.push_back(factores[i](pow(x, 2)));}
    if(i==2){evaluado.push_back(factores[i](pow(x, 1)));}
    if(i==3){evaluado.push_back(factores[i](pow(x, 0)));}
  }
  for(int i(0); i<evaluado.size(); i++){//
    suma+=evaluado[i];
  }
  return suma;
}//José Flores, hecho miércoles 6/11

int main(){
  string alo;
  cin>>alo;
  vector <string> splitted(split(alo, '+'));
  for(int i(0);i<splitted.size(); i++){
  cout<<splitted[i]<<endl;
  }
}
