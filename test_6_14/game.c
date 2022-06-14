# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��ʼ������
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//��ӡ����
		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|"); 
		}
		printf("\n");
		//��ӡ�ָ���Ϣ
		//printf("---|---|---\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������������꣺>");
		scanf("%d %d", &x, &y);
		//���귶Χ�Ϸ��Ե��ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������λ�ã�");
			}
		}
		else
		{
			printf("��������Ƿ� �����������룡");
		}
	}

}
//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�������壺>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;//0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//���ˣ�ƽ�֣�����1
//û��       ����0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;

}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж���
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1]!= ' ')
		{
			return board[i][1];
		}
	}
	//�ж���
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') 
	{
		return board[1][1];
	}
	if (board[3][1] == board[1][1] && board[1][1] == board[1][3] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�������ߵ��������û����Ӯ���ж��Ƿ�ƽ��
	if (IsFull(board, row, col))
	{
		return 'Q';
	}

	//�������ߵ��������û��Ӯ��û��ƽ�֣���Ϸ����
	return 'C';
}