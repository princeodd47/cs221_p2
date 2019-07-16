
/*******************************************************************
*   Book_Inventory.h
*   Steven Powell
*   Programming Assignment 2 - Book Inventory
*   
*   This program is entirely my own work
*******************************************************************/
//#pragma once

#include<iostream>  // This header lets you use cout and cin
#include<fstream>   // This header gives you all the file I/O functions
#include<string.h>
#include<stdlib.h>
#include "BookRecord.h"

using namespace std; // This command lets you use all the I/O function and include headers w/o the ".h"

class Book_Inventory
{
    private:
        BookRecord     *m_pHead;                		// Pointer to the head of the list
        ifstream       m_InFile;                		// File containing the inventory

    public:
        // Class constructor
        Book_Inventory();
        // Class destructor. Must free all list memory
        ~Book_Inventory();
        // Remove all items from the list
        void ClearInventory();
        // Read inventory file and build the list
        bool readInventory(const char *filename);
        // Add the given book to the list 
        bool addBook(BookRecord *br);
        // Remove a book from the list or print message if not found
        BookRecord *removeBook(long stockNum);
        // Search by stock number return pointer to node or NULL if not found
        BookRecord *searchByStockNumber(long stockNum);
        // Search for all books given classification, print all data
        void searchByClassification(int cl);
        // Search for all books within the given cost range
        void searchByCost(double min, double max);
        // Get number of books in stock for the given stock number 
        int getNumberInStock(long sn);
        // Print all information on all books in the inventory.
        void printInventory();
		void copyRecord(BookRecord *sourceBr, BookRecord *targetBr);
    private:
        // read next line from a file
        bool getNextLine(char *line, int lineLen);
};
