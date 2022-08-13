char* forca[] = {" ________________",
		 "|\t\t |",
		 "|\t\t |",
		 "|\t\t |",
		 "|\t\t ",
		 "|\t\t",
		 "|\t\t ",
		 "|\t\t",
		 "|\t\t ",
		 "|\t\t ",
		 "|  "};
char caracteres[] = {' ',
                     ' ',
		     ' ',
		     ' ',
		     ' ',
		     ' ',
		     ' ',
		     ' '
};
void MudarCaractere(int qtd_erros){
	switch(qtd_erros){
		case 0:
			break;
		case 1:
			caracteres[0] = '0';
			break;
		case 2:
			caracteres[1] = '/';
			break;
		case 3:
			caracteres[2] = '|';
			break;
		case 4:
			caracteres[3] = 92;
			break;
		case 5:
			caracteres[4] = '|';
			break;
		case 6:
			caracteres[5] = '/';
			break;
		case 7:
			caracteres[7] = 92;

		default:
			break;
	
	
	}	
}
void PrintarForca(int qtd_erros, char *t, int tamanho, char *palavra_escondida){
	int cont;
	for(cont=0; cont < 11; cont++){
		if(cont != 1 && cont != 4 && cont != 5 && cont != 6 && cont != 7 && cont != 10){
		    printf("%s\n", forca[cont]);
		}
		else{
		    MudarCaractere(qtd_erros);
		    printf("%s", forca[cont]);
		    if(cont == 1){
		    	printf("\t%s", t);
		    }
		    if(cont == 4)
		    	printf("%c\n", caracteres[cont-4]);
		    else if(cont == 5){
		         printf("%c%c%c\n", caracteres[cont-4], caracteres[cont-3], caracteres[cont-2]);
		    }
		    else if(cont == 6){
		    	printf("%c\n", caracteres[cont-2]);
		    }
		    else if(cont == 7){
		    	printf("%c%c%c\n", caracteres[cont-2], caracteres[cont-1], caracteres[cont]);
		    }
		    else if(cont == 10){
			int c;
		    	for(c=0; c< tamanho; c++){
				if (c < tamanho -1)
					printf("%c ", palavra_escondida[c]);
				else
					printf("%c\n", palavra_escondida[c]);
			}
		    }
		    }
	}
}
