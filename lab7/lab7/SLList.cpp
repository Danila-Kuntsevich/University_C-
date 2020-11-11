#include "SLList.h"

using namespace std;

int SLList::GetData() const {
	return m_data;
}

SLList::SLList(int data)
{
	this->m_data = data;
}

SLList::~SLList()
{
	if (this->hasNext()) {
		delete this->next();
	}
}

void SLList::setData(int data) {
	m_data = data;
}

SLList* SLList::next() const{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

SLList* SLList::addElement(int data)
{
	if (!hasNext()){
		return m_nextElem = new SLList(data);
	}
	return nullptr;
}

//void SLList::removeNext()
//{
//	while (this->hasNext()) {
//		SLList* current = this->next();
//		while (current->hasNext()) {
//			current = current->next();
//		};
//		delete current;
//	};
//}

void SLList::removeNext()
{
	auto tmp = this->next()->m_nextElem;
	this->next()->m_nextElem = nullptr;
	delete this->next();
	this->m_nextElem = tmp;
}