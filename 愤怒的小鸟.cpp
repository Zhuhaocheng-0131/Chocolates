#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;
const double pi = 3.1415926536;
int toint (float a) {
	return ((int) (a * 10 + 5)) / 10;
}
 
void Color (int a) {
 
	if (a == 0 || a == 14 || a == 20) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
 
	} else if (a == 1 || a == 12) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
 
	} else if (a == 2) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_GREEN);
 
	} else if (a == 3) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
 
	} else if (a == 4 || a == 11) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_RED);
 
	} else if (a == 5 || a == 13) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
 
	} else if (a == 7) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_GREEN | FOREGROUND_BLUE);
 
	} else if (a == 15) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
 
	} else if (a == 16) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
 
	} else if (a == 17) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), FOREGROUND_RED);
 
	} else if (a == 8) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
 
	} else if (a == 6) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_BLUE);
 
	} else if (a == 9) {
 
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
 
		                         FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
 
	}
 
}
 
void SetPos (float x, float y) {
 
	int xx = toint (x), yy = toint (y);
 
	COORD pos;
 
	pos.X = yy * 2;
 
	pos.Y = xx;
 
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
 
}
 
struct node {
 
	int W, W2, S, mS;
 
	float X, Y;
 
	float vx, vy;
 
	float ax, ay;
 
	bool go, boom;
 
} blt[100001], pig[100001], boo[100001];
 
int T, yX, yY, Xy, put, K, K2, Sle, What;
 
int Bot, Pit, Blt, Pig, Sco, pigk, scok;
 
int m[41][41];
 
void Cout (int a, int x, int y) {
 
	if (a == 1) {
 
		SetPos (x, y);
 
		Color (5);
 
		cout << put << ' ';
 
	}
 
	if (y == 202) {
 
		SetPos (pig[a].X, pig[a].Y);
 
		cout << "  ";
 
		if ((pig[a].W == 2 || pig[a].W == 3) && pig[a].X >= 2) {
 
			SetPos (pig[a].X - 2, pig[a].Y);
 
			cout << "  ";
 
			SetPos (pig[a].X - 1, pig[a].Y);
 
			cout << "  ";
 
		} else if (pig[a].W == 4) {
 
			SetPos (pig[a].X, pig[a].Y - 1);
 
			cout << "  ";
 
		} else if (pig[a].W == 5) {
 
			SetPos (pig[a].X - 1, pig[a].Y);
 
			cout << "  ";
 
			SetPos (pig[a].X - 1, pig[a].Y - 1);
 
			cout << "  ";
 
		}
 
	}
 
	if (a == 2) {
 
		for (int i = 0; i <= 40; i++) {
 
			for (int j = 0; j <= 40; j++) {
 
				if (i <= 18 && m[i][j] == 1) {
 
					SetPos (i, j);
 
					Color (7);
 
					cout << "■";
 
				}
 
				if (m[i][j] >= 2 && m[i][j] <= 19) {
 
					SetPos (i, j);
 
					Color (5);
 
					cout << "█";
 
					m[i][j]++;
 
				}
 
				if (m[i][j] > 19 && m[i][j] <= 29) {
 
					SetPos (i, j);
 
					Color (0);
 
					cout << "█";
 
					m[i][j]++;
 
					if (m[i][j] == 30) {
 
						SetPos (i, j);
 
						Color (0);
 
						cout << "  ";
 
						m[i][j] = 0;
 
					}
 
					if (m[i][j] >= 31 && m[i][j] <= 49) {
 
						SetPos (i, j);
 
						Color (0);
 
						cout << "■";
 
						m[i][j]++;
 
					}
 
					if (m[i][j] == 50) {
 
						SetPos (i, j);
 
						Color (7);
 
						cout << "■";
 
						m[i][j] = 1;
 
					}
 
				}
 
			}
 
		}
 
	}
 
	if (y == 666) {
 
		SetPos (blt[a].X, blt[a].Y);
 
		Color (10 + blt[a].W);
 
		cout << "●";
 
	}
 
	Color (0);
 
}
 
