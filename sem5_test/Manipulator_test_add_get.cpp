#include "pch.h"
#include "../sem5/Manipulator.h"
#include "../sem5/Manipulator.cpp"
#include "../sem5/ManipulatorMoveElem.cpp"
#include "../sem5/Element.h"



TEST(ManipulatorTests, AdditionRight) {
	IManipulator* mn = new Manipulator();
	auto e0 = new Element(0, 0);
	auto e1 = new Element(0, 1);
	auto e2 = new Element(1, 2);
	ASSERT_FALSE(mn->AddElement(e0));
	ASSERT_FALSE(mn->AddElement(e1));
	ASSERT_FALSE(mn->AddElement(e2));


	auto e3 = new Element(0, 0);
	auto e4 = new Element(2, 3, 0,0,311, 0);
	auto e5 = new Element(2, 3, 0,0, 1, -1);
	ASSERT_TRUE(mn->AddElement(e3));
	ASSERT_TRUE(mn->AddElement(e4));
	ASSERT_TRUE(mn->AddElement(e5));
}

TEST(ManipulatorTests, AdditionWrong) {
	IManipulator* mn = new Manipulator();
	auto e0 = new Element(0, 0);
	auto e1 = new Element(0, 1);
	auto e2 = new Element(1, 2);
	ASSERT_TRUE(mn->AddElement(e1));
	ASSERT_FALSE(mn->AddElement(e0));
	ASSERT_TRUE(mn->AddElement(e2));
}

TEST(ManipulatorTests, AdditionWrongFirstEl) {
	IManipulator* mn = new Manipulator();
	auto e0 = new Element(1, 0);
	auto e1 = new Element(0, 1);
	auto e2 = new Element(1, 2);
	ASSERT_TRUE(mn->AddElement(e1));
	ASSERT_TRUE(mn->AddElement(e0));
	ASSERT_TRUE(mn->AddElement(e2));
}

TEST(ManipulatorTests, GetRight) {
	IManipulator* mn = new Manipulator();
	auto e0 = new Element(0, 0);
	auto e1 = new Element(0, 1);
	auto e2 = new Element(1, 2);
	ASSERT_FALSE(mn->AddElement(e0));
	ASSERT_FALSE(mn->AddElement(e1));
	ASSERT_FALSE(mn->AddElement(e2));
	ASSERT_EQ(mn->GetElement(5), nullptr);
	ASSERT_EQ(mn->GetElement(1), e1);

}

TEST(ManipulatorTests, GetVoid) {
	IManipulator* mn = new Manipulator();
	ASSERT_EQ(mn->GetElement(0), nullptr);

}