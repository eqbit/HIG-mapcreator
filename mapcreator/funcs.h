bool cross(int x_hero, int y_hero, int h_hero, int w_hero, int x_obj, int y_obj,  int h_obj, int w_obj)
{
	if(x_hero+w_hero>x_obj && x_hero<x_obj+w_obj && y_hero<y_obj+h_obj && y_hero +h_hero>y_obj)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void btnClck(wchar_t *sound)
{
	if(!GetSoundState(buttonClick))
	{
		buttonClick=SoundPlayEx(sound);
	}
}

wchar_t *RType(int _type)
{
	switch(_type)
	{
	case 0: return L"";break;
	case 1: return L"mc_dirt.png";break;
	case 2: return L"mc_bricks.png";break;
	case 3: return L"mc_stone.png";break;
	case 4: return L"mc_wood.png";break;
	case 5: return L"mc_borderblock.png";break;
	case 6: return L"mc_bluebacks.png";break;
	case 7: return L"mc_greybacks.png";break;
	case 8: return L"mc_fire.png";break;
	case 9: return L"mc_spikes.png";break;
	case 10: return L"mc_essence.png";break;
	case 11: return L"mc_uper.png"; break;
	case 12: return L"mc_pusher_2.png";break;
	case 13: return L"mc_pusher_1.png";break;
	case 14: return L"mc_marble.png"; break;
	case 15: return L"mc_sand.png"; break;
	case 16: return L"mc_stare.png"; break;
	case 17: return L"mc_stuff.png"; break;
	case 18: return L"mc_grassLevel.png"; break;
	default: return L"mc_stone.png";break;
	}
}

bool DrawButton(int _x, int _y, int _wt, int _ht, wchar_t *_pic, wchar_t * a_pic,int lay)
{

	int x,y;
	if(lay==0)
	{
		x=mouse0X;
	    y=mouse0Y;
	}
	else
	{
		x=mouseX;
		y=mouseY;
	}
	
	if(cross(_x,_y,_ht,_wt,x,y,1,1))
	{
		allowCreate=false;

		DrawSprite(_pic,_x,_y,lay);

		if(MouseLBPress()&&!mscheck)
		{
		    mscheck=true;
		    btnClck(L"buttonClick.wav");
		    return true;
		}
	}
	else
	{
		DrawSprite(a_pic,_x,_y,lay);

		return false;
	}
		
}

bool DrawButton(int _x, int _y, int _wt, int _ht, wchar_t *_pic, wchar_t * a_pic,int lay, wchar_t *lbl)
{

	int x,y;
	if(lay==0)
	{
		x=mouse0X;
	    y=mouse0Y;
	}
	else
	{
		x=mouseX;
		y=mouseY;
	}
	
	if(cross(_x,_y,_ht,_wt,x,y,1,1))
	{
		allowCreate=false;

		DrawSprite(a_pic,_x,_y,lay);
		label->Set(_x,_y,lbl);
		if(MouseLBPress()&&!mscheck)
		{
		    mscheck=true;
		    btnClck(L"buttonClick.wav");
		    return true;
		}
	}
	else
	{
		DrawSprite(_pic,_x,_y,lay);

		return false;
	}
		
}

bool DrawButtonNum(int num, int x, int y)
{

	if(cross(x,y,40,40,GetMouseX(),GetMouseY(),1,1))
	{
		DrawSprite(L"buttonBack.png",x-4,y-4,0,0,1.2);
	    PrintDigit(num,0,x+18,y+10,0.5,0,COLOR(255,0,0,0));
		allowCreate=false;

		if(MouseLBPress()&&!mscheck)
		{
			mscheck=true;
			return true;
		}
		else
		    return false;
	}
	else
	{
	    DrawSprite(L"buttonBack.png",x,y,0);
	    PrintDigit(num,0,x+18,y+10,0.5,0,COLOR(255,0,0,0));

		return false;
	}

}

bool DrawButtonWord(wchar_t *word, int x, int y, int length)
{

	if(cross(x-5,y-5,30,20*length,GetMouseX(),GetMouseY(),1,1))
	{
		Print(word,x-2,y-2,1.1);
		allowCreate=false;
		if(MouseLBPress()&&!mscheck)
		{
			mscheck=true;
			return true;
		}
		else
			return false;
	}
	else
	{
		Print(word,x,y);
		return false;
	}
}


void GameTimer()  //Игровой таймер, держит фпс в границах 100
{
	time2=timeGetTime();

	while(time2-5<time1)
	{
		Sleep(1);
		time2=timeGetTime();
	}

}

int tD()
{
	tm1=timeGetTime();
	if(tm1-tm0<5)
		return tm1-tm0;
	else
		return 5;
}

doubleInt LastBlock()
{
	doubleInt s;

	int w=width;
	int h=height;
	
	h=FindLastY(w,h);
	w=FindLastX(w,h);

	s.setA(w);
	s.setB(h);

	return s;
}

int FindLastY(int x, int y)
{
	if(!world->Exist(x,y))
	{
		if(y>0)
			return FindLastY(x,y-1);
		else
		{
			if(x>0)
			{
				if(y==0)
					y=height;

				return FindLastY(x-1,y);
			}
			else
				return 0;
		}
	}
	else
		return y;
}

int FindLastX(int x, int y)
{
	if(!world->Exist(x,y))
	{
		if(x>0)
			return FindLastX(x-1,y);
		else
			return 0;
	}
	else
		return x;
}

int RandInt(int min,int max)
{
	return ((rand()%(max-min))+min);
}

void CheckKeys()
{
	if(!m_menu&&allowCreate)
	{
	    if(blocks)
	    {
	        if(!addMass)
		    {
	            if(MouseLBPress()&&!mscheck)
	            {
		            world->Add(mouseX,mouseY,curType);
		            mscheck=true;
	            }

		        if(MouseRBPress()&&!mscheck)
		        {
		            world->Del(mouseX,mouseY);
			        mscheck=true;
		        }
		    }
		    else
		    {
			    if(MouseLBPress()&&!mscheck)
	            {
		            world->Add(mouseX,mouseY,curType);
	            }

		        if(MouseRBPress()&&!mscheck)
		        {
		            world->Del(mouseX,mouseY);
		        }
		    }
	   }

	   if(mobs)
	   {
		   if(MouseLBPress()&&!mscheck)
	       {
		       world->AddEnemy(mouseX,mouseY,curType);
		       mscheck=true;
	       }
	   }

	   if(objects)
	   {
		   if(MouseLBPress()&&!mscheck)
		   {
		      	world->AddObject(mouseX,mouseY,curType);
			   mscheck=true;
		   }
	   }

	   if(finish)
	   {
		   if(MouseLBPress()&&!mscheck)
		   {
			   world->AddTeleport(mouseX,mouseY,curType);
			   mscheck=true;
		   }
	   }


	   if(KeyCheck(DIK_F6)&&!keyp)
	   {
	       world->Load();
	       keyp=true;
	   }

	   if(KeyCheck(DIK_F5)&&!keyp)
	   {
	       world->Save();
	       keyp=true;
	   }

	   if(KeyCheck(DIK_F7)&&!keyp)
	   {
	       m_menu=true;
	       keyp=true;
	   }

	   if(!KeyCheck(DIK_F5)&&!KeyCheck(DIK_F6)&&!KeyCheck(DIK_F7))
	   {
	       keyp=false;
	   }
	}


	if(!MouseLBPress()&&!MouseRBPress())
	{
		mscheck=false;
	}

	allowCreate=true;
}

void ShowItem()
{
	wchar_t *sprite;
	sprite=L" ";

	if(blocks)
	{
		sprite=RType(curType);
	}

	if(mobs)
	{
		switch(curType)
	    {
	        case 1:sprite=L"mc_ball.png";break;
	        case 2:sprite=L"mc_flyHead.png";break;
	        case 3:sprite=L"mc_golem.png";break;

	        default:sprite=L"mc_ball.png";break;
	    }
	}

	if(objects)
	{
		switch(curType)
		{
		case 1:sprite=L"mc_playerStart.png";break;
		default:sprite=L"mc_playerStart.png";break;
		}
	}

	if(finish)
	{
		sprite=L"mc_finishPoint.png";
	}

	if(GetMouseX()>100&&GetMouseY()>100&&!m_menu)
	{
		if(blocks)
	        DrawSprite(sprite,GetMouseX(),GetMouseY(),0,0,1,COLOR(100,255,255,255));
	    else
		    DrawSprite(sprite,GetMouseX(),GetMouseY(),0,0,1,COLOR(100,255,255,255));
	}

}

void ShowWord(wchar_t* word, int &var, int x, int y)
{
	if(var>0)
	{
		Print(word, x,y,1,0,COLOR(var,0,0,0));
	    var--;
	}
}