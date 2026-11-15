#pragma once
#include <vector>

template<typename T>
class State
{
	virtual void OnEnter(T* owner, State* preState) = 0;
	virtual void OnUpdate(T* owner) = 0;
	virtual void OnExit(T* owner, State* nextState) = 0;
};

template<typename T>
class StateMachine
{
private:
	T* m_Owner;
	std::vector<State<T>*> m_States;
	int actualState;

public:
	void Update();
	void AddState(State<T>* newState) { m_States.push_back(newState); }
	
	/// <param name="nextState">Index in the vector</param>
	bool TryTransitionTo(int nextState);
};

template<typename T>
inline void StateMachine<T>::Update()
{
	m_States[actualState]->OnUpdate();
}

template<typename T>
inline bool StateMachine<T>::TryTransitionTo(int nextState)
{
	if (nextState > m_States.size())
	{
		actualState = nextState;
	}
	else
		return false;
	return true;
}
