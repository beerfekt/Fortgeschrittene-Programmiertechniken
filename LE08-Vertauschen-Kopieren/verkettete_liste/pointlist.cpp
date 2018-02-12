#include "pointlist.h"
#include <assert.h>


//-------------- PointListNode - Hilfsklasse header ------------------

class PointListNode {


public:

    explicit PointListNode(const Point& point);
    const Point point;
    std::unique_ptr<PointListNode> next = nullptr;
};

//-------------- PointListNode - Hilfsklasse Implementierungsdatei ------------------

PointListNode::PointListNode(const Point& point):
    point(point)
{}


//---------------------   PointList    --------------------------

PointList::PointList(){};  //wegen vorwärtsdeklaration
PointList::~PointList(){}; //  "        "
PointList& PointList::operator+=(const Point& point){

    // PointListNode* newNode = new PointListNode(point);
     //auto newNode = std::make_unique<PointListNode>(point);

    if (root){
       //wenn anfangspunkt gesetzt -> kein nullptr

       PointListNode* node = root.get();
       assert(node);
       while (node->next){
           node = node->next.get();
       }
       assert(!node->next);
       node->next = std::make_unique<PointListNode>(point);

    } else {
        //wenn kein anfang -> nullptr
        assert(!root);
        root = std::make_unique<PointListNode>(point);
    }
    ++sizeOf;
    return *this;
}//operator +=




size_t PointList::size() const{

 return sizeOf;

 /*
  size_t size = 0;
  const PointListNode* node = root.get(); //der kann bleiben da er in der while die eigentümerschaft behält

  while (node){
    ++size;
    node = node->next.get();
  }

  return size;
*/
}//size





const Point& PointList::first()const{
       assert(root);
       return root.get()->point;
}


void PointList::deleteFirst(){
    assert(root);
    //root = move(root->next); //Warum geht das nicht? evt. leiche im speicher??
    std::unique_ptr<PointListNode> oldRoot = std::move(root); //eigentümerschaft von root an oldroot
    root = std::move(oldRoot->next);  //eg von next kommt nach root
} //oldroot wird gelöscht -> Blockende



//SWAP .................................................

void PointList::swap(PointList& b){
    using std::swap;
    swap(root, b.root);
    swap(sizeOf, b.sizeOf);
}

      //verschieben ------

PointList::PointList(PointList&& other) {
    swap(other); //valider zustand zu move -> destruktor wird aufgerufen - keine leiche mehr im keller
}


PointList& PointList::operator=(PointList&& other){
      swap(other);    // elementfunktion tauscht mit anderem ,
      return *this;   // dies wird zurückgegeben
}
     //-------------------







//Freie Funktionen der Klasse Point -----------------------------------------------
void swap(PointList& a, PointList& b){
    a.swap(b);  //ruft elementfunktion swap auf
};



//..................................................

