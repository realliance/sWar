set(DIR ${CMAKE_CURRENT_LIST_DIR})
target_sources(swar
  PRIVATE
  "${DIR}/highbot.cpp"
  "${DIR}/highbot.h"
  "${DIR}/lowbot.cpp"
  "${DIR}/lowbot.h"
  "${DIR}/viewer.h"
)
