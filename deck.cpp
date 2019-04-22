/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * Shuffle a deck with Mersenne Twister Engine
 *
 * MIT License
 *
 */

/* deck.cpp
 * A sample of a deck shuffled with MTE
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 08/10/2018 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <iostream>
#include <algorithm>
#include <random>


/* *** LOCAL PROTOTYPES (if applicable) ************************************************ */
using namespace std;


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */
typedef struct _card_t{
	short n;
	char suit;
}card_t;
 

/* *** FUNCTIONS *********************************************************************** */
int main(int argc, char *argv[])
{
	vector<card_t> deck = {{2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'}, {14, 'H'},
	                       {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'}, {14, 'D'},
	                       {2, 'C'}, {3, 'C'}, {4, 'C'}, {5, 'C'}, {6, 'C'}, {7, 'C'}, {8, 'C'}, {9, 'C'}, {10, 'C'}, {11, 'C'}, {12, 'C'}, {13, 'C'}, {14, 'C'},
	                       {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'}, {14, 'S'}
	                      };
	random_device randDev;
	mt19937 eng(randDev());
	auto printCard = [](card_t &c){
		char nC = '0';

		switch(c.n){
			case 10:
				nC = 'T';
				break;
			case 11:
				nC = 'J';
				break;
			case 12:
				nC = 'Q';
				break;
			case 13:
				nC = 'K';
				break;
			case 14:
				nC = 'A';
				break;
			default:
				nC = '0' + c.n;
		}
		cout << '[' << nC << ' ' << c.suit << ']' << endl;
	};

	shuffle(deck.begin(), deck.end(), eng);

	for_each(deck.begin(), deck.end(), printCard);

	return(0);
}
