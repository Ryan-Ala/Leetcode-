/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/

#include<iostream>
int main()
{
	for (int A = 1; A < 6; A++)
		for (int B = 1; B < 6; B++)
			for (int C = 1; C < 6; C++)
				for (int D = 1; D < 6; D++)
					for (int E = 1; E < 6; E++)
						if (A == B || A == C || A == D || A == E || B == C || B == D || B == E || C == D || C == E || D == E)
							continue;
						else
						{
							int a = (B == 2) + (A == 3), b = (B == 2) + (E == 4), c = (C == 1) + (D == 2), d = (C == 5) + (D == 3), e = (E == 4) + (A == 1);
							if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1)
							{
								printf("A排名为%d，B排名为%d，C排名为%d,D排名为%d,E排名为%d",A, B, C, D, E);
							}
						}
}