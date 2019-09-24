import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "DesignerComponents"
    Depends { name: "Qt"; submodules: ["core","gui-private","widgets-private","designer-private","xml"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5DesignerComponentsd"
    libNameForLinkerRelease: "Qt5DesignerComponents"
    libFilePathDebug: "C:/Qt/5.12.2/mingw73_64/lib/libQt5DesignerComponentsd.a"
    libFilePathRelease: "C:/Qt/5.12.2/mingw73_64/lib/libQt5DesignerComponents.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","debug_and_release","shared","release","no_plugin_manifest","win32","mingw","gcc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","compile_examples","largefile","optimize_debug","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","internal_module","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c++1z","c99","c11","qt_install_headers","need_fwd_pri","qt_install_module","debug_and_release","build_all","skip_target_version_ext","compiler_supports_fpmath","release","ReleaseBuild","Release","build_pass","have_target","dll","exclusive_builds","no_autoqmake","thread","designer_defines","uic","opengl","moc","resources","moc","resources"]
    cpp.defines: ["QT_DESIGNERCOMPONENTS_LIB"]
    cpp.includePaths: ["C:/Qt/5.12.2/mingw73_64/include","C:/Qt/5.12.2/mingw73_64/include/QtDesignerComponents","C:/Qt/5.12.2/mingw73_64/include/QtDesignerComponents/5.12.2","C:/Qt/5.12.2/mingw73_64/include/QtDesignerComponents/5.12.2/QtDesignerComponents"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["designercomponents-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
