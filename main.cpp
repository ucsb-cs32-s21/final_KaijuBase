#include <iostream> 
#include <vector> 
#include <map>
#include <algorithm>
#include <climits>
#include "util.h"
#include "vec2.h"
#include "Jaeger.h"
#include "Kaiju.h"
#include "gameObj.h"
//Uncomment when ready
//#include "unitAttackVisitor.h"
//#include "moveVisitor.h"
  
using namespace std; 

/* helper function for distance - friend to vec2 */
inline float distance(const vec2 &a, const vec2 &b) {
    return sqrt((a.val[0]-b.val[0])*(a.val[0]-b.val[0]) + (a.val[1]-b.val[1])*(a.val[1]-b.val[1]));
}


int main() { 

 	vector< shared_ptr<gameObj> > somePlayers;

 	somePlayers.push_back(
		make_shared<Kaiju>(vec2(-1, 2), 123, "godzilla", "lazer"));
 	somePlayers.push_back(
		make_shared<Kaiju>(vec2(-2, 5), 16, "mothra","magic"));
 	somePlayers.push_back(
		make_shared<Kaiju>(vec2(-3, 0.1), 72, "kong", "brute force"));

    shared_ptr<gameObj> robot =
        make_shared<Jaeger>(vec2(0, 0), 93, "gipsy danger", "Raleigh", "Mako");

    //create two different types of visitors
    //Uncomment when ready
    //unitAttackVisitor oneHit;
    //moveVisitor move;

    //print initial Kaiju positions
    cout << "start: " << endl;
    for (auto player: somePlayers) {
        cout << player->getName() << " position: " << player->getLocation() << " power: " << player->getHealth() << endl;
    }

    //simulate 5 rounds of attack and movement
    for (int i=0; i < 5; i++ ) {

      cout << "**round " << i << endl;

      /* Uncomment when ready

      //move Jager and Kaijus
      robot->accept(move);
      cout << robot->getName() << " position: " << robot->getLocation() << endl;
      for (auto player: somePlayers) {
        player->accept(move);
        cout << player->getName() << " position: " << player->getLocation() << " power: " << player->getHealth() << endl;
      }

      //find the closest Kaiju
      double minD = LONG_MAX; 
      shared_ptr<gameObj> closest = nullptr;
      //find the closest Kaiju and call visit on it
      for (auto e: somePlayers) {
        double d = distance(robot->getLocation(), e->getLocation());
        if (d < minD ){
            minD = d;
            closest = e;
        }
      }

      if (closest != nullptr) {
          cout << "closest: " << closest->getName() << endl;
          closest->accept(oneHit);
      }

      //Jaeger always takes a hit (but can sheild)
      robot->accept(oneHit); 
      */
    }

    //sort the Kaiju by health
    sort(somePlayers.begin(), somePlayers.end(),
        [](shared_ptr<gameObj> l, shared_ptr<gameObj> r) {
            return l->getHealth() > r->getHealth();
        }
    );

    cout << "**Final stats based on health!: " << endl;
 	for (auto player: somePlayers) {
    	cout << player->getName() << " size: " << player->getSize() << " power: " << player->getHealth() << endl;
 	}
}
