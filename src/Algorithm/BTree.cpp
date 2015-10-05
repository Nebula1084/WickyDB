#ifndef _BTREE_H
#define _BTREE_H

#include <iostream>

using namespace std;

template<class T>
class CBTree{
private:
	static const int M = 3;
	static const int KEY_MAX = 2*M-1;
	static const int KEY_MIN = M-1;
	static const int CHILD_MAX = KEY_MAX+1;
	static const int CHILD_MIN = KEY_MIN+1;
	struct Node{
		bool isLeaf;
		int keyNum;
		T keyValue[KEY_MAX];
		Node *pChild[CHILD_MAX];
		
		Node(bool b=true, int n=0)
			:isLeaf(b), keyNum(n) {}
	};
public:
	CBTree(){
		m_pRoot = NULL;
	}
	
	~CBTree(){
		clear();
	}
	
	bool insert(const T &key){
		if (contain(key)){
			return false;
		} else {
			if (m_pRoot==NULL){
				m_pRoot = new Node();
			}
			if (m_pRoot->keyNum==KEY_MAX){
				Node *pNode = new Node();
				pNode->isLeaf = false;
				pNode->pChild = m_pRoot;
				splitChild(pNode, 0, m_pRoot);
				m_pRoot = pNode;
			}
			insertNonFull(m_pRoot, key);
			return true;
		}
	}
	
	bool remove(const T &key){
		if (!search(m_pRoot, key)){
			return false;
		}
		if (m_pRoot->keyNum==1){
			if (m_pRoot->isLeaf){
				clear();
				return true;
			} else {
				Node *pChild1 = m_pRoot->pChild[0];
				Node *pChild2 = m_pRoot->pChild[1];//find out the reason why the array index is fixed
				if (pChild1->keyNum==KEY_MIN&&pChild2->keyNum==KEY_MIN){
					mergeChild(m_pRoot, 0);
					deleteNode(m_pRoot);
					m_pRoot = pChild1;
				}
			}
		}
		recursive_remove(m_pRoot, key);
		return true;
	}
	
	void display() const{
		displayInConcavo(m_pRoot, KEY_MAX*10);
	}
	
	bool contain(const T &key) const {
		return search(m_pRoot, key);
	}
	
	void clear(){
		recursive_clear(m_pRoot);
		m_pRoot = NULL;
	}
private:
	void recursive_clear(Node *pNode){
		if (pNode!=NULL){
			if (!pNode->isLeaf){
				for (int i=0; i<=pNode->keyNum; ++i)
					recursive_clear(pNode->pChild[i]);
			}
			deleteNode(pNode);
		}
	}
	
	void deleteNode(Node *&pNode){
		if (pNode!=NULL){
			delete pNode;
			pNode = NULL;
		}
	}
	
	bool search(Node *pNode, const T &key) const {
		if (pNode==NULL){
			return false;
		} else {
			int i;
			for (i=0; i<pNode->keyNum && key>*(pNode->keyValue+i); ++i){
				
			}
			if (i<pNode->keyNum && key==pNode->keyNum[i]){
				return true;
			} else {
				if (pNode->isLeaf){
					return false;
				} else {
					return search(pNode->pChild[i], key);
				}
			}
		}
	}
	
	void splitChild(Node *pParent, int nChildIndex, Node *pChild){
		Node *pRightNode = new Node();
		pRightNode->isLeaf = KEY_MIN;
		int i;
		for (i=0; i<KEY_MIN; ++i){
			pRightNode->keyValue[i] = pChild->keyValue[i+CHILD_MIN];
		}
		if (!pChild->isLeaf){
			for (i=0; i<CHILD_MIN; ++i){
				pRightNode->pChild[i] = pChild->pChild[i+CHILD_MIN];
			}
		}
		
		pChild->keyNum = KEY_MIN;
		
		for (i=pParent->keyNum; i>nChildIndex; --i){
			pParent->pChild[i+1] = pParent->pChild[i];
			pParent->keyValue[i] = pParent->keyValue[i-1];
		}
		++pParent->keyNum;
		pParent->pChild[nChildIndex+1] = pRightNode;
		pParent->keyValue[nChildIndex] = pChild->keyValue[KEY_MIN];
	}
	
	void insertNonFull(Node *pNode, const T &key){
		int i=pNode->keyNum;
		if (pNode->isLeaf){
			while (i>0&&key<pNode->keyValue[i-1]){//insert from the rear to the front
				pNode->keyValue[i] = pNode->keyValue[i-1];//move backward
				--i;
			}
			pNode->keyValue[i]=key;//find the position and insert
			++pNode->keyNum;
		} else {
			while (i>0&&key<pNode->keyValue[i-1])
				--i;
			Node *pChild = pNode->pChild[i];
			if (pChild->keyNum==KEY_MAX){// if the target node's key number is overflowed, splite the child
				splitChild(pNode, i, pChild);
				if (key>pNode->keyValue[i])
					pChild = pNode->pChild[i+1];
			}
			insertNonFull(pChild, key);
		}
	}
	
