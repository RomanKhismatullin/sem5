#include "pch.h"
#include "../sem5/IAction.h"
#include "../sem5/ActionSet.h"
#include "../sem5/ActionSet.cpp"
#include "../sem5/MockManipulator.h"
//#include "../sem5/MockManipulator.cpp" //add this line if ActionMove_test.cpp is excluded



TEST(ActionSetTest, UsualSetTest) {
	ActionSet* act = new ActionSet(0, 3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 0);
	
	IAction* act2 = act;
	
	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 3.14);
	EXPECT_EQ(rs, 0);
}

TEST(ActionSetTest, WrongActN) {
	ActionSet* act = new ActionSet(2, 3.14); //exp false N!=0
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 2);

	IAction* act2 = act;

	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	act->DoWork(mm);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.1);
	EXPECT_EQ(rs, 1);
}

TEST(ActionSetTest, SeqSetTest) {
	ActionSet* act = new ActionSet(0, 3.14);
	ActionSet* act3 = new ActionSet(0, 1.5*3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 0);
	
	IAction* act2 = act;
	
	Element* el = new Element(0, 1);
	el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 1.1);

	auto mm = new MockManipulator();
	mm->AddElement(pos);
	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 3.14);
	EXPECT_EQ(rs, 0);

	act3->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 1.5*3.14);

}

#include "../sem5/Camera.h"

TEST(ActionSetTest, WrongType) {
	ActionSet* act = new ActionSet(0, 3.14);
	EXPECT_EQ(act->Fi, 3.14);
	EXPECT_EQ(act->N, 0);

	IAction* act2 = act;

	Camera* el = new Camera(0, 1); //Не звено!
	//el->MoveAlpha(1.1);

	Positionable* pos = el;
	EXPECT_EQ(el->Alpha(), 0);

	auto mm = new MockManipulator();
	mm->AddElement(pos);

	int rs = act->DoWork(mm);
	EXPECT_EQ(mm->Pos->Alpha(), 0);
	EXPECT_EQ(rs, 1);
}
