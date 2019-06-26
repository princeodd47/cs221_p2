//--------------------------------------------------------
// File BookRecord.h
// Purpose: Define inventory records
//--------------------------------------------------------
#ifndef RECORD_H
#define RECORD_H
#endif

class BookRecord {
    private:
        char m_sTitle[128];
        long m_lStockNum;
        int m_iClassification;
        double m_dCost;
        int m_iCount;
    public:
        BookRecord();
        BookRecord(const char *title, long sn, int cl, double cost);
        ~BookRecord();
        void getTitle(char *title);
        void setTitle(const char *title);
        long getStockNum();
        void setStockNum(long sn);
        void getClassification(int& cl);
        void setClassification(int cl);
        void getCost(double *c);
        void setCost(double c);
        int getNumberInStock();
        void setNumberInStock(int count);
        void printRecord();
};
