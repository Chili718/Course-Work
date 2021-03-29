#ifndef _SUPERVISOR_H
#define _SUPERVISOR_H

#include "employee.h"

class Supervisor : public Employee {
	public:
  		Supervisor(string theName, float thePayRate, string departmentName);
  		string getDept() const;
 		void setDept(string);
		float pay(float hoursWorked) const;
	protected:
 		 string depNme;
};

#endif
