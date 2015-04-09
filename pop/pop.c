#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "conio.h"
void initial();
void printmap();
void button();
void move();
int findmax();
void nextchange();

char map[10][10];
char point[5] = {'a', 'b', 'c', 'd', 'e'};
char press;
int score = 0;
int line = 1;
int position = 5;
int variety;
int respose[3] = {-1, 1, 0};
int resposea;
int linenumber[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int life = 1;
int step = 1;

int main(){
	initial();
	printmap();
	while(life == 1){
		button();
		move();
		if(step == 6){
			nextchange();
			step = 1;
		}
		printmap();
	}
	printf("You die QAQ\n");
}

void initial(){
	int i,j;
	int random;
	printf("The pop above is your enemy, you need to eliminate them.\n");
	printf("a for left, d for right, o for eliminating action.\n\n");
	printf("Press enter to start the game.\n");
	getchar();
	srand((unsigned)time(NULL));
	for(i = 0; i < 10; i++){
		random = rand()%5;
		map[0][i] = point[random];
	}
	variety = rand()%5;
	for(i = 0; i < 10; i++){
		map[9][i] = ' ';
	}
	map[9][5] = point[variety];
}
void button(){
	press = getch();
		switch(press){
			case 97:resposea = respose[0];break;			     //left
			case 100:resposea = respose[1];break;				 //right
			case 111:resposea = respose[2];break;				 //dapao
		}
		step++;
}
void move(){
	int i;
	map[9][position] = ' ';
	if(resposea == -1 || resposea == 1){
		position = position + resposea;
		map[9][position] = point[variety];
	}
	else{
		if(map[linenumber[position] - 1][position] == point[variety]){
			map[linenumber[position] - 1][position] = ' ';
			variety = rand()%5;
			map[9][position] = ' ';
			map[9][5] = point[variety];
			linenumber[position] = linenumber[position] - 1;
			score++;
		}
		else{
			for(i = 0; i < 10; i++){
				if(map[linenumber[position]][i] != 'a' && map[linenumber[position]][i] != 'b' && map[linenumber[position]][i] != 'c' && map[linenumber[position]][i] != 'd' && map[linenumber[position]][i] != 'e'){
					map[linenumber[position]][i] = ' ';
				}
			}
			map[linenumber[position]][position] = point[variety];
			linenumber[position] = linenumber[position] + 1;
			if(linenumber[position] == 10){
				life = 0;
			}
			map[9][position] = ' ';
			variety = rand()%5;
			map[9][5] = point[variety];
		}
		position = 5;
	}
}
void printmap(){
	int i,j;
	system("clear");
	printf("Your score is %d\n", score);
	line = findmax();
	for(i = 0; i < line; i++){
		for(j = 0; j < 10; j++){
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < 10 - line; i++){
		printf("\n");
	}
	for(i = 0; i < 10; i++){
		printf("%c ", map[9][i]);
	}
	printf("\n");
}

int findmax(){
	int max = 1, i;
	for(i = 0; i < 10; i++){
		if(linenumber[i] > max){
			max = linenumber[i];
		}
	}
	return max;
}
void nextchange(){
	int i,j,random;
	int changeline;
	changeline = findmax();
	for(i = 0;i < 10; i++){
		linenumber[i] = linenumber[i] + 1;
	}
	for(i = changeline - 1; i > -1; i--){
		for(j = 0; j < 10; j++){
			map[i + 1][j] = map[i][j];
		}
	}
	random = rand()%5;
	for(i = 0; i < 10; i++){
		random = rand()%5;
		map[0][i] = point[random];
	}

}

