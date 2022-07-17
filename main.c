#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define CEDULAS 6
#define QUANTIDADE 2

void operarDinheiro(int quantidade,int cedulas,int mDinheiro[cedulas][quantidade],int i,int *cedulasUsuario,int *resto,int *totalCedulas,int *saque){
    if((*resto) == 0){  //caso o resto == 0, significa que é a primeira vez que estou fazendo operações com o dinheiro.
        cedulasUsuario[i] = (*saque)/mDinheiro[i][0];   // A única diferença é que na primeira instância eu calculo a qtd de cédulas que vao ser exibidas
        if(cedulasUsuario[i] > mDinheiro[i][1]){        // para o usuário com a variável saque. Nas demais instâncias, faço uso da variável resto.
            cedulasUsuario[i] = mDinheiro[i][1];
        }
        (*resto) = (*saque) - mDinheiro[i][0] * cedulasUsuario[i];
        mDinheiro[i][1] -= cedulasUsuario[i];
        (*totalCedulas) += cedulasUsuario[i];
    }
    else{
        cedulasUsuario[i] = (*resto)/mDinheiro[i][0];
        if(cedulasUsuario[i] > mDinheiro[i][1]){
            cedulasUsuario[i] = mDinheiro[i][1];
        }
        (*resto) -= mDinheiro[i][0] * cedulasUsuario[i];
        mDinheiro[i][1] -= cedulasUsuario[i];
        *totalCedulas += cedulasUsuario[i];
    }
    return;
}

