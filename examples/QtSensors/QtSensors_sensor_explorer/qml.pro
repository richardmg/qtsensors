TEMPLATE = aux

app.files = \
    info.json \
    $$files(*.qml) \
    icon.png \
    components \
    content

MT_SYSROOT=$$(MT_SYSROOT)
!isEmpty(MT_SYSROOT):EXAMPLES_PREFIX=/opt/mt/applications
!isEmpty(EXAMPLES_PREFIX) {
    app.path = $$EXAMPLES_PREFIX/com.nokia.mt.sensor_explorer
    INSTALLS = app
}

