/*************************************************************************
    > File Name: Context.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年01月07日 星期六 11时16分55秒
 ************************************************************************/

#include "Context.h"
#include "State.h"

Context::Context(){

}
Context::Context(State* state){
	this->_state = state;
}

Context::~Context(){
	delete _state;
}
void Context::OprationInterface(){
	_state->OperationInterface(this);
}
bool Context::ChangeState(State* state){
	this->_state = state;
	return true;
}
void Context::OperationChangState(){
	_state->OperationChangeState(this);
}
