#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <time.h>
#include <math.h>
#include<fstream>     //uisng File I/O

using namespace std;

//random generator function
int  Poisson(float mean);

int main()
{
	float mean;

	ofstream out_file;
	out_file.open("outfile.txt");


	//random time
	int seed = time(NULL);
	srand(seed);
	
	mean = 0.5; //mean = 0.5
	cout << "Start generating......" << endl;

	for (int i = 0; i < 100000; i++)
	{
		//cout<<Poisson(mean)<<endl;
		out_file << Poisson(mean)+0.5 << endl;
	}

	cout << "Generate  finished! " << endl;

	out_file.close();   //close file
	system("pause");
	return 0;
}




int Poisson(float mean) //Special technique required: Box-Muller method...
{
	float R;
	float sum = 0;
	int i;
	i = -1;
	float z;

	while (sum <= mean)
	{

		R = (float)rand() / (float)(RAND_MAX + 1);
		z = -log(R);
		sum += z;
		i++;
	}
	return i;
}