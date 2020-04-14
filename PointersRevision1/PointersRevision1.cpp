//https://www.youtube.com/watch?v=iChalAKXffs

#include <iostream>
#include <vector>

int main()
{
	int someArray[10] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30 };

	//int *pLocation6 = &someArray[6];
	int *pLocation0 = &someArray[0];

	for (int i = 0; i < 10; ++i)
	{
		//std::cout << someArray + i << " = " << *(someArray + i) << std::endl;
		std::cout << pLocation0 << " = " << *pLocation0 << std::endl;
		pLocation0++;
	}

	/*std::cout << "pLocation6 = " << (int)pLocation6 << std::endl;
	std::cout << "pLocation0 = " << (int)pLocation0 << std::endl;
	std::cout << "Difference = " << pLocation6 - pLocation0 << std::endl;*/

	std::cout << '\n';

	char someString[] = "Hello!";

	char *pSomeString = someString;	// == &someString[0]

	std::cout << "pSomeString = " << pSomeString << std::endl;

	char *pLocationA3 = &someString[3];
	char *pLocationA0 = &someString[0];

	std::cout << "pLocationA3 = " << (int)pLocationA3 << std::endl;
	std::cout << "pLocationA0 = " << (int)pLocationA0 << std::endl;
	std::cout << "Difference = " << pLocationA3 - pLocationA0 << std::endl;

	std::cout << '\n';

	struct sSomeObject
	{
		int x = 0xA3A2A1A0;
		int y = 0xB3B2B1B0;

		sSomeObject()
		{
			x = 0xC3C2C1C0;
			y = 0xD3D2D1D0;
		};
	};

	//Stack allocation (compile time)
	//sSomeObject pSomeObject[10];

	//Heap allocation (runtime)
	sSomeObject **pSomeObject = new sSomeObject * [10]{ 0 };

	for (int i = 0; i < 10; i++)
		pSomeObject[i] = new sSomeObject();

	for (int i = 0; i < 10; i++)
		delete pSomeObject[i];

	delete[] pSomeObject;

	std::cout << '\n';

	struct sSomeBaseObject
	{
		virtual const char* IdentifyYourself()
		{
			return "BaseObject";
		}
	};

	struct sSomeSubObjectA : public sSomeBaseObject
	{
		const char* IdentifyYourself()
		{
			return "SubObject A";
		}
	};

	struct sSomeSubObjectB : public sSomeBaseObject
	{
		const char* IdentifyYourself()
		{
			return "SubObject B";
		}
	};

	sSomeBaseObject ob_base;
	sSomeSubObjectA ob_A;
	sSomeSubObjectB ob_B;

	std::cout << ob_base.IdentifyYourself() << std::endl;
	std::cout << ob_A.IdentifyYourself() << std::endl;
	std::cout << ob_B.IdentifyYourself() << std::endl;

	std::cout << '\n';

	/*sSomeBaseObject objects[10];
	objects[3] = sSomeSubObjectA();

	for (int i = 0; i < 10; i++)
		std::cout << objects[i].IdentifyYourself() << std::endl;*/

	sSomeBaseObject** pSomeArrayA = new sSomeBaseObject*[5];

	pSomeArrayA[0] = new sSomeSubObjectA();
	pSomeArrayA[1] = new sSomeSubObjectB();
	pSomeArrayA[2] = new sSomeSubObjectB();
	pSomeArrayA[3] = new sSomeBaseObject();
	pSomeArrayA[4] = new sSomeSubObjectA();

	for (int i = 0; i < 5; i++)
		std::cout << pSomeArrayA[i]->IdentifyYourself() << std::endl;

	for (int i = 0; i < 5; i++)
		delete pSomeArrayA[i];

	delete[] pSomeArrayA;

	std::cout << '\n';

	std::vector<sSomeBaseObject*> vSomeVector;

	vSomeVector.push_back(new sSomeSubObjectA());
	vSomeVector.push_back(new sSomeSubObjectB());
	vSomeVector.push_back(new sSomeSubObjectB());
	vSomeVector.push_back(new sSomeBaseObject());
	vSomeVector.push_back(new sSomeSubObjectA());

	for (auto &a : vSomeVector)
		std::cout << a->IdentifyYourself() << std::endl;

	for (auto &a : vSomeVector)
		delete a;

	vSomeVector.clear();

	std::cout << '\n';

	{
		std::shared_ptr<sSomeObject> spSomeObject1 = std::make_shared<sSomeObject>();
	
		{
			std::shared_ptr<sSomeObject> spSomeObject2 = spSomeObject1;
		}

	}

	std::cout << '\n';

	{
		std::unique_ptr<sSomeObject> upSomeObject1 = std::make_unique<sSomeObject>();

		{
			std::unique_ptr<sSomeObject> upSomeObject2 = std::move(upSomeObject1);
		}

	}

	std::cout << '\n';

	return 0;
}