set(spritemovement_SRCS
    main.cpp
    core.cpp
)


## final application

# for defines/consts aux stuff
# configure_file(aux_config.h.in ${CMAKE_SOURCE_DIR}/generated/aux_config.h)

# qt5_wrap_ui(transfer_UIS
#     dialogs/settingsdialog.ui
# )

qt5_add_resources(spritemovement_QRCS
    ../assets/qml.qrc
    ../assets/sprites.qrc
)

# add_executable(transfer ${transfer_SRCS} ${transfer_UIS} ${transfer_QRCS})
add_executable(sprite-movement ${spritemovement_SRCS} ${spritemovement_QRCS})

qt5_use_modules(sprite-movement Core Gui Widgets Qml Quick)



