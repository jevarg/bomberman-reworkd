#ifndef _MUTEX_H_
# define _MUTEX_H_

# define HAVE_STRUCT_TIMESPEC
# include <pthread.h>

class Mutex
{
public:
  Mutex();
  ~Mutex();

  void			lock();
  void			unlock();
  pthread_mutex_t	*getMutexPtr();

private:
  pthread_mutex_t	_mutex;
  volatile bool		_isLocked;
};

#endif /* _MUTEX_H_ */
