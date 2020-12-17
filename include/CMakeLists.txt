set(DIR ${CMAKE_CURRENT_LIST_DIR})
target_sources(swar
    PRIVATE
    "${DIR}/card.h"
    "${DIR}/controllermanager.h"
    "${DIR}/deck.h"
    "${DIR}/event.h"
    "${DIR}/gamestate.h"
    "${DIR}/playercontroller.h"
    "${DIR}/settings.h"
    "${DIR}/statefunctions.h"
)