void Go (int a) {
 
	SetPos (blt[a].X, blt[a].Y);
 
	cout << "  ";
 
	blt[a].X += blt[a].vx / 2;
 
	blt[a].Y += blt[a].vy / 2;
 
	blt[a].vx += blt[a].ax / 2;
 
	blt[a].vy += blt[a].ay / 2;
 
	if (blt[a].X >= 20) {
 
		blt[a].X = 19;
 
	}
 
	if (blt[a].X > 20 || blt[a].Y > 38 || blt[a].X < 0 || blt[a].Y <= 0) {
 
		blt[a].go = 1;
 
	}
 
	if (blt[a].W2 == 1 && blt[a].Y >= Xy) {
 
		blt[a].go = 1;
 
		Sle = 0;//地跑鸟
 
	}
 
	if (blt[a].W2 == 0) {
 
		for (int i = 0; i <= blt[a].vx / 2 + 1; i++) {
 
			if (blt[a].vx > 0 && m[toint (blt[a].X) + i][toint (blt[a].Y)] == 1) {
 
				if (blt[a].W != 5) {
 
					blt[a].boom = 1;
 
				}
 
				blt[a].X = toint (blt[a].X) + i - 1;
 
				blt[a].Y += blt[a].vy / 2;
 
				blt[a].vx = -blt[a].vx * 0.4;
 
				blt[a].vy = blt[a].vy * 0.8;
 
				if (blt[a].W == 3) {
 
					blt[a].ax = 0.5;
 
				}
 
				if (blt[a].W == 7) {
 
					blt[a].vx *= 2;
 
				}
 
				if (blt[a].W == 10) {
 
					blt[a].go = 1;
 
					Bot++;
 
					boo[Bot].X = blt[a].X;
 
					boo[Bot].Y = blt[a].Y;
 
					boo[Bot].S = 1;
 
					boo[Bot].mS = 4;
 
				}
 
			}
 
			if (blt[a].vx < 0 && m[toint (blt[a].X) - i][toint(blt[a].Y)] == 1) {
 
				if (blt[a].W != 5) {
 
					blt[a].boom = 1;
 
				}
 
				blt[a].X = toint (blt[a].X) + i + 1;
 
				blt[a].Y += blt[a].vy / 2;
 
				blt[a].vx = -blt[a].vx;
 
				blt[a].vy = blt[a].vy * 0.8;
 
				if (blt[a].W == 3) {
 
					blt[a].ax = 0.5;
 
				}
 
				if (blt[a].W == 7) {
 
					blt[a].vx *= 2;
 
				}
 
				if (blt[a].W == 10) {
 
					blt[a].go = 1;
 
					Bot++;
 
					boo[Bot].X = blt[a].X;
 
					boo[Bot].Y = blt[a].Y;
 
					boo[Bot].S = 1;
 
					boo[Bot].mS = 4;
 
				}
 
			}
 
		}
 
		if (abs (blt[a].vx) <= 0.1 && abs (blt[a].vy) <= 0.1 && abs (blt[a].ay) <= 0.1) {
 
			blt[a].go = 1;
 
			if (blt[a].W == 5) {
 
				Bot++;
 
				boo[Bot].X = blt[a].X;
 
				boo[Bot].Y = blt[a].Y;
 
				boo[Bot].S = 1;
 
				boo[Bot].mS = 4;
 
				blt[a].go = 1;
 
			}
 
		}
 
	}
 
	if (blt[a].go == 0) {
 
		Cout (a, 0, 666);
 
	}
 
}
 
