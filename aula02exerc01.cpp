#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

class Carro{
  public:
    std::string modelo;
    std::string marca;
    std::string renavam;
    std::string cor;
    // Carro();  chamada estática
    // ~Carro();
};
// Carro::Carro(){
//   std::cout << "Carro Criado" << std::endl;
// }
// Carro::~Carro(){
//   std::cout << "Carro destruído" << std::endl;
//
// } chamada estática

class Proprietario{
  public:
    std::string nome_prop;
    std::string cpf;
    std::string placa;
    std::string modelo;
    // Proprietario(); chamada estática
    // ~Proprietario();
    // Carro *c = new Carro[2];
    // for(i = 0; i < 2; i++){
    //   // new (&c[i]) Carro;
    // }
};
// Proprietario::Proprietario(){ chamada estática
//   std::cout << "Proprietario Criado" << std::endl;
// }
// Proprietario::~Proprietario(){
//   std::cout << "Proprietario destruído" << std::endl;
//
// }

int main(int argc, char const *argv[]) {
  int i =0;
  Proprietario* p = new Proprietario[2];


  std::cin >> i;
  std::cout << 0;
  // std::cin >> p[0].c[0].cor;
  // std::cout << p[0].c[0].cor << std::endl;

  // Proprietario p[10]; chamada estática

  return 0;
}
