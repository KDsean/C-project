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
      //�������
	   playmove(qipan, ROW, COL);
	   dayin(qipan, ROW, COL);
	  //�ж������Ӯ
	   ret = panduan(qipan, ROW, COL);
	   if (ret != 'c')
		   break;
	  //��������
	   computermove(qipan, ROW, COL);
	   dayin(qipan, ROW, COL);
	   //�жϵ�����Ӯ
	   ret = panduan(qipan, ROW, COL);
	   if(ret != 'c')
		   break;
     }
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("������>");
		scanf("%d", &shuru);
		switch(shuru)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		case 3:
			printf("�����������������\n");
			break;
		}

	} while (shuru);
	return 0;

}