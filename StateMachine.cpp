#include "StateMachine.h"

namespace FlappyBirdGame
{
	/** 
	상태 추가 함수를 정의합니다. 
	State를 unique_ptr 객체로 메모리 관리를 합니다.
	*/
	void StateMachine::AddState(unique_ptr<State> newState, bool isReplacing)
	{
		/**
		상태를 추가하는 함수입니다. 새로운 상태를 추가합니다.
		this포인터 : 자기 자신의 객체를 가리키는 포인터 변수입니다. 써도 되고, 안써도 됩니다.
		현재 상태는 추가 상태입니다.
		*/
		this->_isAdding = true;
		/** 상태를 교체할지? */
		this->_isReplacing = isReplacing;
		/**
		unique_ptr는 유일한 소유권을 가지는 스마트 포인터입니다. _newState에 대입을 하지 못합니다.
		_newState에 unique_ptr의 소유권을 복사하지 않고 이전합니다.
		*/
		this->_newState = move(newState);
	}

	/** 상태 제거 함수를 정의합니다. */
	void StateMachine::RemoveState()
	{
		/** 상태 제거 함수입니다. 현재 상태는 제거 상태입니다. */
		this->_isRemoveing = true;
	}

	/** 상태 변경 함수를 정의합니다. */
	void StateMachine::ProcessStateChanges()
	{
		/** 만일 현재 제거상태이고 스택에 상태들이 쌓여있다면? */
		if (this->_isRemoveing && !this->_states.empty())
		{
			/** 맨 위의 상태를 제거합니다. */
			this->_states.pop();
			/**
			맨 위에 있는 상태를 제거했으니, 다시 스택에 상태들이 쌓여있는지 확인합니다.
			만일 스택에 상태들이 쌓여있다면?
			*/
			if (!this->_states.empty())
			{
				/** 스택의 맨 위에 있는 상태를 다시 시작합니다. */
				this->_states.top()->Resume();
			}
			/** 작업이 끝났으니 더이상 제거 상태가 아닙니다. */
			this->_isRemoveing = false;
		}
		/**
		상태변경 함수입니다.
		상태를 제거할 수도 있고, 상태를 추가할 수도 있습니다.
		상태를 추가해줍니다.
		*/
		/** 만일 현재 추가상태라면? */
		if (this->_isAdding)
		{
			/** 만일 스택에 상태들이 쌓여있다면? */
			if (this->_states.empty())
			{
				/** 만일 상태가 교체 상태라면? */
				if (this->_isReplacing)
				{
					/** 교체 상태이니 스택의 맨 위의 요소를 제거합니다. */
					this->_states.pop();
				}
				/** 그렇지 않고 만일 상태가 교체 상태가 아니라면? */
				else
				{
					/** 교체 상태가 아니니 스택의 맨 위의 상태를 잠시 멈춥니다. */
					this->_states.top()->Pause();
				}
			}
			/** 현재 추가 상태입니다. 현재 State를 소유권을 이전해서 스택에 쌓아놓습니다. */
			this->_states.push(move(this->_newState));
			/** 상황 종료입니다. 스택의 맨 위의 상태를 초기화(다음 상황을 대비해서 청소해줍니다.)합니다. */
			this->_states.top()->Init();
			/** 더 이상 추가 상태가 아닙니다. */
			this->_isAdding = false;
		}
	}

	/** 
	현재 상태를 가져오는 함수를 정의합니다.
	State는 unique_ptr로 메모리 관리를 합니다.
	unique_ptr객체로 메모리 관리가 되는 State 객체를 반환합니다.
	*/
	unique_ptr<State>& StateMachine::GetActiveState()
	{
		/**
		왜 C++에서는 포인터 변수보다 참조자를 더 많이 사용할까요?
		포인터 변수는 가리키던 객체를 변경할 수 있습니다. 동적으로 생성된 객체를 바꾸게 되면
		메모리 관리가 힘들 수 있습니다.
		참조자는 별칭입니다. 대상을 하나밖에 못 가리키고, 대상을 변경할 수 없습니다. 
		따라서 메모리 관리가 쉽습니다.
		*/
		/** 스택 컨테이너의 맨 위의 요소를 가져옵니다. */
		return this->_states.top();
	}
}
