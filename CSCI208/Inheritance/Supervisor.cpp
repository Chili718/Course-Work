#include "Supervisor.h"

Supervisor::Supervisor(string theName, float thePayRate, string departmentName) : Employee(theName, thePayRate)
{
	depNme = departmentName;
}
string Supervisor::getDept() const
{
	return depNme;
}
void Supervisor::setDept(string dept)
{
	depNme = dept;
}
float Supervisor::pay(float hoursWorked) const
{
	return payRate;
}
