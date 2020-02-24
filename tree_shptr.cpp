#include <iostream>
#include <memory>
#include <vector>

class Node : public std::enable_shared_from_this<Node> {
public:
    int a;
    std::shared_ptr<Node> parent;
    std::vector<std::weak_ptr<Node>> kids;

    Node(int a) : a(a) {};

    ~Node() {
        std::cout << "Node with a = " << this -> a << " deleted" << std::endl;
    }

    void setParentAndChildrens(std::shared_ptr<Node> p, std::shared_ptr<Node> ch1, std::shared_ptr<Node> ch2) {
        this -> parent = p;
        p -> kids.push_back(shared_from_this());
        this -> kids.push_back(ch1);
        this -> kids.push_back(ch2);
        ch1 -> parent = shared_from_this();
        ch2 -> parent = shared_from_this();
    }
};


int main() {
    auto sp1 = std::make_shared<Node>(1);
    auto sp2 = std::make_shared<Node>(2);
    auto sp3 = std::make_shared<Node>(3);
    auto sp4 = std::make_shared<Node>(4);
    sp2 -> setParentAndChildrens(sp1, sp3, sp4);
}
