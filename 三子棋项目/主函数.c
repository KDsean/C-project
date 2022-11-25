#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("     1.play         2.exit    \n");
	printf("******************************\n");
}

void game()
{
	char qipan[ROW][COL];

	chushihua(qipan, ROW, COL);

	dayin(qipan, ROW, COL);
	char ret = 0;
	while (1)
	{
      //玩家下棋
	   playmove(qipan, ROW, COL);
	   dayin(qipan, ROW, COL);
	  //判断玩家输赢
	   ret = panduan(qipan, ROW, COL);
	   if (ret != 'c')
		   break;
	  //电脑下棋
	   computermove(qipan, ROW, COL);
	   dayin(qipan, ROW, COL);
	   //判断电脑输赢
	   ret = panduan(qipan, ROW, COL);
	   if(ret != 'c')
		   break;
     }
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	dayin(qipan, ROW, COL);
}

int main()
{
	int shuru = 0;

	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入>");
		scanf("%d", &shuru);
		switch(shuru)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		case 3:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (shuru);
	return 0;

}