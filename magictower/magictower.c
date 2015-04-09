#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void createmap();
void printTheMap(char array[][20]);
void printmonster();
void printtreasure();
int blood = 10,magic = 5,attack = 2,armor = 0,money = 5;
int bloodm = 5,attackm = 1,prize;
int room = 1;
void walk(int control);
void shop();
void createmonster();
void attackmonster();
void createtreasure();
void meettreasure();
void createdoor();
int doora,doorb;
int choiceformonster;
int loosemonster=0;
int choiceforattack;
int choicefortreasure;
int shopdecision;
int treasurerand;
char array[16][20];
int i,j;
int control = 1;
int a,b,sa = 0,sb = 0;
int monsterposition[4][4] = {{0,0},{0,0},{0,0},{0,0}};
int treasureposition[4][4] = {{0,0},{0,0},{0,0},{0,0}};
char name[20];
int main(){
	printf("Hello, my lord. Welcome to magic tower. \nType the name:");
	scanf("%s",name);
	printf("In this game, '@' stands for you. '$' stands for the shop. '!' stands for the monster.'?' stands for treasure(It may exist lucky or disaster).\n\n");
	printf("In the shop you can buy something to improve your blood, magic, attack, and armor.\n");
	printf("When you fight with a monster, you may get some spoils when you win, also you will lose the blood when the monster hit you.\n\n");
	printf("2 is for down,4 is for left,6 is for right,8 is for up,1 for you need new monster,11 for new treasure,0 is for exit\n\n");
	printf("Now the game starts, and enjoy your adventure.\n\n\n");
	srand((int)time(NULL));
	createmap();
	printTheMap(array);
	while(control != 0){
		scanf("%d",&control);
		if(control != 0){
			walk(control);
			printTheMap(array);
			if(control == 1){
				createmonster();
			}
			if(control == 11){
				createtreasure();
			}
			if(a == sa && b ==sb){
				shop();
				printTheMap(array);
			}
			for(i = 0; i<4;i++){
				if(monsterposition[i][0] == a && monsterposition[i][1] == b){
					attackmonster();
					if(loosemonster==1){
						array[monsterposition[i][0]][monsterposition[i][1]] = '!';
					}
					printTheMap(array);
				}
			}
			for(i = 0; i<4;i++){
				if(treasureposition[i][0] == a && treasureposition[i][1] == b){
					meettreasure();
					getchar();
					printTheMap(array);

				}
							}
			if(a == doora && b == doorb){
				createmap();
				room += 1;
				printTheMap(array);
			}
			array[sa][sb] = '$';
		}
		if(magic == 0 && money ==0){
			printf("You have no money and magic, so you cannot attack the monster.\n\nGame Over!\n");
			control = 0;
		}
	}	
}
void createmap(){
	a = rand()% 14 + 1;
	b = rand()% 18 + 1;
	sa = rand()% 14 + 1;
	sb = rand()% 18 + 1;
	while (sa == a || sb == b){
		sa = rand()% 14 + 1;
		sb = rand()% 18 + 1;
	} 
	for(j = 1;j < 15;j++){
		for(i = 0; i < 20; i++){
			array[0][i] = '#';
			array[15][i] = '#';
			if(i == 0 || i == 19){
				array[j][i] = '#';
			}
			else{
				array[j][i] = '.';
			}
		}
	}
	
	array[a][b] = '@';
	array[sa][sb] = '$';
	createmonster();
	createtreasure();
	createdoor();
	
}
void printTheMap(char array[][20]){
	int j,i;
	printf("Hello,%s.Now, your blood is %d,magic is %d,attack is %d,armor is %d,money is %d.\nThis is Floor %d\n\n",name,blood,magic,attack,armor,money,room);
	for(j = 0;j < 16;j++){
			for(i = 0; i < 20;i++){
				printf("%c",array[j][i]);
			}
			printf("\n");
		}

}
void walk(int control){
		if(control == 8){
			if(array[a-1][b] != '#'){
			array[a][b] = '.';
			array[a-1][b] = '@';
			a = a-1;
			}
			else{
				printf("Invalid move!\n");
			}

		}
		if(control == 2){
			if(array[a+1][b] != '#'){
			array[a][b] = '.';
			array[a+1][b] = '@';
			a = a+1;
			}
			else{
				printf("Invalid move!\n");
			}
		}
		if(control == 4){
			if(array[a][b-1] != '#'){
			array[a][b] = '.';
			array[a][b-1] = '@';
			b = b-1;}
			else{
				printf("Invalid move!\n");
			}

		}
		if(control == 6){
			if(array[a][b+1] != '#'){
			array[a][b] = '.';
			array[a][b+1] = '@';
			b = b+1;}
			else{
				printf("Invalid move!\n");
			}

		}

}
void shop(){
	printf("Welcome to shop,select some thing to buy.0 for exit.\n1. blood recover----2 dollar\nimprove total blood 2\n2.magic recover----2 dollar\nimprove magic 2\n3.attack improve----5 dollar \nimprove attack 1\n4.armor improve----6 dollar\nimprove armor 1\nYour choose:");
	scanf("%d",&shopdecision);
	switch(shopdecision){
		case 1:money -= 2; blood += 2;printf("Now your blood is %d, and your money is %d\n",blood,money);break;
		case 2:money -= 2; magic += 2;printf("Now your magic is %d ,and your money is %d\n",magic,money);break;
		case 3:money -= 5; attack +=1;printf("Now your attack is %d, and your money is %d\n",attack,money);break;
		case 4:money -= 6; armor += 1;printf("Now your armor is %d, and your money is %d\n",armor,money);break;
	}
	printf("Thanks for visting shop \n\n\n");
}
void createmonster(){
	for(i = 0;i < 4;i++){
		monsterposition[i][0] = rand()% 14 + 1;
		monsterposition[i][1] = rand()% 18 + 1;
		while((monsterposition[i][0] == a && monsterposition[i][1] == b) || (monsterposition[i][0] == sa && monsterposition[i][1] == sb)){
			monsterposition[i][0] = rand()% 14 + 1;
			monsterposition[i][1] = rand()% 18 + 1;
		}
		array[monsterposition[i][0]][monsterposition[i][1]] = '!';	
	}
}
void attackmonster(){
	printf("Now you meet a monster, do you want to attack or escape?\n 1.Attack\n 2.escape\n");
	scanf("%d",&choiceformonster);
	if(choiceformonster == 1){
		printf("Hey! Brave guy, show me you power!!\n");
		printmonster();
		bloodm = rand()%8 + 3;
		attackm = rand()%3 + 1;
		while(blood > 0 && bloodm > 0){
			printf("This monster's attribute is blood----%d,attack----%d.\n",bloodm,attackm);
			printf("1.Attack (Use two magic, attack is%d)\n2.vampire(use 1 magic, you will increase one blood and the monster will lose 1 blood.)\n",attack);
			printf("3.Powerful attack(use 5 money,monster loses 10 blood)\n");
			scanf("%d",&choiceforattack);
			if(choiceforattack == 1){
				bloodm -= attack;
				magic -= 2;
				printf(" =͟͟͞͞(๑•̀=͟͟͞͞(๑•̀д•́=͟͟͞͞(๑•̀д•́๑)=͟͟͞͞(๑•̀д•́ ٩\n");
				printf("Now,the monster's blood is %d\n\n", bloodm);
			}
			else if(choiceforattack == 2){
				bloodm -= 1;
				blood += 1;
				printf("ᕙ(⇀‸↼‵‵)ᕗ\n");
				printf("Now,the monster's blood is %d\nYour blood is %d.\n\n", bloodm,blood);
			}
			else if(choiceforattack == 3){
				if(money >4){
					money -= 5;
					bloodm -= 10;
					printf("(=ﾟДﾟ=) ▄︻┻┳━ ·.`.`.`.  biubiubiu\n");
					printf("Now,the monster's blood is %d\n\n",bloodm);
				}
			}
			
			if(bloodm > 0){
				printf("Now the monster attack you !!\n─=≡Σ((( つ•̀ω•́)つ\n");
				blood = blood - attackm + armor;
				printf("Press enter to continue~\n");
				getchar();
				printf("Now, your blood is %d,magic is %d\n",blood,magic);
			}
			if(blood < 0 || blood == 0){
				control = 0;
			}
			if(bloodm == 0 || bloodm < 0){
				prize = rand()%5;
				money += prize;
				choiceformonster = 2;
				printf("You win!!\n Find %d money on the monster!\nNow,you have %d money.\n",prize,money);
				printf("_(:зゝ∠)__(:зゝ∠)__(:зゝ∠)__(:зゝ∠)__(:зゝ∠)__(:зゝ∠)__(:зゝ∠)_\n\n");
				printf("Press enter");
				getchar();
			}
			if(magic < 1 && money < 1){
				printf("No magic and money......Try to meet a treasure if you have chance.");
				choiceformonster = 2;
				loosemonster = 1;
			}
		}

	}
}
void printmonster(){
	printf("#####################\n#  @@     #     @@  #\n#  @@     #     @@  #\n#  @@     #     @@  #\n#####################\n");
	printf("    ##         ##\n   # #         # #\n  #  #         #  #\n #   #         #   #\n     #         #\n     #         #\n     ###########\n");
	printf("        #   #\n       #     #\n      #       #\n     #         #\n");
}
void printtreasure(){
	printf("        $\n      $$$$$\n   $$$  $\n$$$     $\n$$$     $\n$$$     $\n   $$$  $\n");
	printf("      $$$$\n        $  $$\n        $    $$$\n        $    $$$\n        $    $$$\n");
	printf("        $ $$$\n       $$$\n  $$$$  $\n        $\n");

}

