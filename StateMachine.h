#pragma once

/** 문자열 관련*/
#include <string>
/** SFML Graphics 관련*/
#include <SFML/Graphics.hpp>

/** unique_ptr를 사용하기 위한 스마트 포인터 관련*/
#include <memory>
/**
stack 컨테이너 관련
State를 unique_ptr로 메모리 관리를 하는데, State를 stack컨테이너에 쌓습니다.
*/
#include <stack>
/** State 추상 클래스에 접근하기 위한 */
#include "State.h"
/**
<> include : C++에서 제공하는 기본 라이브러리
"" include : 커스텀 라이브러리
*/

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;
/** SFML 라이브러리 사용합니다. */
using namespace sf;

namespace FlappyBirdGame
{
	class StateMachine
	{
		/**
		unique_ptr는 C++에서 제공하는 스마트 포인터입니다.

		unique_ptr : 객체의 유일한 소유권을 가지는 스마트 포인터입니다.
		shared_ptr : 객체간의 공유가 가능한 스마트 포인터입니다.
		weak_ptr : shared_ptr의 순환참조 문제를 해결한 약한 참조의 스마트 포인터입니다.

		unique_ptr를 사용하면 동적으로 힙 영역에 할당된 객체에 대한 유일한 소유권을 갖고
		unique_ptr 객체가 사라지면 자동으로 해당 객체를 해체하게 됩니다. 
		소유권을 갖기 때문에 객체를 소유하는 unique_ptr는 동시에 2개가 되어서는 안됩니다.
		만일 둘이 된 경우 소멸하는 과정에서 double free 에러가 발생합니다.
		*/

		/**
		하나의 포인터만이 해당 객체를 가리킬 수 있도록 합니다.
		객체의 소멸 권한을 소유권을 가진 한 포인터 변수에게만 주기 때문에
		프로그래머가 원하는 곳에서 객체를 소멸시킬 수 있습니다.
		*/

		/**
		StateMachine : 다양한 상태를 추가하고, 제거하고, 변경하는 상태 매니저 클래스입니다.
		*/

	public:
		/**
		생성자 함수를 정의해줍니다. 
		이미 정의해 주었기 때문에 구현부에서 다시 정의해줄 필요가 없습니다.
		*/
		StateMachine() {}

		/**
		소멸자 함수를 정의해줍니다.
		이미 정의해주었기 때문에 구현부에서 다시 정의해줄 필요가 없습니다.
		*/
		~StateMachine() {}

		/** 상태 추가 함수의 원형을 선언합니다. 구현부에서 정의해 주어야 합니다. */
		void AddState(unique_ptr<State> newState, bool isReplacing = true);
		/** 상태 제거 함수의 원형을 선언합니다. */
		void RemoveState();
		/** 상태 변경 함수의 원형을 선언합니다. */
		void ProcessStateChanges();
		/**
		현재 상태를 가져오는 함수의 원형을 선언합니다.
		unique_ptr<State> newState : State를 unique_ptr로 메모리 관리를 합니다.
		unique_ptr<State> 반환 타입으로 해주어야 합니다.
		C++에서는 포인터 연산자보다 참조자를 많이 씁니다.
		*/
		unique_ptr<State>& GetActiveState();

	private:
		/**
		객체 지향 언어에서는 멤버 변수 보호를 위해서 멤버 변수는 private 접근 지정자 안에 둡니다.
		*/

		/**
		상태들을 stack 컨테이너에 쌓아놓기 위한 변수를 선언합니다.
		스택은 쌓는거라서 맨 나중에 쌓인게 맨 위에 있습니다.
		top() : 맨 위에 있는 요소를 반환합니다.
		pop() : 맨 위에 있는 요소를 제거합니다.
		*/
		stack<unique_ptr<State>> _states;
		/** 새로운 상태를 저장할 변수를 선언합니다. */
		unique_ptr<State> _newState;
		/** 상태를 없앨 것인지 판별해줄 불리언 변수를 선언합니다. */
		bool _isRemoveing;
		/** 상태를 추가할 것인지 판별해줄 불리언 변수를 선언합니다. */
		bool _isAdding;
		/** 상태를 교체할 것인지 판별해줄 불리언 변수를 선언합니다. */
		bool _isReplacing;
	};
}