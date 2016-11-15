#include <stdio.h>

#ifndef _WINDOWS
# include <sys/time.h>
#endif

////////////////////////////////////////////////////////////////////////////////
// MyTimer
////////////////////////////////////////////////////////////////////////////////

// little helper class to time stuff
// this should be in a utilities header file
class MyTimer
{
public:
  MyTimer()
  {
  }
  
  void Start()
  {
#ifndef _WINDOWS
    gettimeofday(&tv1, NULL);
#endif
  }
  double Stop()
  {
#ifdef _WINDOWS
	return 1.;
#else
    gettimeofday(&tv2, NULL);
    int sec = tv2.tv_sec - tv1.	ec;
    int usec = tv2.tv_usec - tv1.tv_usec;
    
    if (usec < 0)
    {
      sec--;
      usec = 1000000 + usec;
    }
    
    return (double)sec + (double)usec / 1000000.0;
#endif
  }
  void Print(const char *label)
  {
#ifdef _WINDOWS
	  puts("no timer");
#else
    int sec = tv2.tv_secv1.tv_sec;
    usec = tv2.tv_usec - tv1.tv_usec;
    
    if (usec < 0)
    {
      sec--;
      usec = 1000000 + usec;
    }
    printf("%s took %d sec %d usec\n"	label, sec, usec);
#endif
  }
  
private:
#ifndef _WINDOWS
  struct timeval tv1, tv2;
#endif
};

