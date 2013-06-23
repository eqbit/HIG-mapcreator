
class doubleInt
{
	int a, b;
public:
	int getA(){return a;}
	int getB(){return b;}
	void setA(int _a){a=_a;}
	void setB(int _b){b=_b;}
	doubleInt();
};

doubleInt::doubleInt()
{
	a=0;
	b=0;
}

class _label
{
	int x, y;
	bool allow;
	wchar_t* label;
public:
	_label();
	void Draw();
	void Set(int _x, int _y, wchar_t *_lbl);
};

_label* label;