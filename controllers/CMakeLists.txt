set(DIR ${CMAKE_CURRENT_LIST_DIR})
target_sources(swar
  PRIVATE
  "${DIR}/duelist.cpp"
  "${DIR}/duelist.h"
  "${DIR}/highbot.cpp"
  "${DIR}/highbot.h"
  "${DIR}/highclass.cpp"
  "${DIR}/highclass.h"
  "${DIR}/lowbot.cpp"
  "${DIR}/lowbot.h"
  "${DIR}/randombot.cpp"
  "${DIR}/randombot.h"
  "${DIR}/scorerecorder.h"
  "${DIR}/scorerecorder.cpp"
  "${DIR}/viewer.h"
)