void Kill (int a) {
 
	if (pig[a].go == 0 && pig[a].W != 2 && pig[a].W != 3 && pig[a].Y < 16) {
 
		Cout (a, 202, 202);
 
		pig[a].Y = 16;
 
	}
 
	if (pig[a].go == 0 && pig[a].W == 4 && pig[a].Y < 20) {
 
		pig[a].W = 1;
 
	}
 
	int R = rand () % 50;
 
	Cout (a, 202, 202);
 
	//清除猪猪
 
	pig[a].X += pig[a].vx / 2;
 
	pig[a].Y += pig[a].vy / 2;
 
	pig[a].vx += pig[a].ax / 2;
 
	pig[a].vy += pig[a].ay / 2;
 
	for (int i = -2; i <= pig[a].vx / 2 + 1; i++) {
 
		if (m[toint (pig[a].X) + i][toint (pig[a].Y)] == 1) {
 
			pig[a].X = toint (pig[a].X) + i - 1;
 
			pig[a].Y += pig[a].vy / 2;
 
			pig[a].vx = -pig[a].vx * 0.5;
 
			pig[a].vy = pig[a].vy * 0.8;
 
		}
 
	}
 
	for (int i = Blt - 10; i <= Blt; i++) {
 
		if (pig[a].W == 5 && blt[i].go == 0 && abs (pig[a].X - blt[i].X) <= 1
 
		    && abs (pig[a].Y - blt[i].Y) <= 1) {
 
			m[toint (pig[a].X) - 1][toint (pig[a].Y)] = 2;
 
			pig[a].W2++;
 
			Sco += 2;
 
			break;
 
		}
 
		if (pig[a].W == 5 && m[toint (pig[a].X)][toint (pig[a].Y)] >= 2 &&
 
		    m[toint (pig[a].X)][toint (pig[a].Y)] < 30) {
 
			m[toint (pig[a].X) - 1][toint (pig[a].Y)] = 2;
 
			pig[a].W2++;
 
			Sco += 2;
 
			break;
 
		}
 
		if (blt[i].go == 0 && abs (pig[a].X - blt[i].X) <= 1 && abs (pig[a].Y - blt[i].Y) <= 1) {
 
			if (pig[a].W == 6) {
 
				Bot++;
 
				boo[Bot].X = pig[a].X;
 
				boo[Bot].Y = pig[a].Y;
 
				boo[Bot].S = 1;
 
				boo[Bot].mS = 4;
 
				blt[i].go = 1;
 
			}
 
			m[toint (pig[a].X)][toint (pig[a].Y)] = 2;
 
			pig[a].go = 1;
 
			Pig--;
 
			Sco += 10;
 
			break;
 
		}
 
		if (m[toint (pig[a].X)][toint (pig[a].Y)] >= 2 &&
 
		    m[toint (pig[a].X)][toint (pig[a].Y)] < 30) {
 
			if (pig[a].W == 6) {
 
				Bot++;
 
				boo[Bot].X = pig[a].X;
 
				boo[Bot].Y = pig[a].Y;
 
				boo[Bot].S = 1;
 
				boo[Bot].mS = 4;
 
			}
 
			pig[a].go = 1;
 
			Pig--;
 
			Sco += 10;
 
			break;
 
		}
 
		if ((pig[a].W == 2 || pig[a].W == 3) && blt[i].go == 0 &&
 
		    abs (pig[a].X - 2 - blt[i].X) <= 1 && abs (pig[a].Y - blt[i].Y) <= 1) {
 
			m[toint (pig[a].X)][toint (pig[a].Y)] = 2;
 
			pig[a].go = 1;
 
			Pig--;
 
			Sco += 10;
 
			break;
 
		}
 
		if ((pig[a].W == 2 || pig[a].W == 3) &&
 
		    m[toint (pig[a].X - 2)][toint (pig[a].Y)] >= 2
 
		    && m[toint (pig[a].X - 2)][toint (pig[a].Y)] < 30) {
 
			pig[a].go = 1;
 
			Pig--;
 
			Sco += 10;
 
			break;
 
		}
 
	}
 
	//弄死猪猪
 
	if (pig[a].go == 0) {
 
		if (pig[a].go == 0 && pig[a].W != 2 && pig[a].W != 3 && pig[a].Y < 16) {
 
			Cout (a, 202, 202);
 
			pig[a].Y = 16;
 
		}
 
		if (pig[a].go == 0 && pig[a].W == 4 && pig[a].Y < 20) {
 
			pig[a].W = 1;
 
		}
 
		int Xx = toint (pig[a].X), Xy = toint (pig[a].Y);
 
		if (pig[a].W == 6) {
 
			SetPos (pig[a].X, pig[a].Y);
 
			Color (9);
 
			cout << "TN";
 
			Color (0);
 
		} else {
 
			SetPos (pig[a].X, pig[a].Y);
 
			Color (2);
 
			cout << "●";
 
			if ((pig[a].W == 2 || pig[a].W == 3) && pig[a].X >= 2) {
 
				SetPos (pig[a].X - 2, pig[a].Y);
 
				Color (0);
 
				cout << "○";
 
				SetPos (pig[a].X - 1, pig[a].Y);
 
				cout << "｜";
 
			} else if (pig[a].W == 4) {
 
				SetPos (pig[a].X, pig[a].Y - 1);
 
				Color (2);
 
				cout << "﹃";
 
			} else if (pig[a].W == 5) {
 
				SetPos (pig[a].X - 1, pig[a].Y);
 
				Color (8);
 
				SetPos (pig[a].X - 1, pig[a].Y - 1);
 
				cout << "▁";
 
				if (pig[a].W2 == 0) {
 
					cout << "▅";
 
				} else if (pig[a].W2 == 1) {
 
					cout << "▃";
 
				} else if (pig[a].W2 == 2) {
 
					cout << "▂";
 
				} else if (pig[a].W2 == 3) {
 
					pig[a].W = 1;
 
					pig[a].W2 = 0;
 
					SetPos (pig[a].X - 1, pig[a].Y - 1);
 
					cout << "  ";
 
				}
 
			}
 
		}
 
		//输出猪猪
 
		if (pig[a].W == 2 && pig[a].X > pig[a].S) {
 
			pig[a].W = 3;
 
			pig[a].ax = -0.4;
 
			pig[a].vx = 1.5;
 
		} else if (pig[a].W == 3 && pig[a].X <= pig[a].S) {
 
			pig[a].W = 2;
 
			pig[a].ax = 0.4;
 
			pig[a].vx = -1.5;
 
		}
 
		if ((pig[a].W == 2 || pig[a].W == 3) && (pig[a].Y <= 10 || pig[a].Y >= 38)) {
 
			pig[a].vy *= -1;
 
		}
 
		if (pig[a].W == 4 && R == 0 && pig[a].X == 20) {
 
			pig[a].vx = -((rand () % 40) / 10);
 
		}
 
		if (pig[a].W == 4) {
 
			int r = rand () % 20;
 
			for (int i = Blt - 10; i <= Blt; i++) {
 
				if (r <= 5 && blt[i].go == 0 && pig[a].Y - blt[i].Y <= 5 &&
 
				    abs (blt[i].X - pig[a].X) <= 1.5 && r < 5) {
 
					r = 0;
 
					break;
 
				}
 
			}
 
			if (r == 0) {
 
				m[toint (pig[a].X)][toint (pig[a].Y) - 2] = 10;
 
				m[toint (pig[a].X)][toint (pig[a].Y) - 3] = 2;
 
				for (int j = toint (pig[a].Y) - 1; j >= toint (pig[a].Y) - 5; j--) {
 
					for (int i = Blt - 10; i <= Blt; i++) {
 
						if (blt[i].go == 0 && !(blt[i].W == 3 && blt[i].boom == 1)
 
						    && blt[i].W2 == 0 && toint (blt[i].Y) == j
 
						    && abs (blt[i].X - pig[a].X) <= 2) {
 
							blt[i].vy = -2;
 
						}
 
					}
 
					for (int i = Pit - 50; i <= Pit; i++) {
 
						if (pig[i].go == 0 && toint (pig[i].Y) == j && abs (pig[i].X - pig[a].X) <= 2) {
 
							pig[i].vy = -1;
 
						}
 
					}
 
				}
 
			}
 
		}
 
		//移动猪猪
 
		if (pig[a].go == 0 && pig[a].W != 2 && pig[a].W != 3 && pig[a].Y < 16) {
 
			Cout (a, 202, 202);
 
			pig[a].Y = 16;
 
		}
 
		if (pig[a].go == 0 && pig[a].W == 4 && pig[a].Y < 20) {
 
			pig[a].W = 1;
 
		}
 
		if (pig[a].X > 20 || pig[a].Y > 38 || pig[a].X < 0 || pig[a].Y <= 0) {
 
			pig[a].go = 1;
 
			Pig--;
 
			Cout (a, 202, 202);
 
		}
 
		//清除猪猪
 
	}
 
}
 
