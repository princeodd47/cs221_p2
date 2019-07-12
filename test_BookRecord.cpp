#include "Book_Inventory.h"
#include "colormod.h" // namespace Color
#include <cstring>
#include <iostream>
using namespace std;

Color::Modifier def_color(Color::FG_DEFAULT);
Color::Modifier fail_color(Color::FG_RED);
Color::Modifier pass_color(Color::FG_GREEN);
Color::Modifier warn_color(Color::FG_BLUE);

void test_BookRecordDefault()
{
    BookRecord *br = new BookRecord();
    char tempTitle[32];
    br->getTitle(tempTitle);

    if(strcmp(tempTitle, "") != 0 ||
       br->getStockNum() != 0 ||
       br->getClassification() != 0 ||
       br->getCost() != 0.00 ||
       br->getNumberInStock() != 0 ||
       br->getNext() != NULL)
    {
        cout << "BookRecordDefault cosntructor test " << fail_color << "failed" << def_color << endl;
    }
    else
    {
        cout << "BookRecordDefault cosntructor test " << pass_color << "passed" << def_color << endl;
    }

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
}

void test_getCost()
{
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    double expected_cost = 3.45;
    if(br->getCost() == expected_cost)
    {
        cout << "getCost test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getCost test " << fail_color << "failed: " << def_color;
        cout << "cost should = " << expected_cost << ", cost = " << br->getCost() << endl;
    }

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
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

    br = NULL;
    delete br;
}

void test_printRecord()
{
    char tempTitle[32];
    strcpy(tempTitle , "foo bar");

    BookRecord *br = new BookRecord(tempTitle, 123456, 5, 3.45);
    cout << "test_printRecord needs to be checked " << warn_color << "manually" << def_color << endl;

    br->printRecord();

    br = NULL;
    delete br;
}

void test_setNext_getNext()
{
    
    BookRecord *br_1 = new BookRecord("foo", 123456, 5, 3.45);
    BookRecord *br_2 = new BookRecord("bar", 654321, 1, 2.12);
    br_1->setNext(br_2);
    BookRecord *test_br = br_1->getNext();

    char tempTitle[32];
    test_br->getTitle(tempTitle);
    if(strcmp(tempTitle, "bar") == 0)
    {
        cout << "setNext_getNext test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "setNext_getNext test " << fail_color << "failed" << def_color << endl;
    }

    br_1 = NULL;
    delete br_1;
    br_2 = NULL;
    delete br_2;
}

void test_readInventory()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_readInventory needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "Expected output: 6 records and no duplicates" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");
    testInv->printInventory();
    cout << endl;

    delete testInv;
    testInv = NULL;
}

void test_searchByStockNumber()
{
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");
    long testStockNum = 2345;
    BookRecord *testBr = new BookRecord();

    testBr = testInv->searchByStockNumber(testStockNum);

    if((testBr != NULL) && (testBr->getStockNum() == 2345))
    {
        cout << "searchByStockNumber test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "searchByStockNumber test " << fail_color << "failed" << def_color << endl;
    }
    delete testBr;
    testBr = NULL;
    delete testInv;
    testInv = NULL;
}

void test_searchByStockNumberNoneFound()
{
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");
    long testStockNum = 12345;
    BookRecord *testBr = new BookRecord();

    testBr = testInv->searchByStockNumber(testStockNum);

    if(testBr == NULL)
    {
        cout << "searchByStockNumberNoneFound test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "searchByStockNumberNoneFound test " << fail_color << "failed" << def_color << endl;
    }
    delete testBr;
    testBr = NULL;
    delete testInv;
    testInv = NULL;
}

void test_removeBook()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_removeBook needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output length 3 and not 1234, 9876, 4567" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    testInv->removeBook(1234);
    BookRecord *testBr = testInv->searchByStockNumber(1234);
    if(testBr != NULL)
    {
        cout << "removeBook test " << fail_color << "failed" << def_color << endl;
    }
    testInv->removeBook(9876);
    testBr = testInv->searchByStockNumber(9876);
    if(testBr != NULL)
    {
        cout << "removeBook test " << fail_color << "failed" << def_color << endl;
    }
    testInv->removeBook(4567);
    testBr = testInv->searchByStockNumber(4567);
    if(testBr != NULL)
    {
        cout << "removeBook test " << fail_color << "failed" << def_color << endl;
    }
    testInv->printInventory();

    delete testInv;
    testInv = NULL;
    delete testBr;
    testBr = NULL;
}

void test_removeBookNotFound()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_removeBookNotFound" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    BookRecord *testBr = testInv->removeBook(5);
    if(testBr == NULL)
    {
        cout << "removeBookNotFound test " << pass_color << "passed" << def_color << endl;
    }
    else
    {
        cout << "removeBookNotFound test " << fail_color << "failed" << def_color << endl;
    }

    delete testInv;
    testInv = NULL;
    delete testBr;
    testBr = NULL;
}

void test_inventoryGetNumberInStock()
{
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    BookRecord *testBr = testInv->searchByStockNumber(5678);

    if(testBr->getNumberInStock() == 25)
    {
        cout << "inventoryGetNumberInStock test " << pass_color << "passed" << def_color << endl;
    }
    else
    {
        cout << "inventoryGetNumberInStock test " << fail_color << "failed" << def_color << endl;
    }

    delete testInv;
    testInv = NULL;
    delete testBr;
    testBr = NULL;
}

void test_searchByClassification()
{
    cout << "===================" << endl;
    cout << "test_searchByClassification needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output count should be 3" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();

    testInv->readInventory("BookData.txt");
    testInv->searchByClassification(613);

    delete testInv;
    testInv = NULL;
}

void test_searchByClassificationNoneFound()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByClassificationNoneFound needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output count should be 0" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    testInv->searchByClassification(55);

    delete testInv;
    testInv = NULL;
}

void test_searchByCost()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByCost needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output count is 2, with cost between 10.00 to 20.00" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    testInv->searchByCost(10.00, 20.00);

    delete testInv;
    testInv = NULL;
}

void test_searchByCostNoneFound()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_searchByCostNoneFound needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output count should be 0" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    testInv->searchByCost(8.00, 9.00);
    cout << endl;

    delete testInv;
    testInv = NULL;
}

void test_ClearInventory()
{
    cout << endl;
    cout << "===================" << endl;
    cout << "test_ClearInventory needs to be checked " << warn_color << "manually" << def_color << endl;
    cout << "expected output count should be 0" << endl;
    cout << "===================" << endl;
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");

    testInv->ClearInventory();
    testInv->printInventory();

    delete testInv;
    testInv = NULL;
}

int main()
{
    //cout << "BookRecord Tests" << endl;
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
    //test_printRecord();
    //test_setNext_getNext();
    //cout << endl;

    cout << "Book_InventoryTests" << endl;
    //auto tests
    test_searchByStockNumber();
    test_searchByStockNumberNoneFound();
    test_inventoryGetNumberInStock();
    test_removeBookNotFound();
    //manual tests
    test_readInventory();
    test_searchByClassification();
    test_searchByClassificationNoneFound();
    test_removeBook();
    test_searchByCost();
    test_searchByCostNoneFound();
    //test_ClearInventory();

    return 0;
}
