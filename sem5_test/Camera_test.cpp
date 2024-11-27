#include "pch.h"
#include "../sem5/Camera.h"
#include "../sem5/Camera.cpp"

TEST(CameraTest, DefaultConstructor) {
	Camera* s = new Camera(0, 1);
	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 0);
	EXPECT_EQ(s->Y(), 0);
	EXPECT_EQ(s->Alpha(), 0);
	EXPECT_EQ(s->AlphaView(), 0);
}


TEST(CameraTest, testSetlphaView) {
	Camera* s = new Camera(0, 1);
	s->SetAlphaView(3);
	EXPECT_EQ(s->AlphaView(), 3);
}


TEST(CameraTest, Constructor) {
	Camera* s = new Camera(0, 1, 2, 3, 4, 5);


	EXPECT_EQ(s->NPrev(), 0);
	EXPECT_EQ(s->N(), 1);
	EXPECT_EQ(s->X(), 2);
	EXPECT_EQ(s->Y(), 3);
	EXPECT_EQ(s->Alpha(), 4);

	EXPECT_EQ(s->AlphaView(), 5);
}
