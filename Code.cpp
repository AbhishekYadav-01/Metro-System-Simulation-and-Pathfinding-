#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

// Forward declarations
class MetroStop;
class MetroLine;
class AVLNode;

// MetroStop class
class MetroStop
{
private:
    std::string stopName;
    MetroStop *nextStop;
    MetroStop *prevStop;
    MetroLine *line;
    int fare;

public:
    MetroStop(std::string name, MetroLine *metroLine, int fare);

    // Getter methods
    std::string getStopName() const;
    MetroStop *getNextStop() const;
    MetroStop *getPrevStop() const;
    MetroLine *getLine() const;
    int getFare() const;

    // Setter methods
    void setNextStop(MetroStop *next);
    void setPrevStop(MetroStop *prev);
    void setLine(MetroLine *ml);
};

MetroStop::MetroStop(std::string name, MetroLine *metroLine, int fare)
{
    stopName = name;
    nextStop = nullptr;
    prevStop = nullptr;
    line = metroLine;
    this->fare = fare;
}

std::string MetroStop::getStopName() const
{
    return stopName;
}

MetroStop *MetroStop::getNextStop() const
{
    return nextStop;
}

MetroStop *MetroStop::getPrevStop() const
{
    return prevStop;
}
void MetroStop::setLine(MetroLine *ml)
{
    line = ml;
}
MetroLine *MetroStop::getLine() const
{
    return line;
}

int MetroStop::getFare() const
{
    return fare;
}

void MetroStop::setNextStop(MetroStop *next)
{
    nextStop = next;
}

void MetroStop::setPrevStop(MetroStop *prev)
{
    prevStop = prev;
}

// MetroLine class
class MetroLine
{
private:
    std::string lineName;
    MetroStop *node;

public:
    MetroLine(std::string name);

    // Getter methods
    std::string getLineName() const;
    MetroStop *getNode() const;

    // Setter methods
    void setNode(MetroStop *node);

    void populateLine(std::string filename);

    // helper function
    void printLine() const;
    int getTotalStops() const;
};


MetroLine::MetroLine(std::string name)
{
    lineName = name;
    node = nullptr;
}

std::string MetroLine::getLineName() const
{
    return lineName;
}

MetroStop *MetroLine::getNode() const
{
    return node;
}

void MetroLine::setNode(MetroStop *node)
{
    this->node = node;
}

void MetroLine::printLine() const
{
    MetroStop *stop = node;
    while (stop != nullptr)
    {
        cout << stop->getStopName() << endl;
        stop = stop->getNextStop();
    }
}

int MetroLine::getTotalStops() const
{
    int totalstops = 0;
    MetroStop *ptr = this->getNode();
    while (!NULL)
    {
        if (ptr != 0)
        {
            totalstops++;
            ptr = ptr->getNextStop();
        }
        else
        {
            return totalstops;
        }
    }
}

void MetroLine::populateLine(std::string filename) {
    // Read the file and populate the line
    std::ifstream inputFile(filename);
    std::string line;

    while(std::getline(inputFile, line)){
        
        size_t lps = line.find_last_of(" ");

        int fare = std::stoi(line.substr(lps + 1,line.find_last_of(",")));
        std::string stopName = line.substr(0,lps);
        MetroStop* newStop = new MetroStop(stopName,this,fare);
        if(node==nullptr){
            node = newStop;
            
           
        } else {
             MetroStop* lastStop = node;
            for( ;lastStop->getNextStop() != nullptr;){
                lastStop = lastStop->getNextStop();
            }
            lastStop->setNextStop(newStop);
            newStop->setPrevStop(lastStop);
        }
    }

}

class AVLNode
{
private:
    std::string stopName;
    std::vector<MetroStop *> stops;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;

public:
    AVLNode(std::string name);

    // Getter methods
    std::string getStopName() const;
    const std::vector<MetroStop *> &getStops() const;
    AVLNode *getLeft() const;
    AVLNode *getRight() const;
    AVLNode *getParent() const;

    // Setter methods
    void addMetroStop(MetroStop *metroStop);
    void setLeft(AVLNode *left);
    void setRight(AVLNode *right);
    void setParent(AVLNode *parent);
};

class AVLTree
{
    // Define your AVLTree implementation here.
private:
    AVLNode *root;

public:
    // getter methods
    AVLNode *getRoot() const;

    // setter methods
    void setRoot(AVLNode *root);

    // helper functions
    int height(AVLNode *node);
    int balanceFactor(AVLNode *node);
    void rotateLeft(AVLNode *node);
    void rotateRight(AVLNode *node);
    void balance(AVLNode *node);
    int stringCompare(string s1, string s2);
    void insert(AVLNode *node, MetroStop *metroStop);
    void populateTree(MetroLine *metroLine);
    void inOrderTraversal(AVLNode *node);
    int getTotalNodes(AVLNode *node);
    AVLNode *searchStop(string stopName);
     AVLNode *searching(string stopName);
   
};

