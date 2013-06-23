
block::block()
{
	x=0;
	y=0;
	type=0;
	w_type=L"";
}

void block::Draw()
{
	if(type!=0)
	    DrawSprite(w_type,x+drawCoef,y+drawCoef);
	else
		DrawSprite(L"noneBlock.png",x+100,y+100);
}



_world::_world()
{
	currentWidth=0;
	currentHeight=0;
	playerStartX=0;
	playerStartY=0;
	map_name="saves/default.map";

	map = new block*[width];
	for(int i=0;i<width;i++)
		map[i] = new block[height];

	enemies = new _enemies;
	enemyCount=0;
	objects=new _objects;
	tps=new teleporters;
	mName=L"Start";

}

_world::~_world()
{
	for(int i=0;i<width;i++)
		delete[] map[i];
	delete[] map;
	delete enemies;
	delete objects;
	delete tps;
}

void _world::Add(int x, int y, int _type)
{
	
	if(x>0&&x<width*blockSide&&y>0&&y<height*blockSide)
	{
	    x=x/blockSide;
	    y=y/blockSide;
		if(addAnyway)
		{
			map[x][y].x=x*blockSide;
	        map[x][y].y=y*blockSide;
	        map[x][y].type=_type;
	        map[x][y].w_type=RType(_type);
		}
		else
		{
		    if(map[x][y].type==0)
		    {
	            map[x][y].x=x*blockSide;
	            map[x][y].y=y*blockSide;
	            map[x][y].type=_type;
	            map[x][y].w_type=RType(_type);
		    }
		}
	}
}

void _world::AddEnemy(int x, int y, int type)
{
	enemies->Add(x,y,type);
	enemyCount++;
}

void _world::AddObject(int x, int y, int type)
{
	objects->Add(x,y,type);
}

void _world::AddTeleport(int x, int y, int index)
{
	tps->Add(x,y,index);
}

void _world::Del(int x, int y)
{
	x=x/blockSide;
	y=y/blockSide;
	map[x][y].type=0;
}

void _world::Draw(int x, int y)
{
	if(x>=0&&x<=currentWidth&&y>=0&&y<=currentHeight)
		map[x][y].Draw();
}

void _world::DrawEnemies()
{
	enemies->Draw();
}

void _world::DrawObjects()
{
	objects->Draw();
}

void _world::DrawFinish()
{
	tps->Draw();
}

bool _world::Exist(int _x, int _y)
{
	if(_x>=0&&_x<=width&&_y>=0&&_y<=height)
	{
		if(map[_x][_y].type!=0)
		    return true;
	    else
		    return false;
	}
	else
		return false;
}

void _world::Load()
{
	ifstream in(map_name);


	in>>currentWidth>>currentHeight;

	if(!in.fail()&&currentWidth>0&&currentWidth<=width&&currentHeight>0&&currentHeight<=height)
	{
		for(int i=0;i<width;i++)
	    {
		    for(int j=0;j<height;j++)
		   {
			    Del(i*blockSide,j*blockSide);
		    }
	    }

		for(int i=0;i<currentWidth;i++)
	    {
		    for(int j=0;j<currentHeight;j++)
		    {
			    int type;
			    in>>type;
			    Add(i*blockSide,j*blockSide,type);
		    }
	    }

		currentWidth=width;
		currentHeight=height;

		enemyCount=0;
		enemies->Clear();

		in>>enemyCount;

		for(int i=0;i<enemyCount;i++)
		{
			float _x,_y;
			int _type;
			in>>_x;
			in>>_y;
			in>>_type;
			enemies->Add(_x/2.5,_y/2.5,_type);
		}

		int objectsNum;
	
		in>>objectsNum;

		objects->Clear();

		for(int i=0;i<objectsNum;i++)
		{
			float _x,_y; int _type;
			in>>_type>>_x>>_y;
			objects->Add(_x/2.5,_y/2.5,_type);
		}

		int finishNum;

		in>>finishNum;

		tps->Clear();

		for(int i=0;i<finishNum;i++)
		{
			float x,y;
			int index;
			in>>x>>y>>index;
			tps->Add(x/2.5,y/2.5,index);
		}


	}
	else
	{
		currentWidth=width;
		currentHeight=height;

		for(int i=0;i<width;i++)
	    {
		    for(int j=0;j<height;j++)
		   {
			    Del(i*blockSide,j*blockSide);
		    }
	    }
	}

	
	in.close();
}


void _world::Save()
{
	///////////ÄÎÁÀÂËÅÍÈÅ ÃÐÀÍÈÖ/////////////
	for(int i=0;i<width;i++)
	{
		Add(i*blockSide,1,2);
		Add(i*blockSide,(height-9)*blockSide,2);
	}

	for(int i=0;i<height;i++)
	{
		Add(20*blockSide,i*blockSide,2);
		for(int j=0;j<20;j++)
		{
			Add(j*blockSide,i*blockSide,RandInt(1,3));
			Add((j+width-20)*blockSide,i*blockSide,RandInt(1,3));
		}
		Add((width-1)*blockSide,i*blockSide,2);
	}


	/////////////ÑÎÕÐÀÍÅÍÈÅ Â ÔÀÉË//////////////////

	ofstream out(map_name);

	out<<width<<" "<<height<<" ";////////øèðèíà è âûñîòà òåêóùåé êàðòû

	for(int i=0;i<width;i++)
	{
		for(int j =0;j<height;j++)
		{
			out<<map[i][j].type<<" ";
		}
	}


	enemies->Save(out);
	objects->Save(out);
	tps->Save(out);

	out.close();

	ofstream out1("saves/mapbackup.txt");

	out<<width<<" "<<height<<" ";////////øèðèíà è âûñîòà òåêóùåé êàðòû

	for(int i=0;i<width;i++)
	{
		for(int j =0;j<height;j++)
		{
			out<<map[i][j].type<<" ";
		}
	}


	enemies->Save(out1);
	objects->Save(out1);
	tps->Save(out1);

	out1.close();

	savedTime=255;
}

void _world::Create()
{
}


class _camera
{
public:
	int x,y;
	void Draw();
	_camera();
};

_camera *camera;

_camera::_camera()
{
	x=850;
	y=700;
}

void _camera::Draw()
{
	if(KeyCheck(DIK_A)&&x>810)
		x-=tD();

	if(KeyCheck(DIK_D)&&x<width*blockSide-10)
		x+=tD();

	if(KeyCheck(DIK_W)&&y>610)
		y-=tD();

	if(KeyCheck(DIK_S)&&y<height*blockSide-10)
		y+=tD();

	SetViewport(x-800,y-600);

	for(int i=x-820;i<x;i+=blockSide)
	{
		for(int j=y-620;j<y;j+=blockSide)
		{
			world->Draw(i/blockSide,j/blockSide);
		}
	}

	world->DrawEnemies();
	world->DrawObjects();
	world->DrawFinish();

}

void _world::SetMap(int num)
{
	switch(num)
	{
	case 1:
		map_name="saves/start.map";
		mName=L"Start";
		break;
	case 2:
		map_name="saves/second.map";
		mName=L"Second";
		break;
	case 3:
		map_name="saves/marbleLvl.map";
		mName=L"Marble level";
		break;
	case 4:
		map_name="saves/durt.map";
		mName=L"Durt";
		break;
	case 5:
		map_name="saves/firewalker.map";
		mName=L"Firewalker";
		break;
	default:
		map_name="saves/start.map";
		mName=L"Start";
		break;
	}
}

void _world::PrintMap()
{
	Print(mName,150,200,1.5,0,COLOR(200,255,255,255));
}