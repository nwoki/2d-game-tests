set(spritemovmentsettings_SRCS
    generalsettings.cpp
    playersettings.cpp
    spritemovementsettingsplugin.cpp
)

# set(spritemovmentqmlsettings_QMLFILES
#     ProductionTestTool/Settings/qmldir
# )


# QML Plugin
add_library(SpriteMovementSettings SHARED ${spritemovmentsettings_SRCS})

# qt5_use_modules(ProductionTestToolQmlSettings Core Qml)
qt5_use_modules(SpriteMovementSettings Core Qml)

file(COPY qmldir DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# # Install the plugin
# install(TARGETS ProductionTestToolQmlSettings
#         DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins/net/wearit/ProductionTestTool/Settings")
#
# # Install qmldir files
# install(FILES ${spritemovmentqmlsettings_QMLFILES}
#         DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins/net/wearit/ProductionTestTool/Settings")