AVLNode::AVLNode(std::string name)
{
    stopName = name;
    left = nullptr;
    right = nullptr;
    parent = NULL;
}

std::string AVLNode::getStopName() const
{
    return stopName;
}

const std::vector<MetroStop *> &AVLNode::getStops() const
{
    return stops;
}

AVLNode *AVLNode::getLeft() const
{
    return left;
}

AVLNode *AVLNode::getRight() const
{
    return right;
}

AVLNode *AVLNode::getParent() const
{
    return parent;
}

void AVLNode::setLeft(AVLNode *left)
{
    this->left = left;
}

void AVLNode::setRight(AVLNode *right)
{
    this->right = right;
}

void AVLNode::setParent(AVLNode *parent)
{
    this->parent = parent;
}

void AVLNode::addMetroStop(MetroStop *metroStop)
{
    stops.push_back(metroStop);
}

AVLNode *AVLTree::getRoot() const
{
    return root;
}

void AVLTree::setRoot(AVLNode *root)
{
    this->root = root;
}

int AVLTree::height(AVLNode *node)
{
    if (node == nullptr)
    {
        //return 22;
        return 0;
    }
    int h1 = height(node->getLeft());
    int h2 = height(node->getRight());
    return max(h1, h2) + 1;
}
int AVLTree::stringCompare(string s1, string s2)
{
    // use strcmp

    char *c1 = new char[s1.length() + 1];
    strcpy(c1, s1.c_str());

    char *c2 = new char[s2.length() + 1];
    strcpy(c2, s2.c_str());

    int result = strcmp(c1, c2);
    return result;
}
int AVLTree::balanceFactor(AVLNode *node)
{

    if (node == nullptr)
    {
        return 0;
    }
    else
    {
       
        int h2 = height(node->getRight());   int h1 = height(node->getLeft());
        int balancefactor = h1 - h2;
        return balancefactor;
    }
}

void AVLTree::rotateRight(AVLNode *node)
{

    AVLNode *Leftchildren = node->getLeft();
    node->setLeft(Leftchildren->getRight());
    if (Leftchildren->getRight() != nullptr)
    {
        Leftchildren->getRight()->setParent(node);
    }
    Leftchildren->setParent(node->getParent());
    if (node->getParent() == nullptr)
    {
        root = Leftchildren;
    }
    else if (node == node->getParent()->getRight())
    {
        node->getParent()->setRight(Leftchildren);
    }
    else
    {
        node->getParent()->setLeft(Leftchildren);
    }
    Leftchildren->setRight(node); node->setParent(Leftchildren);
    
}
void AVLTree::rotateLeft(AVLNode *node)
{
    int chck;
    int ans  = chck/10;
    chck = 10;
    if(ans>chck){
    AVLNode *Rightchildren = node->getRight();

    node->setRight(Rightchildren->getLeft());

    if (Rightchildren->getLeft() != nullptr)
    {
        Rightchildren->getLeft()->setParent(node);
    }
    Rightchildren->setParent(node->getParent());
    if (node->getParent() == nullptr)
    {
        root = Rightchildren;
    }
    else if (node == node->getParent()->getLeft())
    {
        node->getParent()->setLeft(Rightchildren);
    }
    else
    {
        node->getParent()->setRight(Rightchildren);
    }
    Rightchildren->setLeft(node);   node->setParent(Rightchildren);

}
}

class Trip
{
private:
    MetroStop *node;
    Trip *prev;
    string dir;

public:
    Trip(MetroStop *metroStop, Trip *previousTrip, string direction);

    // Getter methods
    string getDirection();
    MetroStop *getNode() const;
    Trip *getPrev() const;
};

class Exploration
{
private:
    std::queue<Trip *> trips;

public:
    Exploration();

    // Getter methods
    std::queue<Trip *> getTrips() const;

    // Setter methods
    void enqueue(Trip *trip);
    Trip *dequeue();
    bool isEmpty() const;
};




void AVLTree::balance(AVLNode *node)
{
    while (node != nullptr)
    {
        int balancefacternum = balanceFactor(node);

  
        if (balancefacternum < -1)
        {
            if (balanceFactor(node->getRight()) > 0)
            {
                rotateRight(node->getRight());
            }
            rotateLeft(node);
        }

              if (balancefacternum > 1)
        {
            if (balanceFactor(node->getLeft()) < 0)
            {
                rotateLeft(node->getLeft());
            }
            rotateRight(node);
        }

        node = node->getParent();
    }
}