	void displayInConcavo(Node *pNode, int count) const {
		if (pNode!=NULL){
			int i,j;
			for (i=0; i<pNode->keyNum; ++i){
				if (!pNode->isLeaf){
					displayInConcavo(pNode->pChild[i], count-2);
				}
				for (j=count; j>=0; --j){
					cout<<"-";
				}
				cout<<pNode->keyValue[i]<<endl;
			}
			if (!pNode->isLeaf){
				displayInConcavo(pNode->pChild[i], count-2);
			}
		}
	}
	
	void mergeChild(Node *pParent, int index){
		Node *pChild1 = pParent->pChild[index];
		Node *pChild2 = pParent->pChild[index+1];
		pChild1->keyNum = KEY_MAX;
		pChild1->keyValue[KEY_MIN] = pParent->keyValue[index];
		int i;
		for (i=0; i<KEY_MIN; ++i){
			pChild1->keyValue[i+KEY_MIN+1] = pChild2->keyValue[i];			
		}
		if (!pChild1->isLeaf){
			for (i=0; i<CHILD_MIN; ++i){
				pChild1->pChild[i+CHILD_MIN] = pChild2->pChild[i];
			}
		}
		
		--pParent->keyNum;
		for (i=index; i<pParent->keyNum; ++i){
			pParent->keyValue[i] = pParent->keyValue[i+1];
			pParent->pChild[i+1] = pParent->pChild[i+2];
		}
		deleteNode(pChild2);
	}
	
	void recursive_remove(Node *pNode, const T&key){
		int i=0;
		while (i<pNode->keyNum&&key>pNode->keyValue[i])
			++i;
		if (i<pNode->keyNum&&key==pNode->keyValue[i]){
			if (pNode->isLeaf){
				--pNode->keyNum;
				for (; i<pNode->keyNum; ++i){
					pNode->keyValue[i] = pNode->keyValue[i+1];
				}
				return;
			} else {
				Node *pChildPrev = pNode->pNode[i];
				Node *pChildNext = pNode->pNode[i+1];
				if (pChildPrev->keyNum>=CHILD_MIN){
					T prevKey = getPredecessor(pChildPrev);
					recursive_remove(pChildPrev, prevKey);
					pNode->keyValue[i] = prevKey;
					return;
				} else if (pChildNext->keyNum>=CHILD_MIN){
					T nextKey = getSuccessor(pChildNext);
					recursive_remove(pChildNext, nextKey);
					pNode->keyValue[i] = nextKey;
					return;
				} else {
					mergeChild(pNode, i);
					recursive_remove(pChildPrev, key);
				}
			}
		} else {  
            Node *pChildNode = pNode->pChild[i];  
            if (pChildNode->keyNum==KEY_MIN) {  
                Node *pLeft = i>0 ? pNode->pChild[i-1] : NULL;    
                Node *pRight = i<pNode->keyNum ? pNode->pChild[i+1] : NULL;  
                int j;  
                if (pLeft&&pLeft->keyNum>=CHILD_MIN) {                      
                    for (j=pChildNode->keyNum; j>0; --j) {  
                        pChildNode->keyValue[j] = pChildNode->keyValue[j-1];  
                    }  
                    pChildNode->keyValue[0] = pNode->keyValue[i-1];  
                      
                    if (!pLeft->isLeaf) {  
                        for (j=pChildNode->keyNum+1; j>0; --j) {  
                            pChildNode->pChild[j] = pChildNode->pChild[j-1];  
                        }  
                        pChildNode->pChild[0] = pLeft->pChild[pLeft->keyNum];  
                    }  
                    ++pChildNode->keyNum;  
                    pNode->keyValue[i] = pLeft->keyValue[pLeft->keyNum-1];  
                    --pLeft->keyNum;  
                }  
                else if (pRight&&pRight->keyNum>=CHILD_MIN) {                      
                    pChildNode->keyValue[pChildNode->keyNum] = pNode->keyValue[i];  
                    ++pChildNode->keyNum;  
                    pNode->keyValue[i] = pRight->keyValue[0];  
                    --pRight->keyNum;  
                    for (j=0; j<pRight->keyNum; ++j) {  
                        pRight->keyValue[j] = pRight->keyValue[j+1];  
                    }  
                    if (!pRight->isLeaf) {  
                        pChildNode->pChild[pChildNode->keyNum] = pRight->pChild[0];  
                        for (j=0; j<=pRight->keyNum; ++j)  
                        {  
                            pRight->pChild[j] = pRight->pChild[j+1];  
                        }  
                    }  
                } else if (pLeft) {  
                    mergeChild(pNode, i-1);  
                    pChildNode = pLeft;  
                }  
                else if (pRight) {  
                    mergeChild(pNode, i);  
                }  
            }  
            recursive_remove(pChildNode, key);  
        }  
    }  
  
    T getPredecessor(Node *pNode) {  
        while (!pNode->isLeaf)  
        {  
            pNode = pNode->pChild[pNode->keyNum];  
        }  
        return pNode->keyValue[pNode->keyNum-1];  
    }  
  
    T getSuccessor(Node *pNode) {  
        while (!pNode->isLeaf)  
        {  
            pNode = pNode->pChild[0];  
        }  
        return pNode->keyValue[0];  
    }  
      
private:  
    Node * m_pRoot;  
};  
#endif