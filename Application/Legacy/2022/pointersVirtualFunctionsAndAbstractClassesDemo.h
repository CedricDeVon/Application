
class Geometry
{
public:
	Geometry()
	{
		this->_name = "Geometry";
	}

	Geometry(string name)
	{
		this->_name = name;
	}

	string getName()
	{
		return this->_name;
	}

	virtual void draw()
	{
		cout << "Drawing " << this->_name << ": " << '\n';
	}

protected:
	string _name;
};

class Point : public Geometry
{
public:
	Point() : Geometry("Point")
	{
		this->_x = 0;
		this->_y = 0;
	}

	Point(double x) : Geometry("Point")
	{
		this->_x = x;
		this->_y = 0;
	}

	Point(double x, double y) : Geometry("Point")
	{
		this->_x = x;
		this->_y = y;
	}

	~Point()
	{
		cout << "Deleting " << this->_name << ": " << "(" << this->_x << ", " << this->_y << ")" << '\n';
	}

	double getX()
	{
		return this->_x;
	}

	double getY()
	{
		return this->_y;
	}

	void setX(double x)
	{
		this->_x = x;
	}

	void setY(double y)
	{
		this->_y = y;
	}

	void draw()
	{
		cout << "Drawing " << this->_name << ": " << "(" << this->_x << ", " << this->_y << ")" << '\n';
	}


private:
	double _x;
	double _y;
};

class Polygon : public Geometry
{
public:
	Polygon() : Geometry("Polygon")
	{

	}
	
	Polygon(string name) : Geometry(name)
	{

	}
	
	Polygon(vector<Point*> &points) : Geometry("Polygon")
	{
		for (Point* point : points)
		{
			this->_points.push_back(point);
		}
	}
	
	Polygon(vector<Point*> &points, string name) : Geometry(name)
	{
		for (Point* point : points)
		{
			this->_points.push_back(point);
		}
	}
	
	~Polygon()
	{
		cout << "Deleting " << this->_name << ": " << '\n';
		// for (Point *point : this->_points)
		// {
		// 	cout << '\t';
		// 	delete point;
		// }
	}

	void addPoint(Point *point)
	{
		this->_points.push_back(point);
	}

	void draw()
	{
		cout << "Drawing " << this->_name << ": " << '\n';
		for (Point *point : this->_points)
		{
			cout << '\t';
			point->draw();
		}
	}

private:
	vector<Point*> _points;
};

class Square : public Polygon
{
public:
	Square() : Polygon("Square")
	{

	}

	Square(Point *bottomLeftPoint,
		Point *topLeftPoint,
		Point *topRightPoint,
		Point *bottomRightPoint) : Polygon("Square")
	{
		this->addPoint(bottomLeftPoint);
		this->addPoint(topLeftPoint);
		this->addPoint(topRightPoint);
		this->addPoint(bottomRightPoint);
	}

	~Square()
	{

	}
};

class Triangle : public Polygon
{
public:
	Triangle() : Polygon("Triangle")
	{

	}

	Triangle(Point *basePoint,
		Point *firstAnglePoint,
		Point *secondAnglePoint) : Polygon("Triangle")
	{
		this->addPoint(basePoint);
		this->addPoint(firstAnglePoint);
		this->addPoint(secondAnglePoint);
	}

	~Triangle()
	{

	}
};
