#pragma once

#include <iostream>
/*
* Wrapper 클래스는 무언가를 포장하는 클래스라는 의미임
* C++에서는 프로그래밍 할 때 종종 기본 자료형들을 객체로써 다루어야 할 때가 있음
* 이럴 때, 기본 자료형들을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것을 Wrapper 클래스
* 
* 그러나, Wrapper 클래스를 사용할때 기존의 기본 자료형들에 존재하는 연산자를 재정의해야되는 것은
* 너무나도 귀찮은 일!!!
* 그래서, 타입 변환 연산자를 사용함
* 문법 : operator (변환 하고자 하는 타입) ()
*/
class Int
{
	int data;
	// some other data
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	
	operator int() { return data; }
};

