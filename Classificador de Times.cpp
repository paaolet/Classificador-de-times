	#include <stdio.h>
	#include <locale.h>
	#include <math.h>
	#include <string.h>
	
			char NOMETIMES [4][50], CLASSIFICACAO[4][50];
			int PONTOSTURNO [4][2], TOTALPONTOS[4], x, y, pont[4];
		
		main(){
			setlocale (LC_ALL, "Portuguese");
			for (x = 0;x<= 3; x++){
				printf	("Digite o time:\n");
				gets (NOMETIMES[x]);
				printf ("\n=====================================\n");
				for (y = 0; y<= 1; y++){
				printf ("Quantos pontos o %s fez no %d° turno?\n", NOMETIMES[x], y + 1);
				scanf ("%d", &PONTOSTURNO[x][y]);
				printf ("\n=====================================\n");
				}
				fflush(stdin);
			}
			for (x = 0; x<= 3; x++){
				TOTALPONTOS[x] = PONTOSTURNO[x][0] + PONTOSTURNO[x][1];
			}
				for (x = 0; x<= 3; x++){
					for (y = 0; y<= 3; y++){
						if (TOTALPONTOS[x] > TOTALPONTOS[y]){
							pont [x]++;
						}else if (TOTALPONTOS[x] == TOTALPONTOS[y]){
							if (PONTOSTURNO[x][1] > PONTOSTURNO[y][1]){
								pont[x]++;
							}else if (PONTOSTURNO[x][1] == PONTOSTURNO[y][1]){
							pont[x]++;
							pont[y]--;	
							}	
						}
					}
					strcpy (CLASSIFICACAO[pont[x]], NOMETIMES[x]);
				}
			printf ("INFORMAÇÕES DOS TIMES NO CAMPEONATO:\n\n");
		for (x = 0; x<= 3; x++){
			printf ("%s:\n", NOMETIMES[x]);
			printf ("Pontos no primeiro turno: %d pontos\n", PONTOSTURNO[x][0]);
			printf ("Pontos no segundo turno: %d pontos\n", PONTOSTURNO[x][1]);
			printf ("Total de pontos: %d pontos \n", TOTALPONTOS[x]);
			printf ("\n**********************\n");
		}
		y = 1;
		printf ("Classificação do campeonato:\n");
		for (x = 3; x>= 0; x--){
			printf ("%d° lugar: %s\n", y, CLASSIFICACAO[x]);
			y++;
		}
		printf ("\n\n");
		printf ("Time campeão: %s\n", CLASSIFICACAO[3]);
		printf ("Time vice-campeão: %s\n", CLASSIFICACAO[2]);
		printf ("Pior time do campeonato: %s\n", CLASSIFICACAO[0]);
	}
