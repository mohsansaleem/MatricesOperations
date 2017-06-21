#include "Matrixx.h"

Matrixx::Matrixx(void)
{
	arr = NULL;
	row = 0;
	col = 0;
}

Matrixx::~Matrixx(void)
{
	delete []*arr;
}

void Matrixx::set_arr( int **src , int r, int c )
{
	if( arr != NULL )
		delete []*arr;

	this->row = r;
	this->col = c;

	arr = new int* [ (this->row) ];

	
	for( int i = 0;i < row; i++ )
	{
		arr[i] = new int[ (this->col) ];

		if( src != NULL )
		for( int j = 0; j < col; j++ )
			arr[i][j] = src[i][j];
	}
	
}

void Matrixx::ini_arr( int r, int c )
{
	this->row = r;
	this->col = c;

	arr = new int* [ (this->row) ];

	
	for( int i = 0;i < row; i++ )
	{
		arr[i] = new int[ (this->col) ];
		for( int j = 0; j < col; j++ )
				arr[i][j] = 0;
		
	}
	
}

Matrixx::Matrixx( Matrixx &src )
{
	ini_arr( src.row , src.col  );
	set_arr( src.arr , src.row , src.col  );
}

Matrixx::Matrixx (  int r, int c )
{
	ini_arr(  r, c );
}

istream & operator>>( istream & in, Matrixx & src )
{

	for( int i =0; i < src. row; i++ )
	{
		for( int r = 0; r < src. col; r++ )
		{
			system("cls");
			cout << "Enter matrix" << endl;
			for( int z = 0; z < src. row; z++ )
			{
				for( int x = 0; x < src. col; x++ )
				{
					if( (z == i && x < r) || (z < i && x < src. row) )
						cout << src. arr[z][x] <<"\t";
				}
				if( z < i )
					cout << endl;
			}

            in >> src. arr[i][r];
		}                   
	}


	return in;
}

ostream & operator<<( ostream & out, Matrixx & src )
{
	out << endl;
	for( int i = 0; i < src.row; i++ )
	{
		for( int r = 0; r < src.col; r++ )
			out << src.arr[i][r]<< '\t';
		out<< endl; 
	}
	return out;
}

int Matrixx::det ()
{
	int dtr = 0;
	if( row == 1 && col == 1 )
		dtr = ( arr[0][0] );
	else
	{
		for( int i = 0; i < row; i++ )
			dtr += arr[i][0] * cofactor(i, 0);
	}
	return dtr; 
}

int Matrixx::cofactor( int r , int c )
{
	Matrixx temp( (this->row-1), (this->col-1) );

	int m = 0, n = 0;

	for( int x = 0; x < (this->row ); x++ )
	{
		n = 0;
		for( int y = 0; y < (this->col ); y++ )
		{
			if( x != r && y != c )
			{
				temp.arr[m][n] = (arr[x][y]);
				n++;			
			}		
		}
		if( x != r )
			m++;
	}

	double a = -1;

	return ( pow( a ,(r+c)) * temp.det());
}

Matrixx Matrixx::adj ()
{
	Matrixx temp( row, col );
	for( int i = 0; i < row; i++ )
		for( int r = 0; r < col ; r++ )
			temp.arr[i][r] = this->cofactor ( i, r );
	
	return temp;
}

Matrixx Matrixx::operator*( Matrixx &A )
{
	if( (this->col) = (A.row) )
	{
		Matrixx temp( (this->row), A.col );

		for( int row = 0; row < (this->row ); row++ )
		{
			
			for( int col = 0; col < A.col ; col++ )
			{
				int sum = 0;
				for( int i = 0; i < (this->col) ; i++)
					sum += (this->arr[row][i]) * ( A.arr[i][col] ) ;

				temp.arr[row][col] = sum;
			}
		
		}
		return temp;
	}
}


Matrixx Matrixx::operator+( Matrixx &A )
{
		Matrixx temp( (this->row), (this->col) );


	if( (this->col) != (A.col) && (this->row) != (A.row)  )
	{
		cerr << "Order Should be same!";
		exit(0);
	}
	else
	{

		for( int row = 0; row < (this->row ); row++ )
		{
			
			for( int col = 0; col < A.col ; col++ )
			{
				temp.arr[row][col] = (this->arr[row][col]) + A.arr[row][col] ;
			}
		
		}
	}
	return temp;
}


Matrixx Matrixx::operator-( Matrixx &A )
{
	Matrixx temp( (this->row), (this->col) );
	
	if( (this->col) != (A.col) && (this->row) != (A.row)  )
	{
		cout << "Order Should be same!";
		exit(0);
	}
	else
	{
		for( int row = 0; row < (this->row ); row++ )
		{
			
			for( int col = 0; col < A.col ; col++ )
			{
				temp.arr[row][col] = (this->arr[row][col]) - A.arr[row][col] ;
			}
		
		}
	}
	return temp;
}
