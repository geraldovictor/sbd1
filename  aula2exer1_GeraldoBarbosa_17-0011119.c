#include <stdio.h>
#include <stdlib.h>

struct carro{
    char modelo[20];
    char marca[20];
    char renavam[11];
    char cor[10];
};

struct proprietario{
    char nome[35];
    char cpf[11];
    char data_nascimento[9];
    struct carro Carro;
};

void abre(FILE **arq){
    *arq = fopen("cadastro.txt", "a");
    if (*arq == NULL){
       printf("Problemas na abertura do arquivo\n");
       return;
    }
}

void apaga(FILE **arq){
  *arq = fopen("cadastro.txt","w");
  if (*arq == NULL){
     printf("Problemas na abertura do arquivo\n");
     return;
  }
}

void mostra(FILE **arq){
  char Linha[100];
  char *result;
  *arq = fopen("cadastro.txt", "rt");
  if (*arq == NULL){
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  while (!feof(*arq)){
    result = fgets(Linha, 100, *arq);
    if (result)
    printf("%s",Linha);
  }
  fclose(*arq);
}

void menu(){
  printf("*** Menu ***\n");
  printf("1) Cadastrar Carro.\n");
  printf("2) Exibir Cadastros.\n");
  printf("3) Apagar (isso apagará todo conteúdo do arquivo).\n");
  printf("4) Sair.\n");
}

int main(void){
    struct proprietario p1;
    struct carro c;
    int qtd_carro;
    FILE *arq = NULL;
    int i = 0;
    int opc_num;
    char opc_letra;

    do{
      menu();
      scanf("%d",&opc_num);
      if(opc_num<0||opc_num>4){
        printf("Digite uma opção válida!!!\n");
      }
      if(opc_num==1){
        abre(&arq);
        printf("Insira nome do proprietário: ");
        scanf(" %[^\n]", p1.nome);
        scanf("%*[^\n]"); scanf("%*c");
        printf("Insira o CPF do proprietário: ");
        scanf(" %s", p1.cpf);
        printf("Insira a data de nascimento do proprietário: ");
        scanf(" %s", p1.data_nascimento);
        printf("Quantos carros deseja cadastrar: ");
        scanf("%d",&qtd_carro);
        fprintf(arq, "Nome do proprietário: %s\nCPF do proprietário: %s\nData de nascimento do proprietário: %s\n", p1.nome, p1.cpf, p1.data_nascimento);
        fprintf(arq, "----------------\n");
        printf("Cadastro do carro:\n");
        for(i = 0; i < qtd_carro; i++){
          printf("Insira o modelo do carro nº %d: ", i+1);
          scanf(" %s", c.modelo);
          printf("Insira a marca do carro nº %d: ",i+1);
          scanf(" %s", c.marca );
          printf("Insira a cor do carro nº %d: ",i+1);
          scanf(" %s", c.cor);
          printf("Insira o renavam do carro nº %d: ",i+1);
          scanf(" %s: ", c.renavam );
          fprintf(arq, "\n");
          fprintf(arq, "Carro nº:%d\nCor:%s\nMarca:%s\nModelo:%s\nRenavam:%s\n", i+1, c.cor, c.marca, c.modelo, c.renavam);
          fprintf(arq, "----------------\n");
        }
        printf("Dados salvos no arquivo com sucesso!\n");
        fclose(arq);
      }
      if(opc_num==2){
        mostra(&arq);
      }
      if(opc_num==3){
        printf("Deseja remover todo conteúdo do arquivo?: [s/n]\n");
        scanf(" %c",&opc_letra);
        while (opc_letra!='s'&&opc_letra!='n') {
          printf("Insira 's' ou 'n'\n");
          scanf(" %c",&opc_letra);
        }
        if(opc_letra=='s'){
          apaga(&arq);
        }
      }
    }while(opc_num!=4);
    return 0;
}
