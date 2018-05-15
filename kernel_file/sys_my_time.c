#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/linkage.h>

asmlinkage int sys_my_time(int isStart, unsigned long *start_sec,
                           unsigned long *start_nsec, unsigned long *end_sec,
                           unsigned long *end_nsec, int *pid) {
  struct timespec t;
  ktime_t currtime;

  currtime = ktime_ge();
  t = ktime_to_timespec(currtime);

  if (isStart) {
    *start_sec = t.tv_sec;
    *start_nsec = t.tv_nsec;
  } else {
    *end_sec = t.tv_sec;
    *end_nsec = t.tv_nsec;
    printk(
        "<0>"
        "[project1] %d %lu.%09lu %lu.%09lu\n",
        *pid, *start_sec, *start_nsec, *end_sec, *end_nsec);
  }
  
  return 0;
}
