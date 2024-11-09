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

int main(){
  string alo;
  cin>>alo;
  vector <string> splitted(split(alo, '+'));
  for(int i(0);i<splitted.size(); i++){
  cout<<splitted[i]<<endl;
  }
}
