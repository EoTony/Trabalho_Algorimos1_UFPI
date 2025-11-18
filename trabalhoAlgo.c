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
int existeAbelha(Abelha p[], int id){
    for(int i = 0;i < 50;i++){
        if(p[i].id == id){
            return 1;
        }
    }
    return 0;  
}
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
    const char regioes[][39] = {"Norte","Nordeste","Centro-Oeste","Sudeste","Sul"};
    int opcao;  
    do{
        printf("Informe o nome popular:\n");
        scanf(" %39[^\n]",p->nomePopular);
        if(strlen(p->nomePopular) == 0){
            printf("!!! Nome invalido! Tente novamente. !!!\n");
        } 
    }while(strlen(p->nomePopular) == 0);
    do{
        printf("Informe o nome cientifico:\n");
        scanf(" %49[^\n]",p->nomeCientifico);
        if(strlen(p->nomeCientifico) == 0){
            printf("!!! Nome invalido! Tente novamente. !!!\n");
        }
    }while(strlen(p->nomeCientifico) == 0);
    do{
        printf("Escolha a regiao:\n");
        printf("0 - Norte\n");
        printf("1 - Nordeste\n");
        printf("2 - Centro-Oeste\n");
        printf("3 - Sudeste\n");
        printf("4 - Sul\n");
        printf("Digite o numero correspondente a regiao:\n");
        if(scanf("%d",&opcao) != 1){
            limpezaBuffer();
            opcao = -1;
        }
        if(opcao < 0 || opcao > 4){
            printf("!!! Regiao invalida! Tente novamente. !!!\n");
        }
    }while(opcao < 0 || opcao > 4);
    strcpy(p->regiao,regioes[opcao]);
    do{
        printf("Informe a producao de mel (em kg):\n");
        if(scanf("%f",&p->producaoMel) != 1){
            limpezaBuffer();
            p->producaoMel = -1;
        }
        if(p->producaoMel < 0){
            printf("!!! Producao invalida! Tente novamente. !!!\n");
        }
    }while(p->producaoMel < 0);
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
int alterarAbelha(Abelha *p,int opcao){
    switch(opcao){
        case 1:
            do{
                printf("Informe o novo nome popular:\n");
                scanf(" %39[^\n]",p->nomePopular);
                if(strlen(p->nomePopular) == 0){
                    printf("Nome invalido!Tente novamente.\n");
                }
            }while(strlen(p->nomePopular) == 0);
            break;
        case 2:
            do{
                printf("Informe o novo nome cientifico:\n");
                scanf(" %49[^\n]",p->nomeCientifico);
                if(strlen(p->nomeCientifico) == 0){
                    printf("!!! Nome invalido! Tente novamente. !!!\n");
                }
            }while(strlen(p->nomeCientifico) == 0);
            break;
        case 3:
            const char regioes[][39] = {"Norte","Nordeste","Centro-Oeste","Sudeste","Sul"};
            int opcaoRegiao;
            do{
                printf("Escolha a regiao:\n");
                printf("0 - Norte\n");
                printf("1 - Nordeste\n");
                printf("2 - Centro-Oeste\n");
                printf("3 - Sudeste\n");
                printf("4 - Sul\n");
                printf("Digite o numero correspondente a regiao:\n");
                if(scanf("%d",&opcaoRegiao) != 1){
                    limpezaBuffer();
                    opcaoRegiao = -1;
                }
                if(opcaoRegiao < 0 || opcaoRegiao > 4){
                    printf("!!! Regiao invalida! Tente novamente. !!!\n");
                }
            }while(opcaoRegiao < 0 || opcaoRegiao > 4);
            strcpy(p->regiao,regioes[opcaoRegiao]);
            break;
        case 4:
            do{
                printf("Informe a nova producao de mel (em kg):\n");
                if(scanf("%f",&p->producaoMel) != 1){
                    limpezaBuffer();
                    p->producaoMel = -1;
                }
                if(p->producaoMel < 0){
                    printf("!!! Producao invalida! Tente novamente. !!!\n");
                }
            }while(p->producaoMel < 0);  
            break;               
        default:
            printf("!!! Opcao invalida! !!!\n");
            break;
    }
    return 0;
}
int registroSensores(Sensor *p1, Abelha *p2){
    const char tipo[][13] = {"Temperatura","Umidade","Luminosidade"};
    int opcao;
    do{
        printf("Escolha o tipo de sensor:\n");
        printf("0 - Temperatura\n");
        printf("1 - Umidade\n");
        printf("2 - Luminosidade\n");
        printf("Digite o numero correspondente ao tipo:\n");
        if(scanf("%d",&opcao) != 1){
            limpezaBuffer();
            opcao = -1;
        }
        if(opcao < 0 || opcao > 2){
            printf("!!! Tipo invalido! Tente novamente. !!!\n");
        }
    }while(opcao < 0 || opcao > 2);
    strcpy(p1->tipo,tipo[opcao]);
    do{
        printf("Informe o valor do sensor:\n");
        if(scanf("%f",&p1->valor) != 1){
            limpezaBuffer();
            p1->valor = -1;
        }
        if(p1->valor < 0){
            printf("!!! Valor invalido! Tente novamente. !!!\n");
        }
    }while(p1->valor < 0);
    do{
        printf("Informe o ID da abelha associada:\n");
        if(scanf("%d",&p1->idAbelha) == 1){
            for(int j = 0;j < 50;j++){
                if(p2[j].id == p1->idAbelha){
                    return 1;
                }
            }
        }
            else{
                printf("!!! ID de abelha invalido! !!!\n");
                limpezaBuffer();
            }
    }while(1);
    return 0;
}    
int deletarAbelha(Abelha p1[], int id, Sensor p2[]){
    int total = quantidadeAbelha(p1);
    for(int i = 0;i < total;i++){
        if(p1[i].id == id){
            for(int j = 0;j < 100;j++){
                if(p2[j].idAbelha == id && p2[j].id != -1){
                    p2[j].id = -1;
                    p2[j].idAbelha = -1;
                    p2[j].valor = 0;
                    p2[j].tipo[0] = '\0';
                }
            }
            for(int j = i;j < total - 1;j++){
                p1[j] = p1[j+1];
                for(int k = 0;k < 100;k++){
                    if(p2[k].idAbelha == p1[j].id){
                        p2[k].idAbelha -= 1;
                    }
                }
                p1[j].id -= 1;
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
        if((p1[i].id >= 0 && strstr(p1[i].nomePopular,nome) != NULL)|| (p1[i].id >= 0 && strcasecmp(p1[i].nomeCientifico,nome) == 0)){
            existe = 1;
            printfAbelha(p1[i]);
            if(quantidadeSensores(p2) > 0){
                printf("Sensores associados:\n");
                for(int j = 0;j < 100;j++){
                    if(p1[i].id == p2[j].idAbelha){
                    printfSensor(p2[j]);
                    }
                }
            }
            else{
                printf("Nenhum sensor associado a esta abelha.\n");
            }   
            printf("---------------\n");
            printf("\n");
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
void buscarSensor(Sensor s[], int idAbelha){
    int existe = 0;
    for(int i = 0;i < 100;i++){
        if(s[i].idAbelha == idAbelha && s[i].id != -1){
            existe = 1;
            printfSensor(s[i]);
            printf("*-------------------------*\n");
        }
    }
    if(existe == 0){
        printf("*-------------------------*\n");
        printf("Nenhum sensor encontrado.\n");
        printf("*-------------------------*\n");
    }
}
int deletarSensor(Sensor s[], int idSensor){
    for(int i = 0;i < 100;i++){
        if(s[i].id == idSensor){
            s[i].id = -1;
            s[i].idAbelha = -1;
            s[i].valor = 0;
            s[i].tipo[0] = '\0';
            return 1;
        }
    }
    return 0;
}
int alterarSensor(Sensor *p,int opcao){
    switch(opcao){
        case 1:
            const char tipo[][13] = {"Temperatura","Umidade","Luminosidade"};
            int opcaoTipo;
            do{
                printf("Escolha o tipo de sensor:\n");
                printf("0 - Temperatura\n");
                printf("1 - Umidade\n");
                printf("2 - Luminosidade\n");
                printf("Digite o numero correspondente ao tipo:\n");
                if(scanf("%d",&opcaoTipo) != 1){
                    limpezaBuffer();
                    opcaoTipo = -1;
                }
                if(opcaoTipo < 0 || opcaoTipo > 2){
                    printf("Tipo invalido!Tente novamente.\n");
                }
            }while(opcaoTipo < 0 || opcaoTipo > 2);
            strcpy(p->tipo,tipo[opcaoTipo]);
            break;
        case 2:
            do{
                printf("Informe o novo valor do sensor:\n");
                if(scanf("%f",&p->valor) != 1){
                    limpezaBuffer();
                    p->valor = -1;
                }
                if(p->valor < 0){
                    printf("Valor invalido! Tente novamente.\n");
                }
            }while(p->valor < 0);
            break;               
        default:
            printf("Opcao invalida!\n");
            break;
    }
    return 0;
}
double temperaturaMedia(Sensor p[]){
    double soma = 0;
    int cont = 0;
    for(int i = 0;i < 100;i++){
        if(p[i].id != -1 && strcmp(p[i].tipo,"Temperatura") == 0){
            soma += p[i].valor;
            cont++;
        }
    }
    if(cont == 0){
        return 0;
    }
    return soma/cont;
}
int quantidadePorRegiao(Abelha p[], char regiao[]){
    int cont = 0;
    for(int i = 0;i < 50;i++){
        if(p[i].id != -1 && strcmp(p[i].regiao,regiao) == 0){
            cont++;
        }
    }
    return cont;
}
double producaoMediaMel(Abelha p[]){
    double soma = 0;
    int cont = 0;
    for(int i = 0;i < 50;i++){
        if(p[i].id != -1){
            soma += p[i].producaoMel;
            cont++;
        }
    }
    if(cont == 0){
        return 0;
    }
    return soma/cont;
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
    char opcao,opcao2,opcao3,opcao4;
    do{
    printf("============================================\n");
    printf("=              BeeMonitor C               =\n");
    printf("============================================\n");
        printf("A - Gerenciar Abelhas\n");
        printf("B - Gerenciar Sensores\n");
        printf("C - Relatorios\n");
        printf("D - Sair\n");
    printf(">> Escolha uma opcao: ");
    scanf(" %c",&opcao);
        system("clear || cls");
        switch(opcao){
            case 'A':
            case 'a':
                do{
                    printf("============================================\n");
                    printf("=        Gerenciamento de Abelhas         =\n");
                    printf("============================================\n");
                    printf("A - Cadastrar\n");
                    printf("B - Listar\n");
                    printf("C - Buscar\n");
                    printf("D - Remover registros de abelhas\n");
                    printf("E - Alterar\n");
                    printf("F - Sair\n");
                    printf(">> Escolha uma opcao: ");
                    scanf(" %c",&opcao2);
                    system("clear || cls");
                    switch(opcao2){
                        case 'A':
                        case 'a':
                            if(quantidadeAbelha(abelhas) == 50){
                                printf("*-------------------------*\n");
                                printf("Limite de abelhas cadastradas atingido.\n");
                                printf("*-------------------------*\n");
                                break;
                            }
                            else{  
                                for(int i = 0;i < 50;i++){
                                    if(abelhas[i].id == -1){
                                        abelhas[i].id = i;
                                        registroAbelhas(&abelhas[i]);
                                        printf("*-------------------------*\n");
                                        printf("Abelha cadastrada com sucesso!\n");
                                        printf("*-------------------------*\n");
                                        break;
                                    }
                                }
                            }    
                            break;
                        case 'B':
                        case 'b':
                            if(quantidadeAbelha(abelhas) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhuma abelha cadastrada.\n");
                                printf("*-------------------------*\n");
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
                                do{
                                    printf("Informe o nome popular da abelha que deseja buscar:\n");
                                    scanf(" %39[^\n]",nome);
                                    if(strlen(nome) == 0){
                                        printf("Nome invalido!Tente novamente.\n");
                                    }
                                }while(strlen(nome) == 0);
                                if(buscaMostraAbelha(abelhas,nome,sensores) != 0){
                                }
                                else{
                                    printf("*-------------------------*\n");
                                    printf("Abelhas nao encontradas!\n");
                                    printf("*-------------------------*\n");
                                }
                            }
                            else{
                                printf("*-------------------------*\n");
                                printf("Nenhuma abelha cadastrada!\n");
                                printf("*-------------------------*\n");
                            }
                            break;
                        case 'D':
                        case 'd':
                      if(quantidadeAbelha(abelhas) == 0){
                          printf("*-------------------------*\n");
                          printf("Nenhuma abelha cadastrada para remover.\n");
                          printf("*-------------------------*\n");
                      }
                           else{
                                int id;
                                do{
                                    printf("Informe o ID da abelha que deseja remover:\n");
                                    if(scanf("%d",&id) != 1){
                                        limpezaBuffer();
                                        id = -1;
                                    }
                                    if(id < 0){
                                            printf("!!! ID invalido! Tente novamente. !!!\n");
                                        }
                                }while(id < 0);
                                if(existeAbelha(abelhas,id)){
                                    char confirma;
                                    printf("Deseja realmente remover?(digite S para confirmar)\n");
                                    scanf(" %c",&confirma);
                                    switch (confirma){
                                    case 'S':
                                    case 's':
                                        if(deletarAbelha(abelhas,id,sensores)){
                                            printf("*-------------------------*\n");
                                            printf("Abelha removida com sucesso!\n");
                                            printf("*-------------------------*\n");
                                        }
                                        else{
                                            printf("!!! Erro ao remover abelha! !!!\n");
                                        }
                                        break;
                                    default:
                                        printf("* Remocao cancelada! *\n");
                                        break;
                                    }
                                }
                                else{
                                    printf("!!! ID de abelha invalido! !!!\n");
                                }
                            }
                            break;
                        case 'E':
                        case 'e': {
                            printf("Informe o ID da abelha que deseja alterar:\n");
                            int id,opcaoAlterar;
                                if(scanf("%d",&id) != 1){
                                        limpezaBuffer(); 
                                        printf("!!! Entrada invalida. !!!\n"); 
                                        break; 
                                }
                            if(existeAbelha(abelhas,id)){
                                printf("O que deseja alterar?\n");
                                printf("1 - Nome Popular\n");
                                printf("2 - Nome Cientifico\n");    
                                printf("3 - Regiao\n");
                                printf("4 - Producao de Mel\n");
                                printf("Digite o numero correspondente a opcao:\n");
                                if(scanf("%d",&opcaoAlterar) != 1){ 
                                    limpezaBuffer(); 
                                    printf("!!! Entrada invalida. !!!\n"); 
                                    break; 
                                }
                                for(int i = 0;i < 50;i++){
                                    if(abelhas[i].id == id){
                                        alterarAbelha(&abelhas[i],opcaoAlterar);
                                        printf("*-------------------------*\n");
                                        printf("Abelha alterada com sucesso!\n");
                                        printf("*-------------------------*\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                printf("!!! ID de abelha invalido! !!!\n");
                            }
                            break;
                        }
                        case 'F':
                        case 'f':
                            printf("*-------------------------*\n");
                            printf("Saindo do gerenciamento de abelhas!\n");
                            printf("*-------------------------*\n");
                            break;
                            default:
                                printf("!!! ERRO Opcao invalida! !!!\n");
                    }
                    printf("---- Pressione enter para continuar ----\n");
                    limpezaBuffer();
                    getchar(); 
                    system("clear || cls");
                }while(opcao2 != 'F' && opcao2 != 'f');
                break;
            case 'B':
            case 'b':
                do{
                    printf("============================================\n");
                    printf("=         Gerenciamento de Sensores       =\n");
                    printf("============================================\n");
                    printf("A - Cadastrar\n");
                    printf("B - Listar\n");
                    printf("C - Buscar\n");
                    printf("D - Remover sensores associados a abelhas\n");
                    printf("E - Alterar\n");
                    printf("F - Sair\n");
                    printf(">> Escolha uma opcao: ");
                    scanf(" %c",&opcao3);
                    system("clear || cls");
                    switch(opcao3){
                        case 'A':
                        case 'a':
                            if(quantidadeAbelha(abelhas) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhuma abelha cadastrada! Cadastre uma abelha antes.\n");
                                printf("*-------------------------*\n");
                            } 
                            else{
                                for(int i = 0;i < 100;i++){
                                    if(sensores[i].id == -1){
                                        sensores[i].id = i;
                                        registroSensores(&sensores[i],abelhas);
                                        printf("*-------------------------*\n");
                                        printf("Sensor cadastrado com sucesso!\n");
                                        printf("*-------------------------*\n");
                                        break;
                                    }
                                }
                            }
                            break;
                        case 'B':
                        case 'b':
                            if(quantidadeSensores(sensores) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhum sensor cadastrado. Cadastre um antes.\n");
                                printf("*-------------------------*\n");
                            } 
                            else{
                                listarSensores(sensores);
                            }
                            break;
                        case 'C':
                        case 'c':
                            if(quantidadeAbelha(abelhas) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhuma abelha cadastrada! Cadastre uma abelha antes.\n");
                                printf("*-------------------------*\n");
                            } 
                            else{
                                int idAbelha;
                                do{
                                    printf("Informe o ID da abelha para buscar seus sensores:\n");
                                    if(scanf("%d",&idAbelha) != 1){
                                            limpezaBuffer();
                                            idAbelha = -1;
                                        }
                                        if(idAbelha < 0){
                                                    printf("!!! ID invalido! Tente novamente. !!!\n");
                                                }
                                }while(idAbelha < 0);
                                if(existeAbelha(abelhas,idAbelha)){
                                    buscarSensor(sensores,idAbelha);
                                }
                                    else{
                                        printf("!!! ID de abelha invalido! !!!\n");
                                    }
                            }  
                            break;
                        case 'D':
                        case 'd':
                            if(quantidadeSensores(sensores) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhum sensor cadastrado para remover.\n");
                                printf("*-------------------------*\n");
                            }
                            else{
                                int idSensor;
                                do{
                                    printf("Informe o ID do sensor que deseja remover:\n");
                                    if(scanf("%d",&idSensor) != 1){
                                            limpezaBuffer();
                                            idSensor = -1;
                                        }
                                        if(idSensor < 0){
                                            printf("!!! ID invalido! Tente novamente. !!!\n");
                                        }
                                }while(idSensor < 0);
                                char confirma;
                                printf("Deseja realmente remover?(digite S para confirmar)\n");
                                scanf(" %c",&confirma);
                                switch (confirma){
                                case 'S':
                                case 's':
                                    if(deletarSensor(sensores,idSensor)){
                                        printf("*-------------------------*\n");
                                        printf("Sensor removido com sucesso!\n");
                                        printf("*-------------------------*\n");
                                        
                                    }
                                        else{
                                        printf("!!! Erro ao remover sensor! !!!\n");
                                    }
                                    break;
                                default:
                                    printf("*-------------------------*\n");
                                    printf("Remocao cancelada!\n");  
                                    printf("*-------------------------*\n");
                                    break;
                                }               
                            }
                            break;
                        case 'E':
                        case 'e':   
                            if(quantidadeSensores(sensores) == 0){
                                printf("*-------------------------*\n");
                                printf("Nenhum sensor cadastrado para alterar.\n");
                                printf("*-------------------------*\n");
                            }
                            else{
                                int idSensor,opcaoAlterar;
                                printf("Informe o ID do sensor que deseja alterar:\n");
                if(scanf("%d",&idSensor) != 1){
                    limpezaBuffer(); 
                    printf("!!! Entrada invalida. !!!\n"); 
                    break; 
                }
                                int existe = 0;
                                for(int i = 0;i < 100;i++){
                                    if(sensores[i].id == idSensor){
                                        existe = 1;
                                        printf("O que deseja alterar?\n");
                                        printf("1 - Tipo\n");
                                        printf("2 - Valor\n");
                                        printf("Digite o numero correspondente a opcao:\n");
                                        if(scanf("%d",&opcaoAlterar) != 1){ 
                                                    limpezaBuffer(); 
                                                    printf("!!! Entrada invalida. !!!\n"); 
                                                    break; 
                                                }
                                        alterarSensor(&sensores[i],opcaoAlterar);
                                        printf("*-------------------------*\n");
                                        printf("Sensor alterado com sucesso!\n");
                                        printf("*-------------------------*\n");
                                        break;
                                    }
                                }
                                if(existe == 0){
                                    printf("*-------------------------*\n");
                                    printf("ID de sensor invalido!\n");
                                    printf("*-------------------------*\n");
                                }
                            }
                            break;    
                        case 'F':
                        case 'f':
                            printf("*-------------------------*\n");
                            printf("Saindo do gerenciamento de sensores\n");
                            printf("*-------------------------*\n");
                            break;
                        default:
                            printf("!!! ERRO Opcao invalida! !!!\n");
                    
                    }
                    printf("---- Pressione enter para continuar ----\n");
                    limpezaBuffer();
                    getchar();  
                    system("clear || cls");
                }while(opcao3 != 'F' && opcao3 != 'f');
                break;
            case 'C':
            case 'c':
                do{
                    printf("============================================\n");
                    printf("=               Relatórios                =\n");
                    printf("============================================\n");
                    printf("A - Media geral de produção de mel\n");
                    printf("B - Temperatura media dos sensores\n");
                    printf("C - Quantidade de abelhas por região\n");
                    printf("D - Sair\n");
                    printf(">> Escolha uma opcao: ");
                    scanf(" %c",&opcao4);
                    system("clear || cls");
                    switch(opcao4){
                        case 'A':
                        case 'a':
                            printf("Media geral de producao de mel: %.2f kg\n",producaoMediaMel(abelhas));
                            break;
                        case 'B':
                        case 'b':
                            printf("Temperatura media dos sensores: %.2f\n",temperaturaMedia(sensores));
                            break;
                        case 'C':
                        case 'c':
                            int totalRegioes[5] = {0};
                            const char regioes[][39] = {"Norte","Nordeste","Centro-Oeste","Sudeste","Sul"};
                            for(int i = 0;i < 5;i++){
                                totalRegioes[i] = quantidadePorRegiao(abelhas,regioes[i]);
                            }
                            printf("Quantidade de abelhas por regiao:\n");
                            for(int i = 0;i < 5;i++){
                                printf("%s: %d abelhas\n",regioes[i],totalRegioes[i]);
                            }
                            break;
                        case 'D':
                        case 'd':
                            printf("*-------------------------*\n");
                            printf("Saindo dos relatórios!\n");
                            printf("*-------------------------*\n");
                            break;
                        default:
                            printf("!!! ERRO Opcao invalida! !!!\n");
                    }        
                    printf("---- Pressione enter para continuar ----\n");
                    limpezaBuffer();
                    getchar();  
                    system("clear || cls");
                }while(opcao4 != 'D' && opcao4 != 'd');
            break;
            case 'D':
            case 'd':
                printf("*=========================*\n");
                printf("Ate logo!\n");
                printf("*=========================*\n");
                return 0;
            default:
                printf("!!! ERRO Opcao invalida! !!!\n");
        }        
        system("clear || cls");
    }while(1);
    return 0;
}
