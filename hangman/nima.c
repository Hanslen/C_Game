#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void deadman(int choice);
int main(int argc, char *argv[]){
	int wordnum,i,play = 1,length,lengtha = 0,wordpo,life = 5,j = 0,win = 0,choice = 0;
	char playornot[1];
	int iw,jw;

	while(play == 1){
		//printf("Number of words:");
		//scanf("%d",&wordnum);
		//char word[wordnum][100];
		//for(i = 0;i<wordnum;i++){
		//	printf("Enter the word:");
		//	scanf("%s",word[i]);
		//}
		//printf("\n");
		//input words
		
		//wordpo = rand()%wordnum;
	FILE *cfPtr;
	srand((unsigned)time(NULL));
	char word[100];
	char oldword[100][100];
	//int asktime[100];     //this line caused the problem
	int asktimelength = 0;
	
	jw = 0;
	char dic[1][100];
	int inputlength, diclength;
	int count,filename;
	char *basic[10] = {"words.txt","computer.txt","name.txt"};
	if(argv[2] == '\0'){
		}
	else{
		inputlength = strlen(argv[2]);
		for(j = 1;j < 3;j++){
			diclength = strlen(basic[j]);
			if(inputlength == diclength){
				for(i = 0;i < inputlength;i++){
					if(basic[j][i] == argv[2][i]){
						filename = j;
					}
					else{
						filename = 0;
					}
				}
			}
		}
		for(i = 0;i < strlen(basic[filename]);i++){
			dic[0][i] = basic[filename][i];
		}
		switch(filename){
			case 0:	iw = rand()%235886;
			case 1: iw = rand()%13;
			case 2: iw = rand()%7;
		}

	}
	if((cfPtr = fopen(dic[0],"r")) == NULL){
		puts("File could not be opened");
	}
	else{
		fscanf(cfPtr,"%s",word);
		while(!feof(cfPtr)){
			if(iw == jw){
			printf("%s",word);
			break;
			}
			fscanf(cfPtr,"%s",word);
			jw++;
		}
	}

		length = strlen(word);
		char guess[length];
		for(i = 0;i<length;i++){
			guess[i] = '_';
		}
		deadman(choice);
		printf("word:");
		for(i = 0;i<length;i++){
			printf("%c ",guess[i]);
		}
		printf("Guess (%d lives):",life);
		char type[length];
		while(strcmp(guess,type) != 0 && life != 0 && win == 0){
			scanf("%s",type);
			if(type[1] == '\0'){
				lengtha = 1;
			}
			j = 0;
			if(lengtha == 1){
				for(i = 0;i < length;i++){
					if(type[0] == word[i]){
						guess[i] = type[0];
						j = 1;
					}

				}
				if(j == 0){
					printf("o\n");
					life = life - 1;
					choice = choice + 1;
				}
								
			}
			else{
				if(strcmp(word,type) == 0){
					win = 1;
				}
				else{
					life = life - 1;
					choice = choice + 1;
				}
				
			}
			if(win != 1){
			deadman(choice);
			printf("word:");
			for(i = 0;i<length;i++){
			printf("%c ",guess[i]);
			}
			printf("Guess (%d lives):",life);
			lengtha = 0;
			}

		}

		if(life == 0){
			printf("You die QAQ!\n");
		}
		else{
			printf("Correct!\n");
			win = 0; 
		}
		printf("Do you want to player again (y/n)?");
		scanf("%s",playornot);
		if(playornot[0] == 'n'){
			play = 0;
		}
		else{
			life = 5;
			choice = 0;
		}
		printf("\n");
		
	}
	
}
void deadman(int choice){
	int i;
	switch(choice){
		case 0:printf("           ...............\n");
    			for(i = 0;i<18;i++){
        			printf("                         .\n");
    				}
    			printf(".....................................\n");break;
		case 1:printf("           ...............\n");
    			printf("                  .      .\n                  .      .\n                  .      .\n                  .      .\n                .   .    .\n               .     .   .\n                .   .    .\n                  .      .\n");
    			for(i = 0;i<10;i++){
        			printf("                         .\n");
    			}
    			printf(".....................................\n");break;
		case 2:printf("           ...............\n");
    			printf("                  .      .\n                  .      .\n                  .      .\n                  .      .\n                .   .    .\n               .     .   .\n                .   .    .\n                  .      .\n");
    			printf("                  .      .\n              .....      .\n");
    			for(i = 0;i<8;i++){
        			printf("                         .\n");
    			}
    			printf(".....................................\n");break;
		case 3:printf("           ...............\n");
    			printf("                  .      .\n                  .      .\n                  .      .\n                  .      .\n                .   .    .\n               .     .   .\n                .   .    .\n                  .      .\n");
    			printf("                  .      .\n              .........  .\n                  .      .\n                  .      .\n                  .      .\n");
    			for(i = 0;i<5;i++){
        			printf("                         .\n");
    			}
    			printf(".....................................\n");break;
		case 4:printf("           ...............\n");
    			printf("                  .      .\n                  .      .\n                  .      .\n                  .      .\n                .   .    .\n               .     .   .\n                .   .    .\n                  .      .\n");
    			printf("                  .      .\n              .........  .\n                  .      .\n                  .      .\n                  .      .\n");
    			printf("                .        .\n               .         .\n");
    			for(i = 0;i<3;i++){
        			printf("                         .\n");
    			}
    			printf(".....................................\n");break;
		case 5:printf("           ...............\n");
    			printf("                  .      .\n                  .      .\n                  .      .\n                  .      .\n                .   .    .\n               .     .   .\n                .   .    .\n                  .      .\n");
    			printf("                  .      .\n              .........  .\n                  .      .\n                  .      .\n                  .      .\n");
    			printf("                .   .     .\n               .     .   .\n");
    			for(i = 0;i<3;i++){
        			printf("                         .\n");
    			}
    			printf(".....................................\n");break;
	}
}
