#include <iostream>
#include <conio.h>
#include <windows.h>
#include <easyx.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <graphics.h>
using namespace std;
void cdxz() 
{
	Sleep(2500);
	initgraph(1000, 600, EX_SHOWCONSOLE);
	IMAGE po, po1;
	loadimage(&po, L"003.jpg");
	loadimage(&po1, L"004.jpg");
	putimage(0, 0, &po);
	settextcolor(RGB(0, 0, 0));
	HWND HB= GetHWnd();
	int opx = -200;
	int r = 0;
	while (true)
	{
		while (true)
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x < 200 && opx < 0)
			{
				r = 1;
			}
			else if (msg.x > 200 && opx > -200)
			{
				r = 2;
			}
			if (r == 1 && opx < 0)
			{
				opx=opx+10;
			}
			if (r == 2 && opx > -200)
			{
				opx=opx-10;
			}
			cout << msg.x << " " << msg.y << endl;
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &po);
			putimage(opx, 0, &po1);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(0, 0, 0));
			settextstyle(50, 20, L"华文琥珀");
			outtextxy(opx, 100, L"文档查询");
			EndBatchDraw();
			cout << r << endl;
			switch(msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if(msg.x < opx + 178 && msg.y>100 && msg.y < 150)
				{
					cout << "yes" << endl;
					MessageBox(HB, L"暂时无文档", L"提示",MB_OKCANCEL);
				}
				break;
			}
		}
	}
}
int main(){
	int c;
	initgraph(600, 300);
	HWND jk = GetHWnd();
	SetWindowText(jk, L"Pwnguin_King");
	IMAGE loding, tk2, tk1;
	loadimage(&loding, L"000.jpg");
	loadimage(&tk2, L"001.jpg");
	loadimage(&tk1, L"002.jpg");
	for (int i = 0; i < 600; i++)
	{
		Sleep(10);
		cleardevice();
		BeginBatchDraw();
		putimage(236, 86, &tk2);
		putimage(i - 600, 250, &loding);
		EndBatchDraw();
	}
	settextcolor(RGB(255, 255, 255));
	settextstyle(50, 0, L"");
	outtextxy(0, 0, L"Pr_KI");
	Sleep(1000);
	closegraph();
	cdxz();
	return 0;
}