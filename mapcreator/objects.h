object::object()
{

}

object::object(int _x, int _y, int _type)
{
	x=_x;
	y=_y;
	type=_type;
	exist=true;

	switch(type)
	{

	    case 1:sprite=L"mc_playerStart.png";break;

	}
}

void object::Draw()
{
	DrawSprite(sprite,x+drawCoef,y+drawCoef);
	if(objects)
	{
		if(MouseRBPress()&&cross(mouseX,mouseY,1,1,x-15,y-15,65,65))
			exist=false;
	}
}


_objects::_objects()
{

}

_objects::~_objects()
{
	arr.clear();
}

void _objects::Draw()
{
	for(int i=0;i<Num();i++)
	{
		arr.at(i).Draw();

		if(!arr.at(i).Exist())
		{
			if(i<Num())
				arr[i]=arr.back();
			arr.pop_back();
		}
	}
}

void _objects::Add(int x, int y, int type)
{
	arr.push_back(object(x,y,type));
}

void _objects::Save(ofstream &out)
{
	out<<Num()<<" ";
	for(int i=0;i<Num();i++)
		out<<arr[i].getType()<<" "<<arr[i].getx()*2.5<<" "<<arr[i].gety()*2.5<<" ";
}

enemy::enemy(int _x, int _y, int _type)
{
	x=_x;
	y=_y;
	type=_type;
	exist=true;

	switch(type)
	{
	case 1:sprite=L"mc_ball.png";break;
	case 2:sprite=L"mc_flyHead.png";break;
	case 3:sprite=L"mc_golem.png";break;

	default:sprite=L"mc_ball.png";break;
	}
}

enemy::enemy()
{

}

void enemy::Draw()
{
	DrawSprite(sprite,x+drawCoef,y+drawCoef);

	if(mobs)
	{
		if(MouseRBPress()&&cross(mouseX,mouseY,1,1,x-15,y-15,65,65))
			exist=false;
	}
}


_enemies::~_enemies()
{
	desk.clear();
}

int _enemies::Count()
{
	return desk.size();
}

void _enemies::Draw()
{
	for(int i=0; i<Count(); i++)
	{
		desk.at(i).Draw();
	    if(!desk.at(i).Exist())
		{
			if(i<Count())
				desk[i]=desk.back();
			desk.pop_back();
		}
	}
}

void _enemies::Add(int x, int y, int type)
{
	desk.push_back(enemy(x,y,type));
}


void _enemies::Save(ofstream &out)
{
	out<<Count()<<" ";

	for(int i=0;i<Count();i++)
	{
		int x=desk.at(i).getx()*2.5, y=desk.at(i).gety()*2.5, type=desk.at(i).getType();

		out<<x<<" "<<y<<" "<<type<<" ";
	}
}

void _enemies::Clear()
{
	desk.clear();
}




_label::_label()
{
	x=0;
	y=0;
	allow=false;
	label=L"";
}

void _label::Draw()
{
	if(allow)
	{
	    if(x-18>0)
		{
		    DrawSprite(L"labelBack.png",x-30,y+50,0);
		    Print(label,x-18,y+60,0.5,0,COLOR(200,0,0,0));
		}
		else
		{
		    DrawSprite(L"labelBack.png",x+15,y+50,0);
		    Print(label,x+27,y+60,0.5,0,COLOR(200,0,0,0));
		}

		allow=false;
	}
}

void _label::Set(int _x, int _y, wchar_t *_lbl)
{
	x=_x;
	y=_y;
	label=_lbl;
	allow=true;

}

teleporter::teleporter()
{

}

teleporter::teleporter(int _x, int _y, int _index)
{
	x=_x;
	y=_y;
	index=_index;
	exist=true;
}

void teleporter::Draw()
{
	PrintDigit(index,0,x+10+drawCoef,y-10+drawCoef,0.5,1);
	DrawSprite(L"mc_finishPoint.png",x+drawCoef,y+drawCoef);

	if(finish)
	{
		if(MouseRBPress()&&cross(mouseX,mouseY,1,1,x-15,y-15,65,65))
			exist=false;
	}
}

teleporters::~teleporters()
{
	tp.clear();
}

void teleporters::Add(int x, int y, int index)
{
	tp.push_back(teleporter(x,y,index));
}

void teleporters::Draw()
{
	for(int i=0;i<Num();i++)
	{
		tp[i].Draw();

		if(!tp.at(i).Exist())
		{
			if(i<Num())
				tp[i]=tp.back();
			tp.pop_back();
		}
	}
}

void teleporters::Save(ofstream &out)
{
	out<<Num()<<" ";
	for(int i=0;i<Num();i++)
	{
		out<<tp[i].getX()*2.5<<" "<<tp[i].getY()*2.5<<" "<<tp[i].getIndex()<<" ";
	}
}