#include <iostream>
#include <string>
#include <strings.h>

class Spear {
public:
  Spear(const std::string &name_, const std::string &icon_)
      : name(name_), icon(icon_) {
    std::cout << "Spear()" << std::endl;
  }
  Spear() = default;
  virtual void openFire() const = 0;
  virtual ~Spear() { std::cout << "~Spear()" << std::endl; }

protected:
  std::string name;
  std::string icon;
};
// 先调用父类，再调用子类构造函数 析构函数反过来
class FireSpear : public Spear {
public:
  FireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) {
    std::cout << "FireSpear()" << std::endl;
  }
  virtual void openFire() const override {
    std::cout << "FireSpear::openFire" << std::endl;
  }
  virtual ~FireSpear() { std::cout << "~FireSpear()" << std::endl; }

private:
  int i;
};
class FireFireSpear : public Spear {
public:
  FireFireSpear(const std::string &name_, const std::string &icon_, int i_)
      : Spear(name_, icon_), i(i_) {
    std::cout << "FireSpear()" << std::endl;
  }
  virtual void openFire() const override {
    std::cout << "FireSpear::openFire" << std::endl;
  }
  virtual ~FireFireSpear() { std::cout << "~FireSpear()" << std::endl; }

private:
  int i;
};
void OpenFire(Spear *pSpear) {
  pSpear->openFire();
  delete pSpear;
}

class IceSpear : public Spear {
public:
  IceSpear(const std::string &name_, const std::string &icon_)
      : Spear(name_, icon_) {
    std::cout << "FireSpear()" << std::endl;
  }

  virtual void openFire() const override {
    std::cout << "FireSpear::openFire" << std::endl;
  }
};
int main() {

  // Spear *pSpear = new Spear();
  // FireSpear fireSpear("asd", "asd", 10);
  // fireSpear.openFire();
  // pSpear->openFire();
  // OpenFire(new FireSpear("asd", "asd", 10));
  Spear *pSpear = new FireSpear("asd", "asd", 20);
  Spear *pSpear3 = new FireSpear("asd", "asd", 20);
  Spear *pSpear1 = new IceSpear("asd", "asd");
  Spear *pSpear2 = new FireSpear("asd", "asd",234);
  Spear *pSpear4 = new FireFireSpear("asd", "asd",234);
  std::cout << typeid(*pSpear3).name() << std::endl;
  std::cout << typeid(*pSpear4).name() << std::endl;
  std::string typenames = typeid(*pSpear4).name(); 
  size_t indexs = typenames.find_first_not_of("0123456789");
  std::cout << std::string(typeid(*pSpear4).name()).substr(indexs) << std::endl;
  if (std::string(typeid(*pSpear).name()) == "class FireSpear") {
    std::cout << std::string(typeid(*pSpear).name()) << std::endl;

    FireSpear *pFireSpear = dynamic_cast<FireSpear *>(pSpear);
    if (pFireSpear) {
      std::cout << "cast FireSpear success" << std::endl;
    }
  }
  delete pSpear;
  // Spear spear;
  // Spear * pSpear1 = FireSpear();
}