void sacarDinheiro(int quantidade,int cedulas,int mDinheiro[cedulas][quantidade]){ //parametros apenas a matriz de dinheiro e o tamanho dela
    int saque,cedulasUsuario[6]={0},i,resto=0,totalCedulas=0;
    printf("Quanto deseja sacar?\n");
    scanf("%i",&saque);

    for(i=0;i<cedulas;i++){
        if(i != 0 ){ //caso for a primeira instância do loop, a operação com dinheiro será diferente
            if(resto > 0){  //se não for a primeira instância do loop mais externo e o resto for != 0 significa que ainda há operações a se fazer com o dinheiro
                switch(i){  //optei por usar o switch, pois dependendo da instância do loop terá mais casos ou menos casos para verificar
                    case 1: //os "casos" mencionados, são as posições da matriz relacionadas a quantidade de cédulas. (Caso eu esteja na 3 instância do loop, não há a posição i+3 na matriz)
                        if(mDinheiro[i][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+1][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+1,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+2][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+2,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+3][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+3,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+4][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+4,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else{
                            printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n\n");
                            for(int s = 0;s<cedulas;s++){   //loop para "devolver" as notas utilizadas durante as operações de saque, pois o saque não foi concluído
                                mDinheiro[s][1]+= cedulasUsuario[s];
                            }
                            system("Pause");
                            system("CLS || clear");
                            return;
                        }

                    break;

                    case 2:
                        if(mDinheiro[i][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+1][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+1,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+2][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+2,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+3][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+3,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else{
                            printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n\n");
                            for(int s = 0;s<cedulas;s++){
                                mDinheiro[s][1]+= cedulasUsuario[s];
                            }
                            system("Pause");
                            system("CLS || clear");
                            return;
                        }

                    break;

                    case 3:
                        if(mDinheiro[i][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+1][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+1,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+2][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+2,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else{
                            printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n\n");
                            for(int s = 0;s<cedulas;s++){
                                mDinheiro[s][1]+= cedulasUsuario[s];
                            }
                            system("Pause");
                            system("CLS || clear");
                            return;
                        }

                    break;

                    case 4:
                        if(mDinheiro[i][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else if(mDinheiro[i+1][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i+1,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else{
                            printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n\n");
                            for(int s = 0;s<cedulas;s++){
                                mDinheiro[s][1]+= cedulasUsuario[s];
                            }
                            system("Pause");
                            system("CLS || clear");
                            return;
                        }

                    break;

                    case 5:
                        if(mDinheiro[i][1] > 0){
                            operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);
                        }
                        else{
                            printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n\n");
                            for(int s = 0;s<cedulas;s++){
                                mDinheiro[s][1]+= cedulasUsuario[s];
                            }
                            system("Pause");
                            system("CLS || clear");
                            return;
                        }

                    break;
                }
            }
            else{ // Se o resto não for maior que 0, significa que não há mais operações para se fazer com o dinheiro
                system("CLS || clear");
                if(totalCedulas > 30){  //Verificando se o número de cédulas excedeu 30
                    printf("\n\nExcedeu o número de notas que podem ser impressas(30 cédulas)!!!\n\n");
                    for(int s = 0;s<cedulas;s++){
                        mDinheiro[s][1]+= cedulasUsuario[s];
                    }
                    system("Pause");
                    system("CLS || clear");
                    break;
                }
                else{ //Caso não tenha excedido o total de cédulas permitido, é exibido ao usuário as cédulas retiradas e a msg de saque concluído
                    printf("\nSaque Concluído!!!\n");
                    for(int s = 0;s<cedulas;s++){
                        printf("\nCedulas de R$%i = %i\n",mDinheiro[s][0], cedulasUsuario[s]);
                    }
                    printf("\n");
                }
                system("Pause");
                system("CLS || clear");
                break;
            }

        }
        else{ //else do if mais externo, que trata a primeira instância do loop
            if(mDinheiro[i][1] > 0){    //verifica se há cédulas de uma forma decrescente (50,20,10,5...)
                operarDinheiro(quantidade,cedulas,mDinheiro,i,cedulasUsuario,&resto,&totalCedulas,&saque);  //chamada da função que faz a operação com dinheiro
            }
            else if(mDinheiro[i+1][1] > 0){ //o i+1,2... significa a próxima casa da matriz relacionada a quantidade de cédulas
                operarDinheiro(quantidade,cedulas,mDinheiro,i+1,cedulasUsuario,&resto,&totalCedulas,&saque);
            }
            else if(mDinheiro[i+2][1] > 0){
                operarDinheiro(quantidade,cedulas,mDinheiro,i+2,cedulasUsuario,&resto,&totalCedulas,&saque);
            }
            else if(mDinheiro[i+3][1] > 0){
                operarDinheiro(quantidade,cedulas,mDinheiro,i+3,cedulasUsuario,&resto,&totalCedulas,&saque);
            }
            else if(mDinheiro[i+4][1] > 0){
                operarDinheiro(quantidade,cedulas,mDinheiro,i+4,cedulasUsuario,&resto,&totalCedulas,&saque);
            }
            else if(mDinheiro[i+5][1] > 0){
                operarDinheiro(quantidade,cedulas,mDinheiro,i+5,cedulasUsuario,&resto,&totalCedulas,&saque);
            }
            else{
                printf("\n\nNão há cédulas suficientes para efetuar o saque!!!\n");
                system("Pause");
                system("CLS || clear");
                return;
            }
        }
    }

    return;

}

void mostrarMatrizCedulas(int quantidade,int cedulas,int dinheiroDisponivel[cedulas][quantidade]){
    printf("CEDULAS\tQUANTIDADE\n");
    for(int i = 0; i < cedulas; i++){
        for(int s = 0; s < quantidade; s++){
            printf(" %i\t",dinheiroDisponivel[i][s]);
        }
        printf("\n");
    }
    system("Pause");
    system("CLS || clear");
    return;
}

float totalReais(int quantidade,int cedulas,int dinheiroDisponivel[cedulas][quantidade]){
    int totalDinheiro=0;
    for(int i = 0;i<cedulas;i++){
        totalDinheiro += dinheiroDisponivel[i][0] * dinheiroDisponivel[i][1];
    }
    return totalDinheiro;
}

void reporCedulas(int quantidade,int cedulas,int dinheiroDisponivel[cedulas][quantidade]){
    int opcao;
    do{
        printf("Deseja repor as cédulas de qual valor?\n");
        printf("1 - R$50\n2 - R$20\n3 - R$10\n4 - R$5\n5 - R$2\n6 - R$1\n7 - Sair");
        printf("\n\nDigite sua opcao: ");
        scanf("%i",&opcao);
        while(opcao < 1 || opcao > 7){
            printf("Valor inválido!!! Insira um valor válido: ");
            scanf("%i",&opcao);
        }

        system("CLS || clear");

        switch(opcao){
            case 1:
                printf("Digite o valor para notas de 50: ");
                scanf("%i",&dinheiroDisponivel[0][1]);
            break;

            case 2:
                printf("Digite o valor para notas de 20: ");
                scanf("%i",&dinheiroDisponivel[1][1]);
            break;

            case 3:
                printf("Digite o valor para notas de 10: ");
                scanf("%i",&dinheiroDisponivel[2][1]);
            break;

            case 4:
                printf("Digite o valor para notas de 5: ");
                scanf("%i",&dinheiroDisponivel[3][1]);
            break;

            case 5:
                printf("Digite o valor para notas de 2: ");
                scanf("%i",&dinheiroDisponivel[4][1]);
            break;

            case 6:
                printf("Digite o valor para notas de 1: ");
                scanf("%i",&dinheiroDisponivel[5][1]);
            break;

        }
        system("CLS || clear");
    }while(opcao != 7);


}

int main(){
    int opcao,dinheiroDisponivel[CEDULAS][QUANTIDADE]={50,7,20,0,10,3,5,0,2,0,1,0};
    setlocale(LC_ALL,"");

    do{
        printf("********************************************\n Terminal de Autoatendimento (ADMIN MODE) \n********************************************\n");
        printf("\n1 - Efetuar saque");
        printf("\n2 - Relatório de cédulas disponíveis");
        printf("\n3 - Valor total disponível");
        printf("\n4 - Efetuar reposição de cédulas");
        printf("\n5 - Sair do programa\n");
        printf("\nEscolha o que deseja fazer: ");
        scanf("%i",&opcao);
        while(opcao < 1 || opcao > 5){
            printf("Valor inválido!!! Insira um valor válido: ");
            scanf("%i",&opcao);
        }
        system("CLS || clear");

        if(opcao != 5){
            switch(opcao){
                case 1:
                    sacarDinheiro(QUANTIDADE,CEDULAS,dinheiroDisponivel); //Chamada da função principal para sacar dinheiro
                break;

                case 2:
                    mostrarMatrizCedulas(QUANTIDADE,CEDULAS,dinheiroDisponivel);
                break;

                case 3:
                    printf("\nO caixa tem R$%.2f\n\n",totalReais(QUANTIDADE,CEDULAS,dinheiroDisponivel));
                    system("Pause");
                    system("CLS || clear");
                break;

                case 4:
                    reporCedulas(QUANTIDADE,CEDULAS,dinheiroDisponivel);
                break;
            }

        }
        else{
            system("CLS || clear");
            printf("\nSaindo do programa...\n");
        }

    }while(opcao != 5);


    return 0;
}
