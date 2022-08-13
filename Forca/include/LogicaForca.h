
#define S_TAM 10
struct Jogadores{
	char nome[50];
	int host;
	int participante;
	int vazio;

};

void AdicionarJogadores(struct Jogadores jogadores[], int *qtd_jogadores){
    printf("Digite o nome do %dº jogador: ", *qtd_jogadores+1);
    scanf("%s", jogadores[*qtd_jogadores].nome);
    jogadores[*qtd_jogadores].vazio = 0;
    (*qtd_jogadores)++;
}

void DefinirHost(struct Jogadores jogadores[]){
	char hostnome[50];
	system("clear");
	printf("Digite o nome do jogador que será o HOST\n");
	int cont;
	printf("JOGADORES:\n");
	for(cont=0; cont<S_TAM; cont++){
	    if(jogadores[cont].vazio == 0){
	        printf("%s\n", jogadores[cont].nome);
	    }
	}
	printf("Nome: ");
	scanf("%s", hostnome);
	for(cont = 0; cont<S_TAM;cont++){
	   if(jogadores[cont].vazio == 0){
	       if(!strcmp(hostnome,jogadores[cont].nome)){
	           jogadores[cont].host = 1;		  
	           printf("%s será o host\n", jogadores[cont].nome);
		    printf("--------------\n");   
	       }
	   }
	}
};

void JogadaHost(struct Jogadores jogadores[], char *t, char *p){
    char tema[20], palavra[100];
    int cont;
    getchar();
    for(cont = 0; cont<S_TAM; cont++){
    	if(jogadores[cont].host == 1){
	    printf("%s, por favor digite o tema: ", jogadores[cont].nome);
	    fgets(tema, 20, stdin);
	    strcpy(t, tema);
    	    printf("%s, por favor digite a palavra:", jogadores[cont].nome);
            fgets(palavra, 100, stdin);
	    strcpy(p, palavra);
	}
    }
}
int JogadaJogador(struct Jogadores jogadores[], int vez, int tamanho,char *palavra, char *palavra_escondida){
	char chute;
	int c, tem_letra = 0;
	printf("\n%s escolha uma letra: ", jogadores[vez].nome);
	scanf("%c", &chute);
	getchar();
	for(c=0; c<tamanho; c++){
	    if(palavra[c] == chute){
	    	palavra_escondida[c] = chute;
		tem_letra = 1;
	    }
	}
	return tem_letra;
}
int Acabou(char *palavra_escondida, int tamanho, int qtd_erros){
    int c, acabou=1;
    for(c=0; c< tamanho; c++){
        if(palavra_escondida[c] == '_'){
	    acabou = 0;
	}
    }

    if(acabou){
	system("sleep 03");
	system("clear");
	printf("------------------------\n");
    	printf("Os jogadores ganharam!!!\n");
	printf("------------------------\n");
    }
    if(qtd_erros == 7){
	    		acabou = 1;
			system("sleep 03");
			system("clear");
			printf("------------------------\n");
			printf("O hosts ganhou!!!\n");
			printf("------------------------\n");
		}

    return acabou;
}
void MenuStart(void){
	system("clear");
	printf("----------\n");
	printf("Iniciando...\n");
	printf("----------\n");
}
int Start(void){
    struct Jogadores jogadores[S_TAM];
    int cont, p_tamanho, tem_letra;
    int qtd_jogadores = 0, gameover = 0, qtd_erros = 0, vez = 0;
    char tema[20], palavra[100], palavra_escondida[100];
    for(cont=0; cont<S_TAM; cont++){
        jogadores[cont].vazio = 1;
	jogadores[cont].host = 0;
    }
    char continuar= 'y';
    MenuStart();
   while(qtd_jogadores < 2){
       AdicionarJogadores(jogadores, &qtd_jogadores);
   }
   while(continuar == 'y'&& qtd_jogadores<=10){
   	printf("Deseja adicionar o %dº jogador?(y/n)", qtd_jogadores+1);
	getchar();
	scanf("%c", &continuar);
	if(continuar == 'y'){
	    AdicionarJogadores(jogadores, &qtd_jogadores);
	}
   }
   DefinirHost(jogadores);
   JogadaHost(jogadores, tema, palavra);
   system("clear");
   p_tamanho = strlen(palavra)-1;
   for(cont=0; cont < p_tamanho; cont++){
	if(palavra[cont] == 32){
		palavra_escondida[cont] = '-';
	}
	else{
   	palavra_escondida[cont] = '_';
	}
   }
   PrintarForca(qtd_erros, tema, p_tamanho, palavra_escondida);
   while(!gameover){
   	if(jogadores[vez].host == 0){
   		tem_letra = JogadaJogador(jogadores, vez, p_tamanho, palavra, palavra_escondida);
		if (tem_letra == 0){
			qtd_erros++;
		}
		system("clear");
   		PrintarForca(qtd_erros, tema, p_tamanho, palavra_escondida);
		
   	}
   	gameover = Acabou(palavra_escondida, p_tamanho, qtd_erros);
	if(vez == qtd_jogadores-1)
		vez = 0;
	else
		vez++;
   	}
}
