#include <iostream>
using namespace std;

class Weapon {
   public:
   virtual loadFeatures() { cout << "Loading weapon features.\n"; }
};

class Bomb : public Weapon {
   public:
   void loadFeatures() { cout << "Loading bomb features.\n"; }
};

class Gun : public Weapon {
   public:
   void loadFeatures() { cout << "Loading gun features.\n"; }
};

class Loader{
	public:
		void loadD(Weapon *w){
			w->loadFeatures();
		}
};

int main() {
   Weapon *w = new Bomb;
   Loader l;
   l.loadD(w);
//   b->loadFeatures();
//   g->loadFeatures();
   system("pause");

   return 0;
}
