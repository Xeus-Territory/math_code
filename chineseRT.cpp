#include <iostream>
using namespace std;

int gcd(int m, int n)     	// function definition
{                         	// block begin
	int  r;                	// declaration of remainder

	while (n != 0) 
        {       	                // not equal
		r = m % n;          	// modulus operator
		m = n;              	// assignment
		n = r;
	}                      	// end while loop
	return m;              	// exit gcd with value m
}const int Max = 50;

int compute(int mod, int fir )
{
	int i = 0;
	bool solved = false;

	
	fir = fir%mod;
	while (solved == false)
	{
		i++;

		if ((fir * i) % mod == 1)
		{
			solved = true;
		}
	}

	return i;
}

int main()
{
	
	char repeat;
	bool allGood=true;
	int x[Max];
	int y[Max];
	int a[Max];
	int b[Max];
	int equ;
	int mul=1;
	int B;
	int z;

	cout << "\tThis program computes Chinese remainder theorem.";
	cout << "\n\tThe statment looks like X=z mod m"<<endl;
	do
	{
		cout << "Number of equ you are computing for:";
		cin >> equ;

		for (int i = 1; i <= equ; i++)
		{
			cout << endl;
			cout << "z = ";
			cin >> x[i];
			cout << "m= ";
			cin >> y[i];
		}

		int i = 1, j = 1;
		while (i <= equ){

			while (j <= equ){
				if (i != j)
				{
					if (gcd(y[i], y[j]) != 1)
					{
						cout << "No solution since the mod's dont have a common gcd" << endl;
						allGood = false;
					}

				}
				j++;
			}
			i++;
		}

		if (allGood)
		{
			B = 1;
		for (int i = 1; i <= equ; i++)
		{
			B = B * y[i];
		}
		for (int i = 1; i <= equ; i++)
		{
			b[i] = B / y[i];
		}

		for (int i = 1; i <= equ; i++)
		{
			a[i] = compute(y[i], b[i]);
		}
		z = 0;
		for (int i = 1; i <= equ; i++)
		{
			z += a[i] * b[i] * x[i];
		}
		z = z%B;

		//Print result:
		cout << endl << "X = " << z << endl << endl;
		for (int i = 1; i <= equ; i++)
		{
			mul *= y[i];
		}
		cout << " Multiples: ";

		for (int i = 0; i < 5; i++)
		{
			cout  << i*mul + z<<" ,";
		}
		cout << "...";
	}
		// would you like to it again

		cout << endl << "Would you like to continue? (y or n):";
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}