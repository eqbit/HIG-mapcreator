#include "windmill.h"
#include <time.h>
#include <MMSystem.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include <string>
using std::vector;
#include <math.h>
#pragma comment (lib, "windmill.lib")
#pragma comment (lib,"winmm.lib")

#include "types.h"



const int width=500, height=90;
const int blockSide=20, drawCoef=100;
bool mscheck=0,keyp=false;
bool blocks=true, mobs=false, objects=false, finish=false;
bool allowCreate=true;

wchar_t *massIMG,*addAnywayIMG;

bool addAnyway=false;
bool addMass=false;

unsigned long buttonClick;

int curType=1;

int mouseX=0, mouseY=0;
int mouse0X=0,mouse0Y=0;

int savedTime=0;



void StartInterface();
bool cross(int x_hero, int y_hero, int h_hero, int w_hero, int x_obj, int y_obj,  int h_obj, int w_obj);
void btnCkck(wchar_t *sound);
bool DrawButton(int _x, int _y, int _wt, int _ht, wchar_t *_pic, wchar_t * a_pic,int lay);
bool DrawButton(int _x, int _y, int _wt, int _ht, wchar_t *_pic, wchar_t * a_pic,int lay, wchar_t *lbl);
void Label(int x, int y, wchar_t *label);
int RandInt(int min,int max);
void game();
void Interface();
void CheckKeys();
void ShowItem();
bool DrawButtonNum(int num, int x, int y);
bool DrawButtonWord(wchar_t *word, int x, int y, int length);
void ShowWord(wchar_t* word, int &var, int x, int y);


int time1=timeGetTime(),time2=timeGetTime();
void GameTimer();
int tm0=timeGetTime(),tm1=timeGetTime();
int tD();
wchar_t *RType(int _type);
bool m_menu=true; bool first_menu=true; bool second_menu=false;


doubleInt LastBlock();
int FindLastX(int x, int y);
int FindLastY(int x, int y);

#include "cad.h"
#include "world.h"
#include "objects.h"


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	int windowW=800, windowH=600;
	IniEngine(L"DR_STORY_MAP_REDACTOR",windowW,windowH,false,COLOR(255,8,162,255));
	TextGen(L"Tahoma",32);
	SetWindowLong(GetForegroundWindow(),GWL_STYLE,GetWindowLong(GetForegroundWindow(),GWL_STYLE)^WS_THICKFRAME^WS_MAXIMIZEBOX);

	world=new _world;
	camera = new _camera();
	label = new _label;

	RunEngine(game);

	delete world;
	delete camera;
	delete label;

	return 0;
}

void game()
{
	if(KeyCheck(DIK_ESCAPE))
		exit(1);

    mouseX=GetWorldX()-100;
	mouseY=GetWorldY()-100;
	mouse0X=GetMouseX();
	mouse0Y=GetMouseY();

	time1=timeGetTime();

	if(m_menu)
	{
		Interface();
	}
	else
	{
	    
		
	    Interface();

	    camera->Draw();
		
		label->Draw();

		ShowWord(L"Saved",savedTime,600,50);



	    //DevelopHelp(1);
	   

    }

	ShowItem();
	GameTimer();

	
	CheckKeys();
}



#include "funcs.h"
#include "interface.h"