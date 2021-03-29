/*
 *          File: employee.h
 *        Author: Robert I. Pitts <rip@cs.bu.edu>
 * Last Modified: April 8, 2000
 *         Topic: Introduction to Inheritance in C++
 * ----------------------------------------------------------------
 *
 * Employee class definition.
 */

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
  Employee(string theName, float thePayRate);

  string getName() const;
  float getPayRate() const;
  bool getSalaried() const;
  float pay(float hoursWorked) const;
  void  setName(string nme);
  void setPayRate(float pay);

protected:
  string name;
  float payRate;
  bool salary;
};

#endif /* not defined _EMPLOYEE_H */