void createtreasure(){
	for(i = 0;i < 4;i++){
		treasureposition[i][0] = rand()% 14 + 1;
		treasureposition[i][1] = rand()% 18 + 1;
		while((treasureposition[i][0] == a && treasureposition[i][1] == b) || (treasureposition[i][0] == sa && treasureposition[i][1] == sb)){
			treasureposition[i][0] = rand()% 14 + 1;
			treasureposition[i][1] = rand()% 18 + 1;
		}
		array[treasureposition[i][0]][treasureposition[i][1]] = '?';	
	}
}
void meettreasure(){
	printf("You meet a '?' treasure, do you want to open it? \n1.Yes\n2.No\n");
	printtreasure();
	scanf("%d",&choicefortreasure);
	if(choicefortreasure == 1){
		treasurerand = rand()%4;
		switch(treasurerand){
			case 0: blood += 3; printf("You got a blood treasure,improve blood 3 points.Now your blood is %d\n\n",blood);break;
			case 1: blood -= 5; printf("AAAAAAAAAAH!You lose 5 blood!Now your blood is %d\n\n",blood);break;
			case 2: money += 5; printf("You got a money treasure, improve 5 money.Now, you money is %d.\n\n",money);break;
			case 3: money -= 7; printf("AAAAAAAAAAH! You lose 7 money.Now your money is %d.\n\n",money);break;
		}
	}
}
void createdoor(){
	doora = rand()%14+1;
	doorb = rand()%18+1;
	array[doora][doorb] = '0';
}