void Creat (int a, int p) {
 
	if (a == -1 && p == -1) {
 
		Blt++;
 
		blt[Blt].W = What;
 
		blt[Blt].W2 = 1;
 
		blt[Blt].vy = 1;
 
		blt[Blt].X = 19;
 
		blt[Blt].Y = 0;
 
		blt[Blt].boom = 1;
 
	} else if (a == 0 && p == -1) {
 
		int u = rand () % 7 + 1, U = rand() % 30;
 
		if (u >= 5) {
 
			Pit++;
 
			pig[Pit].Y = rand () % 15 + 20;
 
			pig[Pit].X = 2;
 
			pig[Pit].ax = 0.5;
 
			pig[Pit].W = 1;
 
		} else if (u == 1) {
 
			Pit++;
 
			pig[Pit].Y = rand () % 15 + 20;
 
			pig[Pit].X = 2;
 
			pig[Pit].vy = 0.5;
 
			pig[Pit].ax = 0.5;
 
			pig[Pit].S = rand () % 5 + 7;
 
			pig[Pit].W = 2;
 
		} else if (u == 2) {
 
			Pit++;
 
			pig[Pit].Y = rand () % 15 + 20;
 
			pig[Pit].X = 2;
 
			pig[Pit].ax = 0.5;
 
			pig[Pit].W = 4;
 
		} else if (u == 3) {
 
			Pit++;
 
			pig[Pit].Y = rand () % 15 + 20;
 
			pig[Pit].X = 2;
 
			pig[Pit].ax = 0.5;
 
			pig[Pit].W = 5;
 
		} else if (u == 4) {
 
			Pit++;
 
			pig[Pit].Y = rand () % 15 + 20;
 
			pig[Pit].X = 2;
 
			pig[Pit].ax = 0.5;
 
			pig[Pit].W = 6;
 
		}
 
		if (U == 1) {
 
			Bot++;
 
			boo[Bot].Y = rand () % 13 + 15;
 
			boo[Bot].X = (rand () % 4) * 3 + 8;
 
			boo[Bot].S = 0;
 
			boo[Bot].mS = rand () % 2 + 2;
 
			boo[Bot].W2 = 1;
 
		}
 
	} else {
 
		Blt++;
 
		blt[Blt].W = What;
 
		if (a == 1) {
 
			blt[Blt].X = yX;
 
			blt[Blt].Y = yY;
 
			blt[Blt].ax = 0.5; //抛物线
 
		}
 
		blt[Blt].vx = -3.5 * sin (p * pi / 180);
 
		blt[Blt].vy = 3 * cos (p * pi / 180);
 
		if (p <= 45) {
 
			blt[Blt].vy *= 1 + (0.33 - 0.01 * (45 - p));
 
		}
 
		if (p >= 45) {
 
			blt[Blt].vy *= 1 + (0.33 - 0.01 * (p - 45));
 
		}
 
		if (blt[Blt].W == 6) {
 
			blt[Blt].vy *= 1.2;
 
			blt[Blt].ax = 0.4;
 
		}
 
	}
 
}
 
