#include "gtest/gtest.h"
#include <fstream>
#include "../include/functions.h"

TEST(SearchByShopTest, FindsProductsInShop) {
  std::ofstream testFile("test_products.txt");
  testFile << "Product1 StoreA 10.0 5 pcs\n";
  testFile << "Product2 StoreB 20.0 3 pcs\n";
  testFile << "Product3 StoreA 15.0 7 pcs\n";
  testFile.close();

  std::stringstream buffer;
  std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

  searchByShop("test_products.txt", "StoreA");

  std::cout.rdbuf(oldCout);

  std::string output = buffer.str();
  EXPECT_NE(output.find("Product1 StoreA 10 5 pcs"), std::string::npos);
  EXPECT_NE(output.find("Product3 StoreA 15 7 pcs"), std::string::npos);
  EXPECT_EQ(output.find("Product2 StoreB 20 3 pcs"), std::string::npos);

  std::remove("test_products.txt");
}