#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void mgotoxy(int x, int y)
{
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void tela(){
	int x;
	
	for(x=20;x<60;x++){ //horizontal ssuperior
				mgotoxy(x,10); 
 				printf("%c",219);
 			}
 
 			for(x=20;x<60;x++){ //horizontal inferior
				mgotoxy(x,20); 
 				printf("%c",219);
 			}	
	
			for(x=10;x<21;x++){ //vertical primaria
				mgotoxy(19,x); 	
 				printf("%c",219);
 			}
 			
			for(x=10;x<21;x++){ //vertical primaria
				mgotoxy(60,x); 	
 				printf("%c",219);
 			}
}
int main(){
	int p, d, quantlet1, quantlet2;
	char palavra[30], dica[30];
	
	tela();//monta a tela
	mgotoxy(28,12);
	printf("BEM-VINDO AO JOGO DA FORCA");
	
	mgotoxy(25,15);
	
	printf("Digite a palavra: ");
	scanf("%s", &palavra);
	
	mgotoxy(25,17);
	printf("Digite a dica: ");
	scanf("%s", &dica);
	
	quantlet1 = strlen(palavra);   //calcula o numero de letras das variaveis dica e palavra
	quantlet2 = strlen(dica);
	
	system("CLS");  //limpa a tela
	
	char tent;  //scanf das letras que vao ser entradas
	int i, x , chances = 6, cont = 0, finish = 0;  //numero de letras da palavra
	char letras[quantlet1];  //matriz da resposta
	
	
	
	for(i=0 ; i<quantlet1 ; i++){   //determina que todos os termos da matriz vao ser '_'
		
		letras[i] = ('_');
	}
	
	char vetorimg[20][20];
	int z, e;
	
	while(chances > 0 ){
		
		printf("\nDICA: ");
		
		for(x=0 ; x < quantlet2 ; x++){  // imprime a dica escolhida
	
			printf("%c", dica[x]);
		}
		
		for(x=0;x<79;x++){ //horizontal ssuperior
			mgotoxy(x,0); 
 			printf("%c",219);
 		}
 
 		for(x=0;x<79;x++){ //horizontal inferior
			mgotoxy(x,24); 
 			printf("%c",219);
 		}	
	
		for(x=1;x<5;x++){ //vertical linha pontilhada 
			mgotoxy(25,x); 	
 			printf("%c",124);
 		}

 		//imprime o boneco 
 	
		if(chances == 5){ // mostra cabeca e pescoco
			
			mgotoxy(25,5);   	
 			printf("%c",254);	
			
			mgotoxy(25,6);  	
 			printf("%c",179);
		}
			
 		if(chances == 4){ //mostra cabeca pescoco e braco esq
			
			mgotoxy(25,5);   	
 			printf("%c",254);	
			
			mgotoxy(24,6);  	
 			printf("%c",47); 
			
			mgotoxy(25,6);  	
 			printf("%c",179);	
		}
 			
 		if(chances == 3){ //mostra cabeca pescoco e braco esq e braco dir
			
			mgotoxy(25,5);   	
 			printf("%c",254);	
			
			mgotoxy(25,6);  	
 			printf("%c",179);
				
			mgotoxy(24,6);  	
 			printf("%c",47); 	
			
			mgotoxy(26,6);  
 			printf("%c",92);
		}
 			
 		if(chances == 2){ //mostra cabeca, pescoco, braco esq,  braco dir e perna esq
			
			mgotoxy(25,5);   	
 			printf("%c",254);	
			
			mgotoxy(25,6);  	
 			printf("%c",179);
			
			mgotoxy(24,6);  	
 			printf("%c",47); 	
			
			mgotoxy(26,6);  
 			printf("%c",92);
		
			mgotoxy(24,7);  	
 			printf("%c",47);
		}
 			
 		if(chances == 1){ //mostra cabeca, pescoco, braco esq,  braco dir, perna esq e perna dir
			
			mgotoxy(25,5);   	
 			printf("%c",254);	
			
			mgotoxy(25,6);  	
 			printf("%c",179);
			
			mgotoxy(24,6);  	
 			printf("%c",47); 	
			
			mgotoxy(26,6);  
 			printf("%c",92);
		
			mgotoxy(24,7);  	
 			printf("%c",47);
	
			mgotoxy(26,7);  
 			printf("%c",92);
		}	
 	

		printf("    \nCHANCES: %d\n\n", chances);  //imprime quantas chances o usuario ainda tem
		
		for(x=0 ;  x<quantlet1 ; x++){   //mostra o avanco do jogo na tela
			printf("%c ", letras[x]);
		}
		
		printf("\n\nLetra: ");	
		scanf("%s", &tent);

		for(x=0 ; x<quantlet1 ; x++){  //compara variavel com a letra entrada e cria matriz letras
		
		
			if(tent == palavra[x]){
			
			letras[x] = tent;
			cont++;
			}
			
			
		}
			
		if(cont == 0){ //desencrementa as chances caso o usuario erre a letra
			
		chances--;
		
		}
			
		cont = 0;  
		
		for(x=0 ; x<quantlet1 ; x++){  //confere se o jogo acabou ou nao
			
			if(letras[x] == '_'){
				
				finish++;
				
			}
		}
		
		if(finish == 0){  //faz a finalizacao caso o usuario acerte
			
			
			system("CLS");
			
			tela();
		 
			mgotoxy(28,12); 
 			printf("PARABENS VOCE ACERTOU!!!");
				
			mgotoxy(25,17);
			printf("A PALAVRA E: ");
			for(x=0 ; x<quantlet1; x++){
					
				printf("%c", letras[x]);
					
			}
 			
			system("PAUSE>>null");
			return 0;
			
		}
		
		finish = 0;
		system("CLS");
	}  
	
	//saiu do loop
	system("CLS");
	
	tela();
	
	mgotoxy(22,15); //termina o jogo com o usuario perdendo
	printf("VOCE PERDEU SUAS CHANCES ACABARAM!!!"); 
	system("PAUSE>>null");
	
	
	return 0;
}
