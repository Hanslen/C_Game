#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void deadman(int choice);
int main(int argc, char *argv[]){
	int wordnum,i,play = 1,length,lengtha = 0,wordpo,life = 5,j = 0,win = 0,choice = 0,winf = 0;
	char playornot[1];
	int iw,jw;
	int choicetime = 0;
	char oldword[100];
	int oldlife, oldchoicetime;
	char oldwin[10];
	FILE *out;
	FILE *cfPtr;
	if((out = fopen("hangman-score.txt", "r")) == NULL){
			puts("File could not be opened.");
		}

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
	srand((unsigned)time(NULL));
	char word[100];
	jw = 0;
	int a[100];
	int lines = 0;
	if(argc == 1){
		cfPtr = fopen("words.txt", "r");
		}
	else{
		cfPtr = fopen(argv[2],"r");
	}
	while (!feof(cfPtr)) {
		fscanf (cfPtr, "%s", word);
		lines++;
	}
	rewind (cfPtr); //back to first line
	iw = rand()%lines;

	if((cfPtr)== NULL){
		puts("File could not be opened");
	}
	else{
		fscanf(cfPtr,"%s",word);
		while(!feof(cfPtr)){
			if(iw == jw){
			
			break;
			}
			fscanf(cfPtr,"%s",word);
			jw++;
		}
	}

		//junge if the word has appear

	while(!feof(out)){
		fscanf(out, "%s %d %s %d", oldword, &oldlife, oldwin, &oldchoicetime);
		if(strcmp(oldword, word) == 0){
			choicetime = oldchoicetime + 1;
			break;
		}
	}
	rewind(out);



		printf("%s",word);
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
			 
		}
		printf("Do you want to player again (y/n)?");
		scanf("%s",playornot);
		if(playornot[0] == 'n'){
			play = 0;
		}
		else{
			choice = 0;
		}
		printf("\n");
		if((out = fopen("hangman-score.txt", "a")) == NULL){
			puts("File could not be opened.");
		}
		if(win == 1){
			fprintf(out, "%s %d %s %d\n",word,life, "win", choicetime);
		}
		else{
			fprintf(out, "%s %d %s %d\n",word,life, "failed",choicetime);
		}
		win = 0;
		life = 5;

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
