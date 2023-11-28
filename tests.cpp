#include <gtest/gtest.h>
#include "BST.h"

TEST(BSTClear, oneNode) 
{ 
    BST<int> bst;
    bst.setItem(1);
    ASSERT_TRUE(bst.findNum(1));
    bst.clear();
    ASSERT_FALSE(bst.findNum(1));
}

TEST(BSTClear, multipleNodes) 
{ 
    BST<int> bst;
    bst.setItem(2);
    bst.insertNum(1);
    bst.insertNum(3);
    ASSERT_TRUE(bst.findNum(3));
    bst.clear();
    ASSERT_FALSE(bst.findNum(3));
}

TEST(BSTClear, zeroNodes) 
{ 
    BST<int> bst;
    bst.clear();
    ASSERT_FALSE(bst.findNum(5));
}


TEST(BSTfinditem, notInTree) 
{ 
    BST<int> bst;
    bst.setItem(1);
    bst.insertNum(2);
    bst.insertNum(3);
    bst.insertNum(4);
    bst.insertNum(5);
    bst.insertNum(6);
    bst.insertNum(7);
    bst.insertNum(8);
    bst.insertNum(9);
    bst.insertNum(10);
    ASSERT_FALSE(bst.findNum(11));
    
}


TEST(BSTfinditem, tenNodes) 
{ 
    BST<int> bst;
    bst.setItem(1);
    bst.insertNum(2);
    bst.insertNum(3);
    bst.insertNum(4);
    bst.insertNum(5);
    bst.insertNum(6);
    bst.insertNum(7);
    bst.insertNum(8);
    bst.insertNum(9);
    bst.insertNum(10);
    ASSERT_TRUE(bst.findNum(10));
   
    
}

TEST(BSTfinditem, zeroNodes) 

{ 
    BST<int> bst;
    ASSERT_FALSE(bst.findNum(1));
    
}

TEST(BSTBSTAccending, 5nodes) 
{ 
    BST<int> bst;
    bst.setItem(1);
    ASSERT_TRUE(bst.findNum(1));
    bst.insertNum(2);
    bst.insertNum(3);
    bst.insertNum(4);
    bst.insertNum(5);
    
    std::vector<int> testVec = {4,2,5,1,3};
    std::vector<std::shared_ptr<BST<int>>> bstVec;
    bst.getAscending(bstVec);

    ASSERT_EQ(testVec[0],bstVec[0]->getItem());
    ASSERT_EQ(testVec[1],bstVec[1]->getItem());
    ASSERT_EQ(testVec[2],bstVec[2]->getItem());
    ASSERT_EQ(testVec[3],bstVec[3]->getItem());
    ASSERT_EQ(testVec[4],bstVec[4]->getItem());
    
}
TEST(BSTBSTAccending, 1node) 
{ 
    BST<int> bst;
    bst.setItem(1);
    ASSERT_TRUE(bst.findNum(1));
    
    std::vector<int> testVec = {1};
    std::vector<std::shared_ptr<BST<int>>> bstVec;
    bst.getAscending(bstVec);

    ASSERT_EQ(testVec[0],bstVec[0]->getItem());
    
}

TEST(BSTBSTAccending, noNodes) 
{ 
    BST<int> bst;
    ASSERT_TRUE(bst.getTreeSize() == 0);
    std::vector<std::shared_ptr<BST<int>>> bstVec;
    bst.getAscending(bstVec);
    ASSERT_TRUE(bstVec.empty());
    
}

TEST(BSTInsert, oneNode) 
{ 
    BST<int> bst;
    bst.setItem(1);
    bst.insertNum(47);
    ASSERT_TRUE(bst.findNum(47));
}

TEST(BSTInsert, balancedTree) 
{ 
    BST<int> bst;
    bst.setItem(4);
    bst.insertNum(2);
    bst.insertNum(1);
    bst.insertNum(3);
    bst.insertNum(6);
    bst.insertNum(5);
    bst.insertNum(7);
    ASSERT_TRUE(bst.findNum(7));
}

TEST(BSTInsert, negativeNum) 
{ 
    BST<int> bst;
    bst.insertNum(-10);
    ASSERT_TRUE(bst.findNum(-10));
}

TEST(BSTRemove, firstnode) 
{ 
   BST<int> bst;
   std::shared_ptr<BST<int>> bstPtr = std::make_shared<BST<int>>(bst);
   bst.setItem(1);
   bst.insertNum(2);

   ASSERT_TRUE(bst.findNum(1));

   ASSERT_TRUE(bst.removeNum(1,bstPtr));
   
   ASSERT_FALSE(bstPtr->findNum(1));
}

TEST(BSTRemove, lastnode) 
{ 

    BST<int> bst;
    std::shared_ptr<BST<int>> bstPtr = std::make_shared<BST<int>>(bst);

    bst.setItem(1);
    bst.insertNum(2);
    bst.insertNum(3);
    bst.insertNum(4);
    bst.insertNum(5);

    ASSERT_TRUE(bst.findNum(5));

    ASSERT_TRUE(bst.removeNum(5,bstPtr));

    ASSERT_TRUE(bst.findNum(1));
    ASSERT_TRUE(bst.findNum(2));
    ASSERT_TRUE(bst.findNum(3));
    ASSERT_TRUE(bst.findNum(4));
    ASSERT_FALSE(bst.findNum(5));
}

TEST(BSTRemove, noNodes) 
{ 
   BST<int> bst;
   std::shared_ptr<BST<int>> bstPtr = std::make_shared<BST<int>>(bst);
   ASSERT_FALSE(bst.findNum(1));
   
   ASSERT_FALSE(bst.removeNum(1,bstPtr));
   
}


TEST(BSTSize, 5nodes) 
{ 
    BST<int> bst;
    bst.setItem(1);
    bst.insertNum(2);
    bst.insertNum(3);
    bst.insertNum(4);
    bst.insertNum(5);

    ASSERT_EQ(5,bst.getTreeSize());    
}

TEST(BSTSize, 1node) 
{ 
    BST<int> bst;
    bst.setItem(1);
    ASSERT_EQ(1,bst.getTreeSize());
}

TEST(BSTSize, noNodes) 
{ 
    BST<int> bst;
    ASSERT_EQ(0,bst.getTreeSize());
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
