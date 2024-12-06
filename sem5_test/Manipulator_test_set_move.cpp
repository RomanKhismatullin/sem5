#include "pch.h"
#include "../sem5/Manipulator.h"
#include "../sem5/Element.h"

TEST(ManipulatorTests, Set) {
	IManipulator* mn = new Manipulator();
	auto e0 = new Element(0, 0);
	auto e1 = new Element(0, 1);
	auto e2 = new Element(1, 2);
	ASSERT_FALSE(mn->AddElement(e0));
	ASSERT_FALSE(mn->AddElement(e1));
	ASSERT_FALSE(mn->AddElement(e2));
}