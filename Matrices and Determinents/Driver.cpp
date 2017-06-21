#include"Matrixx.h"

int main()
{
	Matrixx a( 3, 3 ), b( 1,2 );
	//cin >> a >> b;
	cin >> a;
	//cout << a * b;
	cout << "Det : " <<a.det ();
	system("pause");
	return 0;
}