void Boom (int a) {
 
	if (boo[a].W2 == 0) {
 
		int ms = boo[a].mS, s = boo[a].S, x = boo[a].X, y = boo[a].Y;
 
		if (s == ms) {
 
			return ;
 
		}
 
		for (int i = x - s; i <= x + s; i++) {
 
			for (int j = y - s; j <= y + s; j++) {
 
				float k = (i - x) * (i - x) + (j - y) * (j - y) - s * s;
 
				if (k <= s && k >= -s && i <= 20 && j <= 38 && i >= 0 && j > 0 && m[i][j] != 1) {
 
					m[i][j] = 2;
 
				}
 
			}
 
		}
 
		boo[a].S++;
 
	}
 
	if (boo[a].W2 == 1) {
 
		int ms = boo[a].mS, s = boo[a].S, x = boo[a].X, y = boo[a].Y;
 
		if (s == ms) {
 
			return ;
 
		}
 
		if (y - s > 10) {
 
			m[x][y - s] = 31 - 31 * (boo[a].W2 - 1);
 
		}
 
		if (y + s < 40) {
 
			m[x][y + s] = 31 - 31 * (boo[a].W2 - 1);
 
		}
 
		boo[a].S++;
 
	}
 
}
 
void Move (int a) {
 
	Color (5);
 
	if (a == -2) {
 
		SetPos (17, Xy);
 
		cout << "        ";
 
		SetPos (18, Xy);
 
		cout << "        ";
 
		SetPos (19, Xy);
 
		cout << "        ";
 
		SetPos (20, Xy);
 
		cout << "       ";
 
	}
 
	if (a == -1) {
 
		SetPos (17, Xy);
 
		cout << "        ";
 
		SetPos (18, Xy);
 
		cout << "  ┃  ┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "     ▏";
 
	}
 
	if (a == 0) {
 
		SetPos (18, Xy);
 
		cout << "  ┃";
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << "┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "     ▏";
 
	}
 
	if (a == 1) {
 
		SetPos (18, Xy);
 
		cout << "  ";
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << "  ┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "     ▏";
 
	}
 
	if (a == 2) {
 
		SetPos (18, Xy);
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << "┃  ┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "     ▏";
 
	}
 
	if (a == 3) {
 
		SetPos (18, Xy);
 
		cout << "  ┃  ┃";
 
		SetPos (19, Xy);
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << "╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "     ▏";
 
	}
 
	if (a == 4) {

		SetPos (18, Xy);
		cout << "  ┃  ┃";
		SetPos (19, Xy);
		cout << "  ╰┳╯";
		SetPos (20, Xy);
		Color (What + 10);
		cout << "●";
		Color (5);
		cout << "   ▏";
	}
	if (a == 5) {
		SetPos (18, Xy);
		cout << "  ┃  ┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "  ";
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << " ▏";
 
	}
 
	if (a == 6) {
 
		SetPos (18, Xy);
 
		cout << "  ┃  ┃";
 
		SetPos (19, Xy);
 
		cout << "  ╰┳╯";
 
		SetPos (20, Xy);
 
		cout << "    ";
 
		Color (What + 10);
 
		cout << "●";
 
		Color (5);
 
		cout << " ";
 
	}
 
	Color (0);
 
}
 
