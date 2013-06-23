void Interface()
{


	if(m_menu)
	{
		DrawSprite(L"menu_back.png",0,0,0);
		
			if(DrawButtonNum(1,100,300))
				world->SetMap(1);

			if(DrawButtonNum(2,100,350))
				world->SetMap(2);

			if(DrawButtonNum(3,100,400))
				world->SetMap(3);

			if(DrawButtonNum(4,100,450))
				world->SetMap(4);

			if(DrawButtonNum(5,100,500))
				world->SetMap(5);

			world->PrintMap();

			if(DrawButtonWord(L"Load",400,500,4))
			{
				world->Load();
				m_menu=false;
			}
		
	}
	else
	{

	    DrawSprite(L"topBack.png",0,0,0);
	    DrawSprite(L"leftBack.png",0,100,0);


	    if(blocks)
	    {
	        if(DrawButton(120,10,40,40,L"b_dirt.png",L"b_dirt.png",0,L"DIRT"))
	        {
	        	curType=1;
	        }
	        if(DrawButton(160,10,40,40,L"b_bricks.png",L"b_bricks.png",0,L"BRICKS"))
	        {
	    	    curType=2;
	        }
	        if(DrawButton(200,10,40,40,L"b_stone.png",L"b_stone.png",0,L"STONE"))
	        {
	    	    curType=3;
	        }
	        if(DrawButton(240,10,40,40,L"b_wood.png",L"b_wood.png",0,L"WOOD"))
	        {
	        	curType=4;
	        }
	        if(DrawButton(280,10,40,40,L"b_borderblock.png",L"b_borderblock.png",0,L"BORDER"))
	        {
	    	    curType=5;
	        }
	        if(DrawButton(320,10,40,40,L"b_bluebacks.png",L"b_bluebacks.png",0,L"BLUEBACK"))
	        {
	    	    curType=6;
	        }
	        if(DrawButton(360,10,40,40,L"b_greybacks.png",L"b_greybacks.png",0,L"GREYBACK"))
	        {
		        curType=7;
	        }
	        if(DrawButton(400,10,40,40,L"b_fire.png",L"b_fire.png",0,L"FIRE"))
	        {
	        	curType=8;
	        }
	        if(DrawButton(440,10,40,40,L"b_spikes.png",L"b_spikes.png",0,L"SPIKES"))
	        {
	    	    curType=9;
	        }
	        if(DrawButton(480,10,40,40,L"b_essence.png",L"b_essence.png",0,L"ESSENCE"))
	        {
	        	curType=10;
	        }
		    if(DrawButton(120,50,40,40,L"uperButton.png",L"uperButton.png",0,L"UPER"))
	        {
	    	    curType=11;
	        }
	        if(DrawButton(160,50,40,40,L"pusherRightButton.png",L"pusherRightButton.png",0,L"PUSHER L"))
	        {
	    	    curType=12;
	        }
	        if(DrawButton(200,50,40,40,L"pusherLeftButton.png",L"pusherLeftButton.png",0,L"PUSHER R"))
	        {
	    	    curType=13;
	        }
	        if(DrawButton(240,50,40,40,L"marbleButton.png",L"marbleButton.png",0,L"MARBLE"))
	        {
	    	    curType=14;
	        }
	        if(DrawButton(280,50,40,40,L"sandButton.png",L"sandButton.png",0,L"SAND"))
	        {
	    	    curType=15;
	        }
	        if(DrawButton(320,50,40,40,L"stareButton.png",L"stareButton.png",0,L"LADDER"))
	        {
	        	curType=16;
	        }
			if(DrawButton(360,50,40,40,L"b_stuff.png",L"b_stuff.png",0,L"STUFF"))
	        {
	        	curType=17;
	        }
			if(DrawButton(400,50,40,40,L"b_grassLevel.png",L"b_grassLevel.png",0,L"GLVL"))
	        {
	        	curType=18;
	        }
	    }

	    if(mobs)
	    {
		    if(DrawButton(105,20,30,30,L"ballBtn.png",L"ballBtn.png",0,L"BALL"))
	        {
	        	curType=1;
	        }
	        if(DrawButton(150,20,30,30,L"flyHeadBtn.png",L"flyHeadBtn.png",0,L"FLYHEAD"))
	        {
	        	curType=2;
	        }
	        if(DrawButton(195,20,30,30,L"golemBtn.png",L"golemBtn.png",0,L"GOLEM"))
	        {
	        	curType=3;
	        }
	    }

	    if(objects)
	    {
		    if(DrawButton(105,20,30,30,L"startObjBtn.png",L"startObjBtn.png",0,L"Start"))
	        {
	    	    curType=1;
	        }
	    }

	    if(finish)
	    {
	        if(DrawButtonNum(1,105,20))
			    curType=1;
		    if(DrawButtonNum(2,105,60))
			    curType=2;
			if(DrawButtonNum(3,145,20))
			    curType=3;
			if(DrawButtonNum(4,145,60))
			    curType=4;
			if(DrawButtonNum(5,185,20))
			    curType=5;
	    }

	
	    if(addMass)
		    massIMG=L"MassDrawButtonA.png";
	    else
		    massIMG=L"MassDrawButton.png";

	    if(addAnyway)
		    addAnywayIMG=L"AddAnywayButtonA.png";
	    else
		    addAnywayIMG=L"AddAnywayButton.png";

	    if(DrawButton(5,200,40,40,massIMG,massIMG,0,L"MassDraw"))
	    {
		    addMass=!addMass;
	    }

	    if(DrawButton(45,200,40,40,addAnywayIMG,addAnywayIMG,0,L"AddAnyway"))
	    {
		    addAnyway=!addAnyway;
	    }

	    if(DrawButton(5,100,40,40,L"mobbtn.png",L"mobbtn.png",0,L"Mobs"))
	    {
		    blocks=false;
		    objects=false;
		    mobs=true;
		    finish=false;
	    }

	    if(DrawButton(45,100,40,40,L"blckbtn.png",L"blckbtn.png",0,L"Blocks"))
	    {
	    	blocks=true;
		    objects=false;
		    mobs=false;
		    finish=false;
	    }

	    if(DrawButton(5,150,40,40,L"objectsBtn.png",L"objectsBtn.png",0,L"Objects"))
	    {
		    blocks=false;
		    objects=true;
		    mobs=false;
		    finish=false;
	    }

	    if(DrawButton(45,150,40,40,L"finishBtn.png",L"finishBtn.png",0,L"Finish"))
	    {
		    blocks=false;
		    objects=false;
		    mobs=false;
		    finish=true;
	    }


	/*if(DrawButton(5,85,40,40,L"menubtn.png",L"menubtn_a.png",0))
	{
		//WinExec("HopeIsGone",1);
		m_menu=true;
	}*/



	}

}