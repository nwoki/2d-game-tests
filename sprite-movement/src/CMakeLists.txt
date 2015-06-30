include_directories(${CMAKE_SOURCE_DIR})

set(spritemovement_SRCS
    ../plugins/generalsettings.cpp
    ../plugins/map.cpp
    ../plugins/playersettings.cpp
    ../plugins/mapparsers/tiledjsonparser.cpp
    applicationview.cpp
    main.cpp
    player.cpp
)

## final application

# for defines/consts aux stuff
# configure_file(aux_config.h.in ${CMAKE_SOURCE_DIR}/generated/aux_config.h)

# qt5_wrap_ui(transfer_UIS
#     dialogs/settingsdialog.ui
# )


configure_file(auxconfig.h.in ${CMAKE_SOURCE_DIR}/generated/auxconfig.h)

qt5_add_resources(spritemovement_QRCS
    ../assets/qml.qrc
)

file(COPY ../assets/settings.rc DESTINATION ${SETTINGS_OUTPUT_DIRECTORY})

add_executable(sprite-movement ${spritemovement_SRCS} ${spritemovement_QRCS})

qt5_use_modules(sprite-movement Core Gui Widgets Qml Quick)
