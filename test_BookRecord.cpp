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

    if(strcmp(tempTitle, "") != 0 ||
       br->getStockNum() != 0 ||
       br->getClassification() != 0 ||
       br->getCost() != 0.00 ||
       br->getNumberInStock() != 0 ||
       br->getNext() != NULL)
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
    double expected_cost = 3.45;
    if(br->getCost() == expected_cost)
    {
        cout << "getCost test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "getCost test " << fail_color << "failed: " << def_color;
        cout << "cost should = " << expected_cost << ", cost = " << br->getCost() << endl;
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
    char tempTitle[32];
    strcpy(tempTitle , "foo bar");

    BookRecord *br = new BookRecord(tempTitle, 123456, 5, 3.45);
    cout << "test_printRecord needs to be checked " << warn_color << "manually" << def_color << endl;

    br->printRecord();
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
}

void test_readInventory()
{
    Book_Inventory *testInv = new Book_Inventory();
    testInv->readInventory("BookData.txt");
    cout << "searchByStockNumber test " << fail_color << "no assertions" << def_color << endl;
}

void test_searchByStockNumber()
{
    Book_Inventory *testInv = new Book_Inventory();
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    testInv->addBook(br);
    long testStockNum = 123456;
    BookRecord *testBr = new BookRecord();

    testBr = testInv->searchByStockNumber(testStockNum);

    if((testBr != NULL) && (testBr->getStockNum() == 123456) && (testBr->getNext() == NULL))
    {
        cout << "searchByStockNumber test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "searchByStockNumber test " << fail_color << "failed" << def_color << endl;
    }
}

void test_searchByStockNumberNoneFound()
{
    Book_Inventory *testInv = new Book_Inventory();
    BookRecord *br = new BookRecord("foo bar", 123456, 1, 3.45);
    testInv->addBook(br);
    long testStockNum = 12345;
    BookRecord *testBr = new BookRecord();

    testBr = testInv->searchByStockNumber(testStockNum);

    if(testBr == NULL)
    {
        cout << "searchByStockNumberNoneFound test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "searchByStockNumberNoneFound test " << fail_color << "failed" << def_color << endl;
    }
}

void test_addBookToEmptyList()
{

    Book_Inventory *testInv = new Book_Inventory();
    BookRecord *testBr = new BookRecord("foo", 123456, 5, 3.45);
    testInv->addBook(testBr);
    
    testBr = testInv->searchByStockNumber(123456);
    if(testBr->getNext() == NULL)
    {
        cout << "addBookToEmptyList test " << pass_color << "passed" << def_color << endl;
    } else {
        cout << "addBookToEmptyList test " << fail_color << "failed" << def_color << endl;
    }
}

void test_addBookInOrder()
{
    Book_Inventory *testInv = new Book_Inventory();
    BookRecord *br_1 = new BookRecord("foo", 123456, 5, 3.45);
    BookRecord *br_2 = new BookRecord("bar", 654321, 1, 2.12);
    BookRecord *br_3 = new BookRecord("baz", 554321, 2, 1.12);
    BookRecord *br_4 = new BookRecord("ham", 254321, 3, 0.12);
    BookRecord *br_5 = new BookRecord("spam", 754321, 4, 7.12);
    BookRecord *br_6 = new BookRecord("eggs", 114321, 5, 6.12);
    testInv->addBook(br_1);
    testInv->addBook(br_2);
    testInv->addBook(br_3);
    testInv->addBook(br_4);
    testInv->addBook(br_5);
    testInv->addBook(br_6);

    BookRecord *testBr = new BookRecord();
    BookRecord *nextBr = new BookRecord();
    testBr = testInv->searchByStockNumber(114321);
    nextBr = testBr->getNext();
    // searchbyStockNumber sets next to NULL, which is why this fails
    if(nextBr == NULL) { cout << "nextBR is NULL" << endl; }
    //cout << "testBr->getStockNum()=" << testBr->getStockNum() << endl;
    //cout << "nextBr->getStockNum()=" << nextBr->getStockNum() << endl;
    int recordCount = 1;

    while(nextBr != NULL) 
    {
        long curStockNum = testBr->getStockNum();
        long nextStockNum = nextBr->getStockNum();
        if(curStockNum > nextStockNum)
        {
            cout << "addBookInOrder test " << fail_color << "failed" << def_color << endl;
            cout << "\t" << curStockNum << " > " << nextStockNum << endl;
            break;
        }
        else
        {
            nextBr = nextBr->getNext();
            testBr = nextBr;
            cout << "recordCount=" << recordCount << endl;
            recordCount++;
        }
    }
    if(recordCount == 6)
    {
        cout << "addBookInOrder test " << pass_color << "pass" << def_color << endl;
    }
    else
    {
        cout << "addBookInOrder test " << fail_color << "failed" << def_color << endl;
        cout << "\t" << "recordCount = " << recordCount << " and should = 6" << endl;
    }
}

void test_printInventory()
{
    cout << "test_printInventory needs to be checked " << warn_color << "manually" << def_color << endl;
    Book_Inventory *testInv = new Book_Inventory();
    BookRecord *br_1 = new BookRecord("foo", 123456, 5, 3.45);
    BookRecord *br_2 = new BookRecord("bar", 654321, 1, 2.12);
    BookRecord *br_3 = new BookRecord("baz", 554321, 2, 1.12);
    BookRecord *br_4 = new BookRecord("ham", 254321, 3, 0.12);
    BookRecord *br_5 = new BookRecord("spam", 754321, 4, 7.12);
    BookRecord *br_6 = new BookRecord("eggs", 114321, 5, 6.12);
    testInv->addBook(br_1);
    testInv->addBook(br_2);
    testInv->addBook(br_3);
    testInv->addBook(br_4);
    testInv->addBook(br_5);
    testInv->addBook(br_6);

    testInv->printInventory();
}

int main()
{
    cout << "BookRecord Tests" << endl;
    test_BookRecordDefault();
    test_getTitle();
    test_setTitle();
    test_getStockNum();
    test_setStockNum();
    test_getClassification();
    test_setClassification();
    test_getCost();
    test_setCost();
    test_getNumberInStock();
    test_setNumberInStock();
    test_printRecord();
    test_setNext_getNext();
    cout << endl;

    cout << "Book_InventoryTests" << endl;
    test_readInventory();
    test_searchByStockNumber();
    test_searchByStockNumberNoneFound();
    test_addBookToEmptyList();
    // How to test this?
    //test_addBookInOrder();
    test_printInventory();

    return 0;
}
