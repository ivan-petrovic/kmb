#include <cassert>
#include "engine/constants.h"

int main () {
  
  assert(constants::MAX_NUMBER == 39);
  assert(constants::MAX7 == 15380937);
  assert(constants::MAX6 ==  3262623);
  assert(constants::MAX5 ==   575757);
  assert(constants::MAX4 ==    82251);
  assert(constants::MAX3 ==     9139);
  assert(constants::MAX2 ==      741);
  assert(constants::MAX1 ==       39);

  return 0;
}