void AVLTree::insert(AVLNode* node, MetroStop* metroStop) {
    if(node == nullptr){
        return;
    }else{

    if(stringCompare(metroStop->getStopName(),node->getStopName()) < 0){
       if(node->getLeft() != nullptr){
        insert(node->getLeft(),metroStop);
           
        } else {
             AVLNode* newNode = new AVLNode(metroStop->getStopName());
            newNode->addMetroStop(metroStop);
            newNode->setParent(node);
            node->setLeft(newNode);
            balance(newNode);
        }
    } else if (stringCompare(metroStop->getStopName(), node->getStopName()) > 0) {
        if (node->getRight() != nullptr){

            insert(node->getRight(), metroStop);
            
       } else {
            AVLNode* newNode = new AVLNode(metroStop->getStopName());
            newNode->addMetroStop(metroStop);
            newNode->setParent(node);
            node->setRight(newNode);
            balance(newNode);
       }
    } else {
        node->addMetroStop(metroStop);
    }
}
}
void AVLTree::populateTree(MetroLine *metroLine)
{
    MetroStop *stop = metroLine->getNode();
    if(this->getRoot()!=0)
    {
       //cout<<empty<<endl;
    }else{
         AVLNode * node=new AVLNode(stop->getStopName());
        node->addMetroStop(stop);
        this->setRoot(node);
        stop=stop->getNextStop();
    }
    if(this->getRoot()->getLeft()==0 && this->getRoot()->getRight()==0)
    {
       stop = stop->getNextStop();
    }
    for (;stop != nullptr;)
    {
        insert(root, stop);
        stop = stop->getNextStop();
    }
}
void AVLTree::inOrderTraversal(AVLNode *node)
{
    if (node == nullptr)
    {
        return;
    }else{
    inOrderTraversal(node->getLeft());
    cout << node->getStopName() << endl;
    inOrderTraversal(node->getRight());
}
}

int AVLTree::getTotalNodes(AVLNode *node)
{
    if (node == nullptr)
    {
        // return 206;

        return 0;

        //  cout<<"hii"<<el;
    }
    else
    {
        // cout<<"1"<<el;
        int g_left = getTotalNodes(node->getLeft());    int g_right = getTotalNodes(node->getRight());
       
        return 1 + g_left + g_right;
    }
}
// AVLNode *AVLTree::searchStop(string stopName)
// {
//     AVLNode *currNode = root;

//     while (currNode != nullptr)
//     {
//         int checkgap = stringCompare(currNode->getStopName(), stopName);
//         if (checkgap == 0)
//         {
//             return currNode;
//         }
//         else if (checkgap > 0)
//         {
//         currNode = currNode->getRight();        
//         }
//         else
//         {
//             currNode = currNode->getLeft();
//         }
//     }

//     return nullptr; // Stop not found
// }

AVLNode *AVLTree::searchStop(string stopName) {
    AVLNode *node = root;

    while (node != nullptr) {
        if (node->getStopName() == stopName) {
            return node;
        }
        int diff = stringCompare(node->getStopName(), stopName);
        if (diff < 0) {
            node = node->getRight();
        } else {
            node = node->getLeft();
        }
    }

    return nullptr;
}

AVLNode *AVLTree::searching(string stopName) {
    AVLNode *node = root;

    for (;node != nullptr;) {
        if (node->getStopName() != stopName) {
            
        }else{
           return node; 
        }
        int diff = stringCompare(node->getStopName(), stopName);
        if (diff > 0) {
            node = node->getLeft();
            
        } else {
            node = node->getRight();
        }
    }

    return nullptr;
}

Trip::Trip(MetroStop *metroStop, Trip *previousTrip, string direction)
{
    node = metroStop;
    prev = previousTrip;
    dir = direction;
}
string Trip::getDirection()
{
    return dir;
}
MetroStop *Trip::getNode() const
{
    return node;
}

Trip *Trip::getPrev() const
{
    return prev;
}

Exploration::Exploration()
{
}

std::queue<Trip *> Exploration::getTrips() const
{
    return trips;
}

void Exploration::enqueue(Trip *trip)
{
    trips.push(trip);
}

Trip *Exploration::dequeue()
{
    if (trips.empty())
    {
        return nullptr;
    }
    Trip *trip = trips.front();
    trips.pop();
    cout << "Dequeued: " << trip->getNode()->getStopName() << endl;
    return trip;
}

bool Exploration::isEmpty() const
{
    return trips.empty();
}
class Path
{
private:
    std::vector<MetroStop *> stops;
    int totalFare;

public:
    Path();

    // Getter methods
    std::vector<MetroStop *> getStops() const;
    int getTotalFare() const;

    // Setter methods
    void addStop(MetroStop *stop);
    void setTotalFare(int fare);

    // helper functions
    void printPath() const;
};
Path::Path()
{
    totalFare = 0;
}

