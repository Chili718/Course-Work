!
!Name:Jon Tice
!
!Title:Program 3 - Fortran
!
!Description:User inputs an amount of numbers to then obtain the average of 
!the collection of numbers
!
!Class:CSCI431
!
!Date:2/18/2018      
!

      program prog3
      !the size is for the size of the array and will also be used in the loop 
      !that will collect the numbers from the user
      !error is for handling the io errors
      integer :: size, error = 0
      !answer will hold the users decision to run the program and or run it again
      character :: answer
      !average will hold the average of the collection of numbers given by the user
      real :: average 
      !the dynamic array that will hold the colleciton of numbers
      real, dimension(:), allocatable :: ray
    
      !ask the user if they would like to run the program 
      print*,"Would you like to find the average of a collection"
      print*,"of numbers? 'Y' for yes or 'N' for no."

      read(*,*) answer
      
      do while(answer == 'Y')

      !Prompt the user to enter the amount of integers the would like to average
      !this must be done for the loop that will be used to gain the users input
      !and the array that will be used to hold all of it
      print*,"Please enter the amount of you would like to average: "
      !obtain the number from the user for use in the loop and function
      read(*,*, iostat=error) size
      !error checking using iostat, if error is not zero an error was generated
      if(error /= 0) then
         write(*,*)"Valid integer not entered. Exiting"
         stop
      endif

      !minor check(s) for valid but non-valid input i.e. zero and negative numbers 
      !for the size handled accordingly
      if(size < 0) then
         write(*,*)"Cannot find the average of ", size, " numbers"
         stop
      else if(size == 0) then
         write(*,*)"The average of ", size, " numbers is 0."
         stop
      end if

      write(*,*)"Please enter ",size," numbers: "
      !dynamically create the array because declaration statements cannot follow
      !a normal statement
      allocate(ray(size))
      !get size number of numbers from the user 
      do i = 1, size
         write(*,*)"Enter number ", i, ": "
         read(*,*, iostat=error) ray(i)
         !error checking using iostat, if error is not zero an error was generated
         if(error /= 0) then
            write(*,*)"Valid integer not entered. Exiting"
            stop
         endif
      end do
      !use the average function to obtain the average
      average = avg(ray, size)
      !print the average of the numbers
      write(*,*)"The average of the numbers entered is: ", average
      !deallocate the space that we no longer need
      deallocate(ray)
      !prompt the user if they would like to run the program again
      print*,"Would you like to find the average of another collection"
      print*,"of numbers? 'Y' for yes or 'N' for no."

      read(*,*) answer

      enddo
      
      end program prog3

!
!Function Name:avg
!
!Description:Takes an array and finds the average of the integers inside
!
!Parameters:tay(An array that the average will be determined from), sze(size of the array)
!
!Return Values:aver(the average of the numbers in the array)
!
      function avg(tay, sze) result(aver)
      !determine the use of the parameters and return value
      !(if they will be input or returned)
      integer, intent(in) ::sze
      real, intent(in) ::tay(sze)
      real ::aver
      !sum all the number in the array
      do i = 1, sze
         aver = aver + tay(i)
      end do

      aver = aver / sze

      end function avg

