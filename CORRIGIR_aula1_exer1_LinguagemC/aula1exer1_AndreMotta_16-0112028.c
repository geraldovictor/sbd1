#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Pessoa{
  char nome[100];
  int  cpf;
  char placa[100];
  char modelo[100]
};

int main(){
 
  struct Pessoa *lista;
  int capacity;
  int n; 
  int option; 
  int i;
  FILE *fp;

  
  fp = fopen("lista.dat","r");
  if(fp==NULL){
    n = 0;
    capacity = 10;
    lista = (struct Pessoa *)malloc(sizeof(struct Pessoa)*capacity);
  }
  else{ 
    fread(&n, sizeof(int), 1, fp);
    capacity = n*2; 
    lista = (struct Pessoa *)malloc(sizeof(struct Pessoa)*capacity);
    fread(lista, sizeof(struct Pessoa), n, fp);
    fclose(fp);
  }
  
  do{
    printf("*** Menu ***\n");
    printf("1) Cadastrar Carro.\n");
    printf("2) Exibir Carros.\n");
    printf("3) Apagar.\n");
    printf("4) Sair.\n");
    scanf("%d",&option);

    if(option==1){
      if(n==capacity){
	     capacity *= 2;
         lista = realloc(lista, sizeof(struct Pessoa)*capacity);
      }
      printf("Digite a Placa do carro:");
      scanf(" %[^\n]",lista[n].placa);
      printf("Digite o nome: ");
      scanf(" %[^\n]",lista[n].nome);
      printf("Digite o cpf: ");
      scanf("%d",&lista[n].cpf);
      printf("Digite o Modelo do carro:");
      scanf(" %[^\n]",lista[n].modelo);

      n++; 
    }
    else if(option==2){
      for(i=0; i<n; i++){
	    printf("\n",i+1);
        printf("Placa: %s\n",lista[i].placa);
        printf("Nome do prorpietario: %s\n",lista[i].nome);
	    printf("cpf: %d\n",lista[i].cpf);
        printf("Modelo: %s\n",lista[i].modelo);
        printf("\n");
      }
    }
    else if(option==3){
      char placa[100];
      int j;
      printf("Digite o nome:");
      scanf("%s",&placa);
      for(i=0; i<n; i++){
             if (strcmp(lista[i].placa, placa)==0){
             	for(j=i+1; j<n; j++){
                         strcpy(lista[j-1].nome,lista[j].nome);
                         lista[j-1].cpf=lista[j].cpf;
                         strcpy(lista[j-1].placa,lista[j].placa);
                         strcpy(lista[j-1].modelo,lista[j].modelo);
                 }
               n--;
               i=n;
              }
      }
    }
  }while(option!=4); 
  if(n>0){
    fp = fopen("lista.dat","w");
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(lista, sizeof(struct Pessoa), n, fp);
    fclose(fp);
  }
  free(lista);
  return 0;
}