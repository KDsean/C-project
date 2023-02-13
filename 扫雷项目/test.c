#include"game.h"


void menu()
{
	printf("--------------------------------\n");
	printf("-------------扫雷游戏-----------\n");
	printf("----1.play--------------2.exit--\n");
	printf("--------------------------------\n");
}



void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	chushihua(mine, ROWS, COLS, '0');
	chushihua(show, ROWS, COLS, '*');

	
	dayin(show, ROW, COL);

	buzhi(mine, ROW, COL);
	//dayin(mine, ROW, COL);

	paica(mine, show, ROW, COL);
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;

		}

	} while (input);
		return 0;
}