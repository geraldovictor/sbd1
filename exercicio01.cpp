#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

typedef struct {
  string nome_prop;
  string cpf;
  string placa;
  string modelo;
} Cadastro;

int main(int argc, char const *argv[]) {
  int n;
  fstream arquivo;
  arquivo.open("cadastro.txt", ios::out);
  printf("Quantos carros deseja cadastrar?\n");
  cin >> n ;
  cin.ignore();
  Cadastro cad[n];
    for (int i = 0; i < n; i++) {
      if(i==0)
      arquivo << "-----------" << endl;
      cout << "Carro numero " << i+1 << endl;
      cout << "Nome do proprietario: " << endl;
      getline(cin, cad[i].nome_prop);
      arquivo << "Nome do proprietario: " << cad[i].nome_prop << endl;
      cout << "CPF: " << endl;
      getline(cin, cad[i].cpf);
      arquivo << "CPF do proprietario: " << cad[i].cpf << endl;
      cout << "Modelo: " << endl;
      getline(cin, cad[i].modelo);
      arquivo << "Modelo: " << cad[i].modelo << endl;
      cout << "Placa: " << endl;
      getline(cin, cad[i].placa);
      arquivo<< "Placa: " << cad[i].placa << endl;
      arquivo << "-----------" << endl;
    }
    arquivo.close();

  return 0;
}