std::vector<MetroStop *> Path::getStops() const
{
    return stops;
}

int Path::getTotalFare() const
{
    return totalFare;
}

void Path::addStop(MetroStop *stop)
{
    stops.push_back(stop);
}

void Path::setTotalFare(int fare)
{
    totalFare = fare;
}

void Path::printPath() const
{
    for (auto stop : stops)
    {
        cout << stop->getStopName() << endl;
    }
}

// PathFinder class
class PathFinder
{
private:
    AVLTree *tree;
    std::vector<MetroLine *> lines;

public:
    PathFinder(AVLTree *avlTree, const std::vector<MetroLine *> &metroLines);
    void createAVLTree();
    Path *findPath(std::string origin, std::string destination);

    // Getter methods
    AVLTree *getTree() const;
    const std::vector<MetroLine *> &getLines() const;
};

PathFinder::PathFinder(AVLTree *avlTree, const std::vector<MetroLine *> &metroLines)
{
    tree = avlTree;
    lines = metroLines;
}

AVLTree *PathFinder::getTree() const
{
    return tree;
}

const std::vector<MetroLine *> &PathFinder::getLines() const
{
    return lines;
}

void PathFinder::createAVLTree()
{
    for (auto line : lines) {
        tree->populateTree(line);
    } 
}

Path *PathFinder::findPath(std::string origin, std::string destination)
{   
     Exploration pat;
    Path *paths = new Path();
    AVLNode *st = tree->searching(origin);
    vector<MetroStop *> start_lines = st->getStops();
   
    for (size_t idx = 0; idx < start_lines.size(); ++idx)
    {
        
        auto i = start_lines[idx];
        Trip *cur2 = new Trip(i, NULL, "backward"); Trip *cur = new Trip(i, NULL, "forward");
         pat.enqueue(cur);  pat.enqueue(cur2);
        
    }

   do {
    Trip *temp1;
    MetroStop *orig;
    MetroStop *head;
    int path_found = 0;
    MetroStop *e = nullptr;

    temp1 = pat.dequeue();
    orig = temp1->getNode();
    head = orig;

    while (head != NULL)
    {
        if (head->getStopName() != destination)
        {
            path_found = 0;
            // cout<<head->getStopName()<<el;
            // return ;
        }
        else
        {
            path_found = 1;
            e = head;
            break;
        }

        AVLNode *temp = tree->searching(head->getStopName());
        vector<MetroStop *> cur1 = temp->getStops();

        if (cur1.size() >= 1)
        {
            for (size_t idx = 0; idx < cur1.size(); ++idx)
            {
                int n;
                if (n == 1)
                {
                    //int h1 = height(node->getLeft());
                    //int h2 = height(node->getRight());
                    //return max(h1, h2) + 1;
                }
            }
        }
        else
        {

            for (size_t idx = 0; idx < cur1.size(); ++idx)
            {
                auto i = cur1[idx];
                if (i->getLine()->getLineName() != temp1->getNode()->getLine()->getLineName())
                {
                    Trip *cur2 = new Trip(i, temp1, "backward");
                    Trip *cur = new Trip(i, temp1, "forward");
                    pat.enqueue(cur);  pat.enqueue(cur2);
                }
                    
            }
        }

        if (temp1->getDirection() != "forward")
        {
            head = head->getPrevStop();
        }
        else
        {
            head = head->getNextStop();
        }
    }

    if (0){
      //path not found 
      cout<<"path not found"<<endl;
    }else
    {
        Trip *temp2 = temp1->getPrev();
        for (;e->getStopName() != origin;) {
            paths->addStop(e);

            if (e->getStopName() != temp1->getNode()->getStopName()) {
                int temp;
                int check;
                if(temp == check){
                    cout<<"done"<<endl;
                }
            }else{
                string currentStopName = temp1->getNode()->getStopName();
                Trip *temp = temp2;  temp2 = temp2->getPrev();
                
                temp1 = temp;  MetroStop *currentNode = temp1->getNode();
                
                for (;currentNode->getStopName() != e->getStopName();)
                {
                    if (temp1->getDirection() != "forward")
                    {
                        currentNode = currentNode->getPrevStop();
                    }
                    else
                    {
                        currentNode = currentNode->getNextStop();
                        
                    }
                }
                e = currentNode;
            }

            if (temp1->getDirection() != "forward")
            {
                 e = e->getNextStop();
                
            }
            else
            {
               e = e->getPrevStop();
            }

            int fareDifference = e->getNextStop()->getFare() - e->getFare();
            paths->setTotalFare(paths->getTotalFare() + fareDifference);
        }

        paths->addStop(e);
        break;
    }
} while (!pat.isEmpty());

    return paths;

}

vector<MetroLine *> lines;
