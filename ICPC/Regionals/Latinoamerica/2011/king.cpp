#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl

using namespace std;

int hand[3];

int main() {
	while(true) {
		scanf("%d %d %d", &hand[0], &hand[1], &hand[2]);
		if((hand[0]|hand[1]|hand[2]) == 0) return 0;
		sort(hand, hand+3);
		if(hand[0] == hand[1] && hand[1] == hand[2]) { // set
			if(hand[0] == 13) puts("*");
			else printf("%d %d %d\n", (hand[2]+1), (hand[2]+1), (hand[2]+1));
		}
		else if(hand[0] == hand[1]) { // pair 1
			hand[2]++;
			if(hand[2] > 13) {
				hand[0]++, hand[1]++, hand[2] = 1;
			}
			sort(hand, hand+3);
			printf("%d %d %d\n", hand[0], hand[1], hand[2]);
		}
		else if(hand[1] == hand[2]) { // pair 2
			if(hand[0] == 12 && hand[1] == 13) {
				puts("1 1 1");
				continue;
			}
			do { 
				hand[0]++; 
				if(hand[0] > 13) {
					hand[0] = 1, hand[1]++, hand[2]++;
					break;
				}
			} while(hand[0] == hand[1]);
			sort(hand, hand+3);
			printf("%d %d %d\n", hand[0], hand[1], hand[2]);
		}
		else puts("1 1 2");
	}
}
