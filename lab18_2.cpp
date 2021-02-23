#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect* a, Rect* b){

	double minY = abs(min(0.0,min(a->y,b->y)));
	double minX = abs(min(0.0,min(a->x,b->x)));


	double aT = a->y + minY;
	double bT = b->y + minY;

	double aL = a->x + minX;
	double bL = b->x + minX;

	double aR = aL+a->w;
	double bR = bL+b->w;

	double aB = aT-a->h;
	double bB = bT-b->h;

	double overlapX = 0;
	double overlapY = 0;


	if(aR < bR && aL > bL && aT < bT && aB > bB){
		return abs(a->w*a->h);
	}else if(bR < aR &&  bL > aL && bT < aT && bB > aB){
		return abs(b->w*b->h);
	}

	if( (aR > bL && aR < bR) ){
		overlapX = aR - max(aL,bL);
	}else if( (bR > aL && bR < aR) ){
		overlapX = bR - max(aL,bL);
	}

	if( (aB < bT && aB > bB)){
		overlapY = min(aT,bT)-aB;
	}else if( (bB < aT && bB > aB) ){
		overlapY = min(bT,aT)-bB;
	}


	return abs(overlapX*overlapY);

}

int main(){
	Rect a,b;
	cin >> a.x >> a.y >> a.w >> a.h;
	cin >> b.x >> b.y >> b.w >> b.h;

	cout << overlap(&a,&b);

	return 0;
}