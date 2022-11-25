#include"game.h"
void chushihua(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			qipan[i][j] = ' ';
		}
	}
}

void dayin( char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
			    {
				   printf("|");
			    }
			}
			printf("\n");
		}
	}
}


void playmove(char qipan[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入坐标\n");
	while (1)
	{
		scanf("%d %d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*'; 
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}


void computermove(char qipan[ROW][COL], int row, int col)
{
	printf("电脑下\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = '#';
			break;
		}
	}
}


int full(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < col; i++)
	{
		for (i = 0; i < row; i++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;
			}
			
		}
	}
    return 1;
}
char panduan(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][1] != ' ')
			return qipan[i][1];
	}
	for (i = 0; i < col; i++)
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[1][i] != ' ')
			return qipan[1][i];
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[1][1] != ' ')
	{
		return qipan[1][1];
	}
	int ret = full(qipan, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'c';
	

}