// All list functions will be defined in a class called Book_Inventory and live here.
#include "Book_Inventory.h"

using namespace std;

//--------------------------------------------
// Function: Book_Inventory()
// Purpose: Default Constructor
//--------------------------------------------
Book_Inventory::Book_Inventory()
{
    m_pHead = NULL;
}

//--------------------------------------------
// Function: ~Book_Inventory()
// Purpose: Deconstructor, closes files opened
//      using readInventory()
//--------------------------------------------
Book_Inventory::~Book_Inventory()
{
    ClearInventory();
    m_pHead = NULL;
}

//--------------------------------------------
// Function: ClearInventory()
// Purpose: Remove all items from the list.
//--------------------------------------------
void Book_Inventory::ClearInventory()
{
    BookRecord *tempBr = m_pHead;
    while(tempBr != NULL)
    {
        m_pHead = m_pHead->getNext();
        tempBr = NULL;
        //tempBr = m_pHead;
        delete tempBr;
    }
}

//--------------------------------------------
// Function: addBook()
// Purpose: 
//--------------------------------------------
bool Book_Inventory::addBook(BookRecord *br)
{
    if(m_pHead == NULL)
    {
        m_pHead = br;
        return true;
    }

    BookRecord *curBr = m_pHead;
    BookRecord *prevBr = NULL;

    while((curBr != NULL) && (curBr->getStockNum() < br->getStockNum()))
    {
        prevBr = curBr;
        curBr = curBr->getNext();
    }

    if(prevBr == NULL)
    {
        br->setNext(m_pHead);
        m_pHead = br;
    }
    else if((curBr != NULL) && (br->getStockNum() == curBr->getStockNum()))
    {
        curBr->setNumberInStock(curBr->getNumberInStock() + br->getNumberInStock());
    }
    else
    {
        prevBr->setNext(br);
        br->setNext(curBr);
    }

    curBr = NULL;
    prevBr = NULL;

    return true;
}

//--------------------------------------------
//Function: removeBook(long stockNum)
// Purpose: Search by stock number return pointer to node or NULL if not found
//--------------------------------------------
BookRecord *Book_Inventory::removeBook(long stockNum)
{
    if(m_pHead == NULL)
    {
        return NULL;
    }

    BookRecord *tempBr = m_pHead;
    BookRecord *parentBr = NULL;
    BookRecord *returnBr = NULL;
    while((tempBr != NULL) && (tempBr->getStockNum() != stockNum))
    {
        parentBr = tempBr;
        tempBr = tempBr->getNext();
    }

    if(tempBr == NULL)
    {
        return NULL;
    }
    else if(parentBr == NULL)
    {
        m_pHead = m_pHead->getNext();
        returnBr = tempBr;
        delete tempBr;
        tempBr = NULL;
        return returnBr;
    }
    else
    {
        parentBr->setNext(tempBr->getNext());
        returnBr = tempBr;
        delete tempBr;
        tempBr = NULL;
        return returnBr;
    }
    return NULL;
}



//--------------------------------------------
// Function: searchByStockNumber()
// Purpose: Search by stock number return pointer to node or NULL if not found
//--------------------------------------------
BookRecord *Book_Inventory::searchByStockNumber(long stockNum)
{
    BookRecord *tempBr = m_pHead;
    //tempBr = m_pHead;
    while((tempBr != NULL) && (tempBr->getStockNum() != stockNum))
    {
        tempBr = tempBr->getNext();
    }

    if(tempBr == NULL)
    {
        return NULL;
    }
    else
    {
        BookRecord *retBr = tempBr;
        retBr->setNext(NULL);
        return retBr;
    }
}