void Start () {
 
	char g;
 
	Color (5);
 
	system ("cls");
 
	SetPos (1, 1);
 
	cout << "------- 愤 怒 的 小 鸟 -------";
 
	Color (0);
 
	SetPos (3, 1);
 
	cout << "空格瞄准,按X触发小鸟技能,←→移动弹弓";
 
	SetPos (5, 1);
 
	cout << "猪猪技能自动触发，空中会有墙出现。";
 
	SetPos (7, 1);
 
	cout << "危险值由命中率，猪的存活时间计算！";
 
	SetPos (9, 1);
  
	cout << "危险值点满后失败！1500分通关！";
 
	SetPos (1, 20);
 
	cout << "-------- 小 鸟 技 能 --------";
 
	SetPos (3, 20);
 
	Color (11);
 
	cout << "●";
 
	Color (0);
 
	cout << "：无技能";
 
	SetPos (5, 20);
 
	Color (12);
 
	cout << "●";
 
	Color (0);
 
	cout << "：分身！不同分身初速度大小相同，";
 
	SetPos(6, 20);
	cout << "        方向不同。";
 
	SetPos (7, 20);
 
	Color (13);
 
	cout << "●";
 
	Color (0);
 
	cout << "：加速！以当前速度做匀速直线运动，";
 
	SetPos (8, 20);
 
	cout << "          且免疫狙击猪的冲击。";
 
	SetPos (9, 20);
 
	Color (14);
 
	cout << "●";
 
	Color (0);
 
	cout << "：投蛋！并获得向上速度做匀速直线";
 
	SetPos (10, 20);
 
	cout << "          运动，快达可以穿墙。";
 
	SetPos (11, 20);
 
	Color (15);
 
	cout << "●";
 
	Color (0);
 
	cout << "：爆炸！";
 
	SetPos (13, 20);
 
	Color (16);
 
	cout << "●";
 
	Color (0);
 
	cout << "：回旋！开始做向左加速运动！发射";
 
	SetPos (14, 20);
 
	cout << "          时获得双倍水平速度。";
 
	SetPos (15, 20);
 
	Color (17);
 
	cout << "●";
 
	Color (0);
 
	cout << "：[被动] 弹跳力为普通鸟三倍。发射";
 
	SetPos (16, 20);
 
	cout << "          时获得1.5倍水平、竖直速度。";
 
	SetPos (11, 1);
 
	cout << "-------- 猪 猪 技 能 --------";
 
	SetPos (13, 2);
 
	Color (2);
 
	cout << "●";
 
	Color (0);
 
	cout << "：无技能";
 
	SetPos (14, 1);
 
	Color (8);
 
	cout << "▁▅";
 
	SetPos (15, 2);
 
	Color (2);
 
	cout << "●";
 
	Color (0);
 
	cout << "：防御力为普通猪三倍";
 
	SetPos (16, 2);
 
	cout << "○";
 
	SetPos (17, 2);
 
	cout << "│：做空中简谐运动，受死范围";
 
	SetPos (18, 2);
 
	Color (2);
 
	cout << "●";
 
	Color (0);
 
	cout << "  为普通猪两倍。";
 
	SetPos (19, 2);
 
	cout << "    有几率跳起或发射冲击波，冲";
 
	SetPos (20, 1);
 
	Color (2);
 
	cout << "﹃●";
 
	Color (0);
	cout << "：开小鸟与同类，可以引爆TNT！";
	SetPos (18, 20);
	Color (5);
	cout << "按 y 开始游戏！";A:
	if (kbhit ())g = _getch ();
	if (g != 'y')goto A;
}
int main () {
	system ("mode con cols=79 lines=22");
 
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 
	SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &cursor_info);
 
	srand ((unsigned)time(NULL));
 
