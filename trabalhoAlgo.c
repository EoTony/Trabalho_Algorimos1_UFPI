#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
typedef struct {
    int id;
    char tipo[30];
    float valor;
    int idAbelha;
}Sensor;
typedef struct {
    int id;
    char nomePopular[40];
    char nomeCientifico[50];
    char regiao[30];
    float producaoMel;
}Abelha;

void printfAbelha(Abelha p){
    printf("ID: %d\n",p.id);
    printf("Nome Popular: %s\n",p.nomePopular);
    printf("Nome Cientifico: %s\n",p.nomeCientifico);
    printf("Regiao: %s\n",p.regiao);
    printf("Producao de Mel: %.2f kg\n",p.producaoMel);
}
void printfSensor(Sensor p){
    printf("ID: %d\n",p.id);
    printf("Tipo: %s\n",p.tipo);
    printf("Valor: %.2f\n",p.valor);
    printf("ID da Abelha Associada: %d\n",p.idAbelha);
}
void limpezaBuffer(){
    int aux;
    while((aux = getchar()) != '\n' && aux != EOF);
}
void registroAbelhas(Abelha *p){
    printf("Informe o nome popular:\n");
    scanf(" %39[^\n]",p->nomePopular);
    printf("Informe o nome cientifico:\n");
    scanf(" %49[^\n]",p->nomeCientifico);
    printf("Informe a regiao:\n");
    scanf(" %29[^\n]",p->regiao);
    printf("Informe a producao de mel (em kg):\n");
    scanf("%f",&p->producaoMel);
}
int quantidadeAbelha(Abelha a[]){
    int cont = 0;
    for(int i = 0;i < 50;i++){
        if(a[i].id != -1){
            cont++;
        }
    }
    return cont;
}
int quantidadeSensores(Sensor s[]){
    int cont = 0;
    for(int i = 0;i < 100;i++){
        if(s[i].id != -1){
            cont++;
        }
    }
    return cont;
}
int registroSensores(Sensor *p1, Abelha *p2){
    const char *tipo[] = {"Temperatura","Umidade","Luminosidade"};
    int opcao;
    do{
        printf("Escolha o tipo de sensor:\n");
        printf("0 - Temperatura\n");
        printf("1 - Umidade\n");
        printf("2 - Luminosidade\n");
        printf("Digite o numero correspondente ao tipo:\n");
        scanf("%d",&opcao);
        if(opcao < 0 || opcao > 2){
            printf("Tipo invalido!Tente novamente.\n");
        }
    }while(opcao < 0 || opcao > 2);
    
    strcpy(p1->tipo,tipo[opcao]);
    printf("Informe o valor de leitura do sensor:\n");
    scanf("%f",&p1->valor);
    do{
        printf("Informe o ID da abelha associada:\n");
        scanf("%d",&p1->idAbelha);
        for(int i = 0; i < 50; i++){
            if(p2[i].id == p1->idAbelha){
                return 1;
            }
        }
        printf("ID de abelha invalido! Tente novamente.\n");
    }while(1);
}    
int existeAbelha(Abelha p[], int id){
    for(int i = 0;i < 50;i++){
        if(p[i].id == id){
            return 1;
        }
    }
    return 0;
    
}
int deletarAbelha(Abelha *p1, int id, Sensor *p2){
    int total = quantidadeAbelha(p1);
    for(int i = 0;i < total;i++){
        if(p1[i].id == id){
            for(int j = 0;j < 100;j++){
                if(p2[j].idAbelha == id){
                    p2[j].id = -1;
                    p2[j].idAbelha = -1;
                    p2[j].valor = 0;
                    p2[j].tipo[0] = '\0';
                }
            }
            for(int j = i;j < total - 1;j++){
                p1[j] = p1[j+1];
            }
            p1[total - 1].id = -1;
            p1[total - 1].producaoMel = 0;
            p1[total - 1].nomeCientifico[0] = '\0';
            p1[total - 1].nomePopular[0] = '\0';
            p1[total - 1].regiao[0] = '\0';
            return 1;
        }
    }
    return 0;
}
int buscaMostraAbelha(Abelha p1[], char nome[],Sensor p2[]){
    int existe = 0;
    for(int i = 0;i < 50;i++){
        if(strcasecmp(p1[i].nomePopular,nome) == 0 && p1[i].id >= 0){
            existe = 1;
            printfAbelha(p1[i]);
            printf("Sensores associados:\n");
            for(int j = 0;j < 100;j++){
                if(p1[i].id == p2[j].idAbelha){
                   printfSensor(p2[j]);
                }
            }
        }
    }
    return existe;
}
void listarAbelhas(Abelha a[]){
    for(int i = 0; i < 50;i++){
        if(a[i].id != -1){
            printfAbelha(a[i]);
            printf("*-------------------------*\n");
        }
    }
}
void listarSensores(Sensor s[]){
    for(int i = 0;i < 100;i++){
        if(s[i].id != -1){
            printfSensor(s[i]);
            printf("*-------------------------*\n");
        }
    }
}
int main(){
    Abelha abelhas[50];
    Sensor sensores[100];
    for(int i = 0;i < 50;i++){
        abelhas[i].id = -1;
        abelhas[i].producaoMel = 0;
        abelhas[i].nomeCientifico[0] = '\0';
        abelhas[i].nomePopular[0] = '\0';   
        abelhas[i].regiao[0] = '\0';
    }
    for(int i = 0;i < 100;i++){
        sensores[i].id = -1;
        sensores[i].idAbelha = -1;
        sensores[i].valor = 0;
        sensores[i].tipo[0] = '\0';
    }
    char opcao;

    do{
        printf("----*BeeMonitor C*----\n");
        printf("A - Gerenciar Abelhas\n");
        printf("B - Gerenciar Sensores\n");
        printf("C - Relatorios\n");
        printf("D - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c",&opcao);
        system("clear || cls");
        switch(opcao){
            char opcao2;
            case 'A':
            case 'a':
                do{
                    printf("---*Gerenciamento de abelhas*---\n");
                    printf("A - Cadastrar\n");
                    printf("B - Listar\n");
                    printf("C - Buscar\n");
                    printf("D - Remover registros de abelhas\n");
                    printf("E - Alterar\n");
                    printf("F - Sair");
                    printf("Escolha uma opção: ");
                    scanf(" %c",&opcao2);
                    system("clear || cls");
                    switch(opcao2){
                        case 'A':
                        case 'a':
                            for(int i = 0;i < 50;i++){
                                if(abelhas[i].id == -1){
                                    abelhas[i].id = i;
                                    registroAbelhas(&abelhas[i]);
                                    printf("Abelha cadastrada com sucesso!\n");
                                    break;
                                }
                            }
                            break;
                        case 'B':
                        case 'b':
                            if(quantidadeAbelha(abelhas) == 0){
                                printf("Nenhuma abelha cadastrada.\n");
                            }
                            else{
                                listarAbelhas(abelhas);
                                printf("\n");
                            }
                            break;
                        case 'C':
                        case 'c':
                            if(quantidadeAbelha(abelhas) != 0){
                                char nome[40];
                                printf("Informe o nome popular da abelha que deseja buscar:\n");
                                scanf(" %39[^\n]",nome);

                                if(buscaMostraAbelha(abelhas,nome,sensores) != 0){
                                }
                                else{
                                    printf("Abelhas não encontradas!\n");
                                }
                            }
                            else{
                                printf("Nenhuma abelha cadastrada!\n");
                            }
                            break;
                        case 'D':
                        case 'd':
                           if(quantidadeAbelha(abelhas) == 0){
                                printf("Nenhuma abelha cadastrada para remover.\n");
                           }
                           else{
                                int id;
                                printf("Informe o ID da abelha que deseja remover:\n");
                                scanf("%d",&id);
                                if(existeAbelha(abelhas,id)){
                                    deletarAbelha(abelhas,id,sensores);
                                    printf("Abelha removida com sucesso!\n");
                                }
                                else{
                                    printf("ID de abelha invalido!\n");
                                }
                            }
                            break;
                        case 'E':
                        case 'e':   
                            // Lógica para alterar abelha
                            break;    
                        case 'F':
                        case 'f':
                            printf("Saindo do gerenciamento de abelhas!\n");
                            break;
                        default:
                            printf("ERRO Opção invalida!\n");
                    }
                    printf("Pressione enter para continuar:");
                    limpezaBuffer();
                    getchar(); 
                    system("clear || cls");
                }while(opcao2 != 'F' && opcao2 != 'f');
                break;
            case 'B':
            case 'b':
                do{
                    printf("---*Gerenciamento de sensores*---\n");
                    printf("A - Cadastrar\n");
                    printf("B - Listar\n");
                    printf("C - Buscar\n");
                    printf("D - Remover sensores associados a abelhas\n");
                    printf("E - Alterar\n");
                    printf("F - Sair\n");
                    printf("Escolha uma opção: ");
                    scanf(" %c",&opcao2);
                    system("clear || cls");
                    switch(opcao2){
                        case 'A':
                        case 'a':
                            if(quantidadeAbelha(abelhas) == 0){
                                printf("Nenhuma abelha cadastrada.Cadastre uma abelha antes!\n");
                            } else {
                                for(int i = 0;i < 100;i++){
                                    if(sensores[i].id == -1){
                                        sensores[i].id = i;
                                        registroSensores(&sensores[i],abelhas);
                                        printf("Sensor cadastrado com sucesso!\n");
                                        break;
                                    }
                                }
                            }
                            break;
                        case 'B':
                        case 'b':
                            if(quantidadeSensores(sensores) == 0){
                                printf("Nenhum sensor cadastrado.Cadastre um antes\n");
                            } 
                            else{
                                listarSensores(sensores);
                            }
                            break;
                        case 'C':
                        case 'c':
                            // Lógica para buscar sensor    
                            break;
                        case 'D':
                        case 'd':
                            // Lógica para deletar sensor
                            break;
                        case 'E':
                        case 'e':   
                            // Lógica para alterar sensor
                            break;    
                        case 'F':
                        case 'f':
                            printf("Saindo do gerenciamento de sensores!\n");
                            break;
                        default:
                            printf("ERRO Opção invalida!\n");
                    
                    }
                    printf("Pressione enter para continuar:");
                    limpezaBuffer();
                    getchar();  
                    system("clear || cls");
                }while(opcao2 != 'F' && opcao2 != 'f');
                break;
            case 'C':
            case 'c':
                do{
                    printf("---*Relatórios*---\n");
                    printf("A - Media geral de produção de mel\n");
                    printf("B - Temperatura media dos sensores\n");
                    printf("C - Quantidade de abelhas por região\n");
                    printf("D - Sair\n");
                    printf("Escolha uma opção: ");
                    scanf(" %c",&opcao2);
                    system("clear || cls");
                    switch(opcao2){
                        case 'A':
                        case 'a':
                            // Lógica para média geral de produção de mel
                            break;
                        case 'B':
                        case 'b':
                            // Lógica para temperatura média dos sensores
                            break;
                        case 'C':
                        case 'c':
                            // Lógica para quantidade de abelhas por região    
                            break;
                        case 'D':
                        case 'd':
                            printf("Saindo dos relatórios!\n");
                            break;
                        default:
                            printf("ERRO Opção invalida!\n");
                    }        
                    printf("Pressione enter para continuar:");
                    limpezaBuffer();
                    getchar();  
                    system("clear || cls");
                }while(opcao2 != 'D' && opcao2 != 'd');
            break;
            case 'D':
            case 'd':
                printf("Até logo!\n");
                return 0;
            default:
                printf("ERRO Opção invalida!\n");
        }        
        system("clear || cls");
    }while(1);
    return 0;
}