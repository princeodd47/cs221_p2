// All list functions will be defined in a class called Book_Inventory and live here.
#include "Book_Inventory.h"

using namespace std;

//--------------------------------------------
// Function: Book_Inventory()
// Purpose: Default Constructor
//--------------------------------------------
Book_Inventory::Book_Inventory()
{

}

//--------------------------------------------
// Function: ~Book_Inventory()
// Purpose: Deconstructor, closes files opened
//      using readInventory()
//--------------------------------------------
Book_Inventory::~Book_Inventory()
{
    m_InFile.close();
}

//--------------------------------------------
// Function: ClearInventory()
// Purpose: 
//--------------------------------------------
void Book_Inventory::ClearInventory()
{
    //TODO: Do cool things here.
}

//--------------------------------------------
// Function: addBook()
// Purpose: 
//--------------------------------------------
bool Book_Inventory::addBook(BookRecord *br)
{
    //TODO: Do cool things here.
    return true;
}

//--------------------------------------------
// Function: searchByStockNumber()
// Purpose: 
//--------------------------------------------
BookRecord *Book_Inventory::searchByStockNumber(long stockNum)
{
    //TODO: Do cool things here.
    BookRecord *br = new BookRecord();
    return br;
}

//--------------------------------------------
// Function: searchByClassification()
// Purpose: 
//--------------------------------------------
void Book_Inventory::searchByClassification(int cl)
{
    //TODO: Do cool things here.
}

//--------------------------------------------
// Function: searchBycost()
// Purpose: 
//--------------------------------------------
void Book_Inventory::searchByCost(double min, double max)
{
    //TODO: Do cool things here.
}

//--------------------------------------------
// Function: getNumberInStock()
// Purpose: 
//--------------------------------------------
int Book_Inventory::getNumberInStock(long sn)
{
    //TODO: Do cool things here.
    int numInStock = 0;
    return numInStock;
}

//--------------------------------------------
// Function: printInventory()
// Purpose: 
//--------------------------------------------
void Book_Inventory::printInventory()
{
    //TODO: Do cool things here.
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

        tempBr->printRecord();
    }
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
