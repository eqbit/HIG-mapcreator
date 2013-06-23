class object
{
	int x, y,type;
	bool exist;
	wchar_t *sprite;
public:
	object();
	object(int _x, int _y, int _type);
	bool Exist(){return exist;}
	int getx(){return x;}
	int gety(){return y;}
	int getType(){return type;}
	void Draw();
};

class _objects
{
	vector <object> arr;
public:
	_objects();
	~_objects();
	void Add(int x, int y, int type);
	void Draw();
	void Clear(){arr.clear();}
	int Num(){return arr.size();}
	void Save(ofstream &out);
};


class block
{
public:
	int x,y,type;
	wchar_t *w_type;
	block();
	void Draw();
};

class enemy
{
	int x, y;
	int type;
	wchar_t *sprite;
	bool exist;
public:
	void Draw();
	int getx(){return x;}
	int gety(){return y;}
	int getType(){return type;}
	bool Exist(){return exist;}
	enemy(int _x, int _y, int _type);
	enemy();
};

class _enemies
{
	vector <enemy> desk;
public:
	void Add(int x, int y, int type);
	void Draw();
	void Save(ofstream &out);
	int Count();
	void Clear();
	~_enemies();
};

class teleporter
{
	int index;
	int x,y;
	bool exist;
public:
	void Draw();
	int getX(){return x;}
	int getY(){return y;}
	int getIndex(){return index;}
	bool Exist(){return exist;}
	teleporter();
	teleporter(int _x, int _y, int _index);
};

class teleporters
{
	vector<teleporter> tp;
public:
	void Add(int x, int y, int index);
	void Draw();
	void Save(ofstream &out);
	void Clear(){tp.clear();}
	int Num(){return tp.size();}
	~teleporters();
};


class _world
{
	int playerStartX,playerStartY;
	int currentWidth,currentHeight;
	_enemies* enemies;
	int enemyCount;
	_objects *objects;
	teleporters *tps;
	wchar_t *mName;

public:
	char* map_name;
	block **map;
	_world();
	~_world();
	void Draw(int x, int y);
	void DrawEnemies();
	void DrawObjects();
	void DrawFinish();
	void Add(int x, int y, int _type);
	void AddEnemy(int x, int , int type);
	void AddObject(int x, int y, int type);
	void AddTeleport(int x, int y, int index);
	void Del(int x, int y);
	void SetPlayerStart(int _x, int _y);
	void SetMap(int num);
	void PrintMap();
	void Save();
	void Load();
	void Create();
    bool Exist(int _x, int _y);
};

_world *world;


