#include "Book_Inventory.h"
#include "colormod.h" // namespace Color
#include <cstring>
#include <iostream>
using namespace std;

Color::Modifier def_color(Color::FG_DEFAULT);
Color::Modifier fail_color(Color::FG_RED);
Color::Modifier pass_color(Color::FG_GREEN);
Color::Modifier warn_color(Color::FG_BLUE);

int test_BookRecordDefault()
{
    BookRecord *br = new BookRecord();
    char tempTitle[32];
    br->getTitle(tempTitle);

    if(strcmp(tempTitle, "") != 0 || br->getStockNum() != 0 || br->getClassification() != 0 || br->getCost() != 0.00 || br->getNumberInStock() != 0)
    {
        cout << "BookRecordDefault cosntructor test " << fail_color << "failed" << def_color << endl;
        return 0;
    }
    cout << "BookRecordDefault cosntructor test " << pass_color << "passed" << def_color << endl;
    return 0;
}

void test_getTitle()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    char tempTitle[32];
    br->getTitle(tempTitle);
    if(strcmp(tempTitle, "foo bar") == 0)
    {
        cout << "getTitle test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getTitle test " << fail_color << "failed" << def_color << endl;
    }
}

void test_setTitle()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    char tempTitle[32];
    br->setTitle("baz quz");
    br->getTitle(tempTitle);
    if(strcmp(tempTitle, "baz quz") == 0)
    {
        cout << "setTitle test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "setTitle test " << fail_color << "failed" << def_color << endl;
    }
}

void test_getStockNum()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    if(br->getStockNum() == 123456)
    {
        cout << "getStockNum test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getStockNum test " << fail_color << "failed" << def_color << endl;
    }
}

void test_setStockNum()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    br->setStockNum(789012);
    if(br->getStockNum() == 789012)
    {
        cout << "setStockNum test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "setStockNum test " << fail_color << "failed" << def_color << endl;
    }
}

void test_getClassification()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    if(br->getClassification() == 1)
    {
        cout << "getClassification test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getClassification test " << fail_color << "failed" << def_color << endl;
    }
}

void test_setClassification()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    br->setClassification(4);
    if(br->getClassification() == 4)
    {
        cout << "getClassification test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getClassification test " << fail_color << "failed" << def_color << endl;
    }
}

void test_getCost()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    double cost;
    double expected_cost = 3.45;
    if(br->getCost() == expected_cost)
    {
        cout << "getCost test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getCost test " << fail_color << "failed: " << def_color;
        cout << "cost should = " << expected_cost << ", cost = " << cost << endl;
    }
}

void test_setCost()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    double cost = 54.54;
    br->setCost(cost);
    if(cost == 54.54)
    {
        cout << "setCost test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "setCost test " << fail_color << "failed" << def_color << endl;
    }
}

void test_getNumberInStock()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 5, 3.45);
    if(br->getNumberInStock() == 1)
    {
        cout << "getNumberInStock test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getNumberInStock test " << fail_color << "failed" << def_color << endl;
    }
}

void test_setNumberInStock()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 5, 3.45);
    br->setNumberInStock(14);
    if(br->getNumberInStock() == 14)
    {
        cout << "setNumberInStock test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "setNumberInStock test " << fail_color << "failed" << def_color << endl;
    }
}

void test_printRecord()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 5, 3.45);
    cout << "test_printRecord needs to be checked " << warn_color << "manually" << def_color << endl;
    br->printRecord();
}

int main()
{

    //test_BookRecordDefault();
    //test_getTitle();
    //test_setTitle();
    //test_getStockNum();
    //test_setStockNum();
    //test_getClassification();
    //test_setClassification();
    //test_getCost();
    //test_setCost();
    //test_getNumberInStock();
    //test_setNumberInStock();
    test_printRecord();

    return 0;
}
