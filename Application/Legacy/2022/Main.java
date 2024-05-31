
class Rectangle extends Polygon
{
	public Rectangle(double abscissa1, double abscissa2, double ordinate1, double ordinate2)
	{
		super(
			new Point(abscissa1, ordinate1),
			new Point(abscissa1, ordinate2),
			new Point(abscissa2, ordinate2));
		super.addVertex(new Point(abscissa2, ordinate1));
	}

	public double computeDiagonalLength()
	{
		Point p1 = this.getVertices().get(1);
		Point p2 = this.getVertices().get(3);
		return Math.sqrt(
			Math.pow(p2.getX() - p1.getX(), 2) +
			Math.pow(p2.getY() - p1.getY(), 2));
	}

	public Point getCentroid()
	{
		Point p1 = this.getVertices().get(0);
		Point p2 = this.getVertices().get(1);
		Point p4 = this.getVertices().get(3);
		return new Point(
			(p4.getX() + p1.getX()) / 2,
			(p2.getY() + p1.getY()) / 2);
	}

	@Override
	public void addVertex(Point vertex)
	{
		System.out.println("You cannot add another point in a rectangle.");
	}

	@Override
	public boolean removeVertex(Point vertex)
	{
		System.out.println("You cannot remove another point in a rectangle.");
		return false;
	}
}
