#ifndef SLLIST_H
#define SLLIST_H

using namespace std;

class SLList
{
public:
	void setData(int data);
	int GetData() const;
	SLList* next() const;
	bool hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	~SLList();

private:
	SLList(int);
	SLList* m_nextElem = nullptr;
	int m_data;
};

#endif // !SLLIST_H


