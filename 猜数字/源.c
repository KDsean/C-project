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
	//1.���������
	int ret = 0;
	int guess = 0;//���ղµ�����
	//��ʱ����������������������ʼ��
	//time_t time(time_t*timer)//time_t����������time(time_t*timer)
	//ͨ�����巢��time_t�ǳ����ͣ���������ǿ�ƶ��峤����
	//srand((unsigned int)time(NULL));�Ƶ����棬������������һ����Ϸ����һ�Σ������������//����һ��������ʱ���(����rand֮ǰ�ı��벽�裬������㣩//NULL��ָ��
	ret = rand()%100+1;//����1��100�����%100+1(%100��0��99��
	//2.������
	while (1)\
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}

}
int main()
{
	int intput = 0;
	srand((unsigned int)time(NULL));
	do//�������ٽ���һ��
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &intput);
		switch (intput)
		{
		case 1:
				game();//������Ϸ
		     break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (intput);
	return 0;
}