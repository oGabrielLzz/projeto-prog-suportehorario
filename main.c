#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//=============================================Função para adicionar o horario de aula===================================================
void preenchendoHorariodeaula(int rotina[][17], int dia, int turno) {
    for (int j = 0; j < 17; j++){
        if(turno == 1){
            if (j >= 1 && j < 6){
                rotina[dia][j] = -1;
            }
        }  
        if(turno == 2){
            if (j >= 7 && j < 12){
                rotina[dia][j] = -1;
            } 
        }   
        if(turno == 3){
            if (j >= 11 && j < 16){
                rotina[dia][j] = -1;
            }
        } 
     }
  } 
//================================================Função para adicionar as materias====================================================
void preenchendomaterias(int rotina[5][16], int turno, int numMaterias) {
    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            if (turno == 1 && (j > 6 && j < 16)) {
                rotina[i][j] = rand() % numMaterias + 1;
            } else if (turno == 2 && ((j >= 1 && j <= 5) || (j > 11 && j < 16))) {
                rotina[i][j] = rand() % numMaterias + 1;
            } else if (turno == 3 && (j >= 1 && j <= 5) || (j >= 7 && j <= 11)) {
                rotina[i][j] = rand() % numMaterias + 1;
            }
        }
    }
}
//===============================================Iniciando nossa tabela de horarios===================================================
int main() {
    char nome[50];
    int idade;
    int d = 5, h = 17; // 5 dias da semana, 19 horas do dia
    int rotina[d][h];
    
    // Inicialize a matriz rotina
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            rotina[i][j] = 0;
        }
    }

//==================================================Lendo dados iniciais do usuario====================================================
    printf("-Seja bem vindo(a) ao seu suporte de horario para estudo\n");
    printf("-Digite seu nome:\n");
    scanf("%s", nome);

    int turno;
    printf("-Ola %s, Para comecarmos, preciso saber em qual turno você estuda?\n-Digite 1 para manha, 2 para tarde ou 3 para noite:\n", nome);
    scanf("%d", &turno);

    while (turno != 1 && turno != 2 && turno != 3) {
        printf("-Digite um valor valido.\n");
    }
    int numMaterias;
    int not;

    printf("Diga quantas materias voce tem no momento:\n");
    scanf("%d",&numMaterias);

    printf("Para calcularmos suas notas , Me diga quantas notas por materia voce ja tem\n");
    scanf("%d",&not);

    double notas[numMaterias][not];
    int pontosparaaprovacao[numMaterias];

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite quantos pontos precisa para ser aprovado na materia %d: ", i + 1);
        scanf("%d", &pontosparaaprovacao[i]);
    }

    for (int i = 0; i < numMaterias; i++) {
        printf("-Digite suas ultimas %d notas da materia %d:\n",not, i + 1);
        for (int j = 0; j < not; j++) {
            scanf("%lf", &notas[i][j]);
        }
    }
//=====================================================Parte matematica das notas========================================================

    for (int i = 0; i < numMaterias; i++) {
        double somaMat = 0;
        for (int j = 0; j < not; j++){
            somaMat += notas[i][j];
        }
        pontosparaaprovacao[i] = pontosparaaprovacao[i] - somaMat;
    }


//=================================================Amostra do resultado das notas========================================================= 

     printf("\n");  
      printf("\nPrioridade de materias:\n");
    for (int i = 0; i < numMaterias; i++) {
        printf("Materia %d: %d pontos faltando para aprovacao\n", i + 1, pontosparaaprovacao[i]);
    }

//==========================================Adicionando as materias na matriz tabela====================================================

    preenchendomaterias(rotina, turno, numMaterias);
    for(int i = 0; i < d; i++){
    preenchendoHorariodeaula(rotina, i, turno);
}

//==============================================Impressao da Matriz=============================================

 printf("\n");
    // Dias da semana
    char *dias_semana[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};
    printf("Rotina de Estudos:\n");

    // Imprima os cabeçalhos das horas
    printf("Dias\t");
    for (int i = 0; i < 17; i++) {
        int hora = 6 + i; // Calcula a hora a partir do índice da coluna
        printf("%02d:00  ", hora); // Imprime o horário no formato "hora:minuto"
    }
    printf("\n");

    // Imprima os dias e a matriz de rotina
    for (int i = 0; i < d; i++) {
        printf("%s\t", dias_semana[i]);

        for (int j = 0; j < h; j++) {
            printf("  %d    ", rotina[i][j]);
        }
        printf("\n");
    }
     printf("\n");
    printf("Tabela de orientação da matriz:\n"
           " 0 - tempolivre\n"
           "-1 - horario da escola\n"
           " 1 - primeira materia que precisa de mais estudo\n"
           " 2 - segunda materia que precisa de mais estudo\n"
           " 3 - terceira materia que precisa de mais estudo\n");

    return 0;
}