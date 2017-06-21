#include<math.h>
#include<iostream >
using namespace std;

class Matrixx
{
private:
	int **arr;
	int row;
	int col;

	int cofactor( int , int );
	void ini_arr( int, int);
	friend istream & operator>>( istream & in, Matrixx & src );
	friend ostream & operator<<( ostream & out, Matrixx & src );

public:
	Matrixx(void);
	~Matrixx(void);

	Matrixx( Matrixx & );
	Matrixx(int **, int, int);
	Matrixx(int,int);
	void set_arr(int **, int, int);
	Matrixx adj(  );
	Matrixx operator*( Matrixx &A );
	Matrixx operator-( Matrixx &A );
	Matrixx operator+( Matrixx &A );
	int det(  );

	


};