St:
	Start ();
 
	system ("cls");
 
	memset (blt, 0, sizeof (blt));
 
	memset (pig, 0, sizeof (pig));
 
	memset (boo, 0, sizeof (boo));
 
	memset (m, 0, sizeof (m));
 
	T = put = K = K2 = Sle = What = Pig = Sco = 0;
 
	pigk = scok = -1;
 
	Xy = 4;
 
	yX = 18;
 
	yY = 6;
 
	Blt = 20;
 
	Bot = 20;
 
	Pit = 60;
 
	Color (7);
 
	SetPos (19, 14);
 
	cout << "■";
 
	SetPos (20, 13);
 
	cout << " █▍";
 
	m[19][14] = m[20][13] = m[20][14] = 1;
 
	SetPos (21, 0);
 
	for (int i = 0; i < 39; i++) {
 
		cout << "■";
 
		m[21][i] = 1;
 
	}
 
	Color (0);
 
	What = rand () % 5 + 1;
 
	while (1) {
 
		if (Sco >= 1500) {
 
			break;
 
		}
 
		T++;
 
		K = 0;
 
		Color (0);
 
		if (Sco != scok) {
 
			SetPos (1, 1);
 
			cout << "分数：" << Sco << ' ';
 
		}
 
		if (Pig != pigk) {
 
			SetPos (3, 1);
 
			cout << "危险值：";
 
			int aa = min (Sco / 100, 10);
 
			Pig += aa;
 
			SetPos (3, 5);
 
			if (Pig <= 2) {
 
				Color (2);
 
			} else if (Pig <= 4) {
 
				Color (16);
 
			} else if (Pig <= 6) {
 
				Color (7);
 
			} else if (Pig <= 9) {
 
				Color (6);
 
			} else if (Pig <= 12) {
 
				Color (3);
 
			} else if (Pig <= 15) {
 
				Color (17);
 
			} else {
 
				Color (11);
 
			}
 
			for (int i = 1; i <= Pig; i++) {
 
				cout << "■";
 
			}
 
			Color (0);
 
			cout << ' ' << Pig;
 
			for (int i = 1; i <= 5; i++) {
 
				cout << "  ";
 
			}
 
			if (Pig > 18) {
 
				break;
 
			}
 
			Pig -= aa;
 
		}
 
		scok = Sco;
 
		pigk = Pig;
 
		if (GetAsyncKeyState (VK_LEFT) & 0x8000 && Xy > 0) {
 
			Move (-2);
 
			Xy--;
 
			K = 1;
 
		}
 
		if (GetAsyncKeyState (VK_RIGHT) & 0x8000 && Xy < 10) {
 
			Move (-2);
 
			Xy++;
 
			K = 1;
 
		}
 
		if (K == 1) {
 
			if (put == 0 && Sle == 0) {
 
				Move (0);
 
			} else {
 
				Move (-1);
 
			}
 
		}
 
		if (kbhit ()) {
 
			char g = _getch ();
 
			if (g == 'x' || g == 'X') {
 
				for (int i = Blt - 10; i <= Blt; i++) {
 
					if (blt[i].go == 0 && blt[i].boom == 0 && blt[i].W != 1 && blt[i].W != 7) {
 
						blt[i].boom = 1;
 
						if (blt[i].W == 2) {
 
							Blt++;
 
							blt[Blt].W = 2;
 
							blt[Blt].vy = blt[i].vy * 1.2;
 
							blt[Blt].vx = blt[i].vx + 1;
 
							blt[Blt].ax = blt[i].ax;
 
							blt[Blt].X = blt[i].X;
 
							blt[Blt].Y = blt[i].Y;
 
							blt[Blt].boom = 1;
 
							Blt++;
 
							blt[Blt].W = 2;
 
							blt[Blt].vy = blt[i].vy * 0.7;
 
							blt[Blt].vx = blt[i].vx - 1;
 
							blt[Blt].ax = blt[i].ax;
 
							blt[Blt].X = blt[i].X;
 
							blt[Blt].Y = blt[i].Y;
 
							blt[Blt].boom = 1;
 
						}
 
						if (blt[i].W == 3) {
 
							blt[i].vy = fmax (blt[i].vy * 1.5, 2.5);
 
							blt[Blt].vx++;
 
							blt[i].ax = 0;
 
						}
 
						if (blt[i].W == 4) {
 
							blt[i].vx = -3;
 
							blt[i].ax = 0.1;
 
							Blt++;
 
							blt[Blt].boom = 1;
 
							blt[Blt].W = 10;
 
							blt[Blt].X = blt[i].X;
 
							blt[Blt].Y = blt[i].Y;
 
							blt[Blt].ax = blt[i].ax;
 
							blt[Blt].vx = 1;
 
						}
 
						if (blt[i].W == 5) {
 
							Bot++;
 
							boo[Bot].X = blt[i].X;
 
							boo[Bot].Y = blt[i].Y;
 
							boo[Bot].S = 1;
 
							boo[Bot].mS = 5;
 
							blt[i].go = 1;
 
						}
 
						if (blt[i].W == 6) {
 
							blt[i].ay = -1;
 
							blt[i].ax = 0.3;
 
							blt[i].vx = min (blt[i].vx / 2, (float)0);
 
						}
 
						break;
 
					}
 
				}
 
			}
 
		}
 
		if (GetAsyncKeyState (' ') & 0x8000 && K == 0 && Sle == 0) {
 
			if (put <= 5) {
 
				Move (1);
 
				yX = 18;
 
				yY = Xy + 1;
 
			} else if (put <= 20) {
 
				Move (2);
 
				yX = 18;
 
				yY = Xy;
 
			} else if (put <= 40) {
 
				Move (3);
 
				yX = 19;
 
				yY = Xy;
 
			} else if (put <= 60) {
 
				Move (4);
 
				yX = 20;
 
				yY = Xy;
 
			} else if (put <= 80) {
 
				Move (5);
 
				yX = 20;
 
				yY = Xy + 1;
 
			} else {
 
				Move (6);
 
				yX = 20;
 
				yY = Xy + 2;
 
			}
 
			if (put == 0) {
 
				K2 = 1;
 
			}
 
			if (put == 90) {
 
				K2 = -1;
 
			}
 
			if (K2 == 1) {
 
				put += min (rand () % 7 + 1, 90 - put);
 
			}
 
			if (K2 == -1) {
 
				put -= min(rand() % 7 + 1, put);
 
			}
 
			Cout (1, 17, Xy + 2);
 
		}
 
		if ((!(GetAsyncKeyState (' ') & 0x8000) && (put != 0)) || (put != 0 && K == 1)) {
 
			Move (-1);
 
			Creat (1, put);
 
			put = 0;
 
			yX = 18;
 
			yY = 5;
 
			Sle = 1;
 
			What = rand () % 7 + 1;
 
			Creat (-1, -1);
 
			Sco = max (Sco - 5, 0);
 
		}
 
		for (int i = Blt - 10; i <= Blt; i++) {
 
			if (blt[i].go == 0) {
 
				Go (i);
 
			}
		}
		for (int i = Bot - 10; i <= Bot; i++) {
			if (boo[i].go == 0) {
				Boom (i);
				Cout (2, 0, 0);
			}
		}
		for (int i = Pit - 50; i <= Pit; i++) {
			if (pig[i].go == 0) {
				Kill (i);
			}
		}
		if (Sle != 0) {
			Move (-1);
		} else if (put == 0) {
			Move (0);
		}
		if (T % 300 == 0) {
			system ("cls");
			pigk = scok = -1;
		}
		if (T % 100 == 0) {
			Color (7);
			for (int i = 0; i <= 18; i++) {
				for (int j = 0; j <= 40; j++) {
					if (m[i][j] == 1 && T % 100 == 0) {
						SetPos (i, j);
						cout << "■";
					}
				}
			}
			SetPos (19, 14);
			cout << "■";
			SetPos (20, 13);
			cout << " █▍";
			SetPos (21, 0);
			for (int i = 0; i < 39; i++) {
				cout << "■";
				Color (0);
			}
		}
		if (T % min (50, (2000 - Sco) / 30) == 0) {
 
			Pig++;
 
			Creat (0, -1);
 
		}
 
		Sleep (30);
 
	}
 
	if (Sco < 1500) {
 
		if (MessageBox (NULL, "很遗憾，您输了，您还想再来一次吗？", "温馨提示", MB_YESNO) == IDYES) {
 
			goto St;
 
		} else {
 
			return 0;
 
		}
 
	} else {
 
		if (MessageBox (NULL, "恭喜您赢了！您还想再来一次吗？", "温馨提示", MB_YESNO) == IDYES) {
 
			goto St;
 
		} else {
 
			return 0;
 
		}
 
	}
 
	return 0;
 
}
