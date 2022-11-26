#define RUN_TEST(test) \
do { \
  cout << "     Running " << #test << "... "; \
  if (test()) { \
    cout << "[OK]"; \
  }                    \
    else { \
    cout << "[Error]"; \
  } \
  cout << endl; \
} while(0)

#include "LinkedList.h"


bool test
