class Triangle
{

public:
  Triangle(int size, char border = '#', char fill = '*');
  int GetSize();
  int Perimeter();
  double Area();
  int Grow();
  int Shrink();

  char SetBorder(char border);
  char SetFill(char fill);

  void Draw();
  void Summary();  
private:
  int size_;
  char border_;
  char fill_;
};
