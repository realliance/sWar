set(DIR ${CMAKE_CURRENT_LIST_DIR})
target_sources(swar
  PRIVATE
    "${DIR}/statefunctions/battle.cpp"
    "${DIR}/statefunctions/collect.cpp"
    "${DIR}/statefunctions/declaration.cpp"
    "${DIR}/statefunctions/draw.cpp"
    "${DIR}/statefunctions/duel.cpp"
    "${DIR}/statefunctions/gameend.cpp"
    "${DIR}/statefunctions/gamestart.cpp"
    "${DIR}/statefunctions/regroup.cpp"
    "${DIR}/statefunctions/surrender.cpp"

    "${DIR}/card.cpp"
    "${DIR}/controllermanager.cpp"
    "${DIR}/event.cpp"
    "${DIR}/gamestate.cpp"
    "${DIR}/statecontroller.cpp"
)
