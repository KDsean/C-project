#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("************************************\n");
	printf("****    1.play     0.exit       ****\n");
	printf("************************************\n");
}

void game()
{
	//1.生成随机数
	int ret = 0;
	int guess = 0;//接收猜的数字
	//拿时间戳来设置随机数的生成起始点
	//time_t time(time_t*timer)//time_t函数，返回time(time_t*timer)
	//通过定义发现time_t是长整型，所以下面强制定义长整型
	//srand((unsigned int)time(NULL));移到下面，在上面会出现玩一次游戏设置一次，造成随机数相近//设置一个随机起点时间戳(调用rand之前的必须步骤，设置起点）//NULL空指针
	ret = rand()%100+1;//生成1—100随机数%100+1(%100是0—99）
	//2.猜数字
	while (1)\
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}

}
int main()
{
	int intput = 0;
	srand((unsigned int)time(NULL));
	do//程序至少进行一次
	{
		menu();
		printf("请选择:>");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
				game();//进入游戏
		     break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (intput);
	return 0;
}