//--------------------------------------------
// Function: searchByClassification()
// Purpose: Search for all books given classification, print all data
//--------------------------------------------
void Book_Inventory::searchByClassification(int cl)
{
    int counter = 0;
    BookRecord *tempBr;
    tempBr = m_pHead;
    while(tempBr != NULL)
    {
        if(tempBr->getClassification() == cl)
        {
            counter++;
            tempBr->printRecord();
        }
        tempBr = tempBr->getNext();
    }
    if(counter == 0)
    {
        cout << "No records found with classification " << cl << endl;
    }
}

//--------------------------------------------
// Function: searchBycost()
// Purpose: 
//--------------------------------------------
void Book_Inventory::searchByCost(double min, double max)
{
    int counter = 0;
    double cost = 0.00;
    BookRecord *tempBr = new BookRecord;
    tempBr = m_pHead;
    while(tempBr != NULL)
    {
        cost = tempBr->getCost();
        tempBr->printRecord();
        if((cost >= min) && (cost <= max))
        {
            counter++;
            tempBr->printRecord();
        }
        tempBr = tempBr->getNext();
    }
    if(counter == 0)
    {
        cout << "No records found with cost range of "
             << min
             << " and "
             << max
             << endl;
    }
    delete tempBr;
    tempBr = NULL;
}

//--------------------------------------------
// Function: getNumberInStock()
// Purpose: 
//--------------------------------------------
int Book_Inventory::getNumberInStock(long sn)
{
    BookRecord *tempBr = searchByStockNumber(sn);
    if(tempBr == NULL)
    {
        cout << "Record not found for " << sn << endl;
        return 0;
    }
    else
    {
        return tempBr->getNumberInStock();
    }
}

//--------------------------------------------
// Function: printInventory()
// Purpose: 
//--------------------------------------------
void Book_Inventory::printInventory()
{
    if(m_pHead != NULL)
    {
        BookRecord *tempBr = m_pHead;
        while(tempBr != NULL)
        {
            tempBr->printRecord();
            tempBr = tempBr->getNext();
        }
        tempBr = NULL;
        delete tempBr;
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

//--------------------------------------------
// Function: readInventory()
// Purpose: Read the inventory data file and
//		build the list.
// Returns: True if successful read
//--------------------------------------------
bool Book_Inventory::readInventory(const char *filename)
{
     char     line[128];
     int      numBooks;
     // define other variables here as needed

    m_InFile.open(filename, ifstream::in);
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file" << filename << "\nProgram terminating...\n";
        return false;
    }
    // Read number of books
    getNextLine(line, 128);
    numBooks = atoi(line);

    /*
     * Remaining lines will give the stock number, Title, classification, 
     * cost and number in stock
     */
    for(int i=0; i<numBooks; i++)
    {
        BookRecord *tempBr = new BookRecord();

        // stockNum
        getNextLine(line, 128);
        tempBr->setStockNum(atol(line));

        // title
        getNextLine(line, 128);
        char tempTitle[128];
        strcpy(tempTitle, line);
        tempBr->setTitle(tempTitle);

        // classification
        getNextLine(line, 128);
        tempBr->setClassification(atoi(line));

        // cost
        getNextLine(line, 128);
        tempBr->setCost(atof(line));

        // numInStock
        getNextLine(line, 128);
        tempBr->setNumberInStock(atoi(line));

        addBook(tempBr);
    }
    m_InFile.close();
    return true;
}

//--------------------------------------------
// Function: getNextLine()
// Purpose:  Read a line from a data file.
//   The next non-comment line read from file
//   is stored in line char array.
//   An empty string is stored if the end of
//   file is reached.
// Returns: bool - true if a valid line was
//   read, false if end of file is reached.
//--------------------------------------------
bool Book_Inventory::getNextLine(char *line, int lineLen)
{
    int    done = false;
    while(!done)
    {
        m_InFile.getline(line, lineLen);

        if(m_InFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else // No valid line read, meaning we reached the end of file
        {
            strcpy(line, ""); // Copy empty string into line as sentinal value
            return false;
        }
    } // end while
    return false; // Cannot reach this point but include a return to avoid compiler warning
                  //   that not all paths return a value.
}
