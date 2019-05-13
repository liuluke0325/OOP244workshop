/*
Author: hsueh chih liu
student number : 116131186
date:3/17/2019
milestone2
*/

#ifndef  AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace ama {

	class ErrorState {

		char * addOfMessage; // pointer, store the address of the message,

	public:
		// one/no argument constructor
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();

		//this function return true if the current instance is storing a valid message
		operator bool() const;

		// overloaded assignment operator not a copu constructor
		ErrorState& operator=(const char* pText);

		//stores a copy the text received in the parameter.
		void message(const char* pText);

		//this query returns the address of the message stored in the current object.
		const char* message() const;
	};

	//helper : Prints the text stored in an ErrorState object to a stream.
	std::ostream& operator<< (std::ostream& os, const ErrorState& src);




}//end of namespace
#endif // ! AMA_ERRORSTATE_H



