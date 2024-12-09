#include "pch.h"
#include <vector>
#include <complex>
#include "../sem5/Element.h"
#include "../sem5/Manipulator.h"

TEST(ManipulatorTest, DRWTest) { // линия
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0);
	auto el2 = new Element(0, 1);
	auto el3 = new Element(1, 2);
	auto el4 = new Element(2, 3);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);

	mn->DRW();

	Point P1(0, 0);
	Point P2(1, 0);
	Point P3(2, 0);
	Point P4(3, 0);
	

	EXPECT_EQ(P1, el1->drw);
	EXPECT_EQ(P2, el2->drw);
	EXPECT_EQ(P3, el3->drw);
	EXPECT_EQ(P4, el4->drw);
	EXPECT_EQ(P4 + Point(1, 0), el4->drw2());


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(0, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);

}


TEST(ManipulatorTest, DRWTest2) { // - - UP - DOWN
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0);
	auto el2 = new Element(0, 1);
	auto el3 = new Element(1, 2, 1, 0, Pi/2);
	auto el4 = new Element(2, 3, 1, 0, -Pi/2);
	auto el5 = new Element(3, 4, 1, 0, -Pi/2);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);
	mn->AddElement(el5);

	mn->DRW();



	Point P1(0, 0);
	Point P2(1, 0);
	Point P3(2, 0);
	Point P4(2, 1);
	Point P5(3, 1);


	EXPECT_EQ(P1, el1->drw);
	EXPECT_EQ(P2, el2->drw);
	EXPECT_EQ(P3, el3->drw);
	EXPECT_EQ(P4, el4->drw);
	EXPECT_EQ(P5, el5->drw);
	EXPECT_EQ(Point(3.0, 0.0), el5->drw2());


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(Pi / 2, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);
	EXPECT_EQ(-Pi / 2, el5->drwAlpha);

}
TEST(ManipulatorTest, DRWTest3) { // ROT Pi/2
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0, 0, Pi / 2);
	auto el2 = new Element(0, 1);
	auto el3 = new Element(1, 2, 1, 0, Pi / 2);
	auto el4 = new Element(2, 3, 1, 0, -Pi / 2);
	auto el5 = new Element(3, 4, 1, 0, -Pi / 2);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);
	mn->AddElement(el5);

	mn->DRW();



	//Point P1(0, 0);
	//Point P2(1, 0);
	//Point P3(2, 0);
	//Point P4(2, 1);
	Point P5(-1, 3);


	EXPECT_TRUE(std::norm(P5 - el5->drw) < 1e-3);

	EXPECT_EQ(Pi / 2, el1->drwAlpha);
	EXPECT_EQ(Pi / 2, el2->drwAlpha);
	EXPECT_EQ(Pi, el3->drwAlpha);
	EXPECT_EQ(Pi / 2, el4->drwAlpha);
	EXPECT_EQ(0, el5->drwAlpha);

}


TEST(ManipulatorTest, DRWTest4) { // -(2) - UP - DOWN
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0);
	auto el2 = new Element(0, 1, 2);
	auto el3 = new Element(1, 2, 1, 0, Pi / 2);
	auto el4 = new Element(2, 3, 1, 0, -Pi / 2);
	auto el5 = new Element(3, 4, 1, 0, -Pi / 2);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);
	mn->AddElement(el5);

	mn->DRW();



	//Point P1(0, 0);
	//Point P2(1, 0);
	//Point P3(2, 0);
	//Point P4(2, 1);
	Point P5(4, 1);


	//EXPECT_EQ(P1, el1->drw);
	//EXPECT_EQ(P2, el2->drw);
	//EXPECT_EQ(P3, el3->drw);
	//EXPECT_EQ(P4, el4->drw);
	EXPECT_EQ(P5, el5->drw);


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(Pi / 2, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);
	EXPECT_EQ(-Pi / 2, el5->drwAlpha);

}


TEST(ManipulatorTest, DRWTest5) {  // branch at zero // - - UP - (0)DOWN
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0);
	auto el2 = new Element(0, 1, 2);
	auto el3 = new Element(1, 2, 1, 0, Pi / 2);
	auto el4 = new Element(2, 3, 1, 0, -Pi / 2);
	auto el5 = new Element(0, 4, 0, 0, -Pi / 2);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);
	mn->AddElement(el5);

	mn->DRW();



	//Point P1(0, 0);
	//Point P2(1, 0);
	//Point P3(2, 0);
	//Point P4(2, 1);
	Point P5(0, 0);


	//EXPECT_EQ(P1, el1->drw);
	//EXPECT_EQ(P2, el2->drw);
	//EXPECT_EQ(P3, el3->drw);
	//EXPECT_EQ(P4, el4->drw);
	EXPECT_EQ(P5, el5->drw);


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(Pi / 2, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);
	EXPECT_EQ(-Pi / 2, el5->drwAlpha);

}

class MOCKElement : public Element {
public:
	MOCKElement(int Np, int N, double x, double y, double a, double l) : Element(Np, N, x, y, a, l) {

	}

	void setNp(int NP) {
		_NPrev = NP;
	}
	void setX(double x) {
		_X = x;
	}
};



TEST(ManipulatorTest, DRW6CONSEQ) {
	Manipulator* mn = new Manipulator();

	auto el1 = new Element(0, 0, 0);
	auto el2 = new Element(0, 1, 2);
	auto el3 = new Element(1, 2, 1, 0, Pi / 2);
	auto el4 = new Element(2, 3, 1, 0, -Pi / 2);
	MOCKElement* el5 = new MOCKElement(3, 4, 1, 0, -Pi / 2, 1);

	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->AddElement(el4);
	mn->AddElement(el5);

	mn->DRW();

	Point P5(4, 1);
	EXPECT_EQ(P5, el5->drw);


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(Pi / 2, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);
	EXPECT_EQ(-Pi / 2, el5->drwAlpha);


	//auto el5 = new Element(0, 4, 0, 0, -Pi / 2);
	
	el5->setNp(0);
	el5->setX(0);
	mn->DRW();
	Point P5_(0, 0);
	EXPECT_EQ(P5_, el5->drw);


	EXPECT_EQ(0, el1->drwAlpha);
	EXPECT_EQ(0, el2->drwAlpha);
	EXPECT_EQ(Pi / 2, el3->drwAlpha);
	EXPECT_EQ(0, el4->drwAlpha);
	EXPECT_EQ(-Pi / 2, el5->drwAlpha);
}






using std::vector;
using std::complex;
//#define Point complex<double>
#define MM_PI 3.141592653589793




//TEST(ManipulatorTest, MoveElementGettingConstPoints) {
//#pragma region prms
//	const int N = 5;
//	vector<Element*> el;
//	//el.push_back(new el(0, 0));
//	//el.push_back(new el(0, 0, ));
//#pragma endregion
//
//	vector<Point> Cpoints; // non movable Points //last point is our point
//	Cpoints.push_back(Point(el[0]->X(), el[0]->Y()));
//
//
//	double totalAlpha = 0; //counts current position of element
//	for (int i = 1; i <= N; i++) {
//		totalAlpha += el[i - 1]->Alpha();
//		Point rotator(std::polar(1.0, totalAlpha));
//		Point pos(el[i]->X(), el[i]->Y());
//		Cpoints.push_back(Cpoints[i - 1] + pos * rotator);
//	}
//
//	Point rp = Cpoints[N]; //rotation point
//
//	
//
//
//
//}