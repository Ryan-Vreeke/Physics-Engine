#include <cmath>
#include <gtest/gtest.h>
#include <vector>
#include "Body.h"
#include "physics.cpp"

TEST(MatrixTest, DefaultConst){
  Matrix obj;

  EXPECT_EQ(obj.x, 0);
  EXPECT_EQ(obj.y, 0);
}

TEST(MatrixTest, DistTest){
  Matrix obj(1,1);
  Matrix obj1(2,2);

  EXPECT_FLOAT_EQ(obj.dist(obj1), std::sqrt(2));
}

TEST(MatrixTest, DirTest){
  Matrix obj(1,1);

  EXPECT_NEAR(obj.dir(), 0.785,0.001);
}

TEST(MatrixTest, DotTest){
  Matrix obj(1,1);
  Matrix obj1(2,2);

  EXPECT_EQ(obj.dot(obj1), 4);
}

TEST(MatrixTest, ScaleTest){
  Matrix obj(1,1);
  obj.scale(2); 
  
  EXPECT_EQ(obj.x, 2);
  EXPECT_EQ(obj.y, 2);
}

TEST(MatrixTest, MagTest){
  Matrix obj(1,1);
  
  EXPECT_FLOAT_EQ(obj.mag(), std::sqrt(2));
}

TEST(MatrixTest, AddTest){
  Matrix obj(1,1);
  Matrix obj1(2,2);
  
  obj.add(obj1);


  EXPECT_EQ(obj.x, 3);
  EXPECT_EQ(obj.y, 3);
}

/*PHYSICS TEST*/
TEST(PhysicsTests, UpdateTest){
  std::vector<Body> *objs = new std::vector<Body>();
  Physics p;
  objs->push_back(Body());
  p.update(objs);

  Body b = objs->at(0);
  EXPECT_FLOAT_EQ(b.a->y , 9.8);
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
