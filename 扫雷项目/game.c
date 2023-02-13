#include"game.h"



void chushihua(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void dayin(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");//��ӡ������֮����
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void buzhi(char mine[ROWS][COLS], int row, int col)
{
	int count = MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}



 static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x][y - 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] - 8 * '0';
}

void biaoji(char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int z = 0;
	while (z<1)
	{
		printf("PS;��ʱ���˳������롰0 0��\n");
		printf("��������Ҫ��ǵ�����\n");
		scanf("%d %d", &y, &x);
		if (x == 0 && y == 0)
		{
			printf("�˳����\n");
			break;
		}
		else if (show[x][y] == '*')
		{
			show[x][y] = '$';
			break;
		}
		else
		{
			printf("��������Ѿ�����ǹ���\n");
			printf("�����������0���˳��������1:>\n");
			scanf("%d", &z);
		}
	}
	
}


void digui(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* p)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		int sum = get_mine_count(mine, x, y);
		int i = 0;
		int j = 0;
		if (sum == 0)
		{
			(*p)++;
			show[x][y] = ' ';
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')
					{
						digui(mine, show, i, j, p);
					}
				}
			}
		}
		else
		{
			(*p)++;
			show[x][y] = sum + '0';
		}
	}
}

void paica(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int a = 0;
	int* p = &win;
	while (win < row * col - MINE)
	{
		printf("��������Ҫ�Ų������:>\n");
		scanf("%d%d", &y, &x);
		if (x >= 1 && x <= row && y>=1 && y <= col)
		{
			if (show[x][y] == '*' || show[x][y] == '$')
			{
				if (mine[x][y] == '1')
				{
					printf("���ź���������\n");
					dayin(mine, ROW, COL);
					printf("\n");
					break;
				}
				else
				{
					digui(mine, show, x, y, p);
					dayin(show, ROW, COL);
					printf("\n");
					printf("�Ƿ���б��? 1.yes    0.no\n");
					scanf("%d", &a);
					if (a == 1)
					{
						biaoji(show);
						printf("\n");
						dayin(show, ROW, COL);
					}
				}
			}
			else
			{
				printf("��������Ѿ����Ų���ˣ�����������\n");
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - MINE)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		dayin(mine, ROW, COL);
		printf("\n");
		return 0;
	}
}
