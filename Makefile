#############################################################################
# Makefile for building: untitled
# Generated by qmake (2.01a) (Qt 4.8.0) on: ?? 18. ??? 16:11:48 2012
# Project:  untitled.pro
# Template: app
# Command: e:\database\learning\software\qt_4.8\desktop\qt\4.8.0\mingw\bin\qmake.exe -spec ..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\win32-g++ CONFIG+=declarative_debug -o Makefile untitled.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = e:\database\learning\software\qt_4.8\desktop\qt\4.8.0\mingw\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: untitled.pro  ../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/win32-g++/qmake.conf ../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/qconfig.pri \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/modules/qt_webkit_version.pri \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/qt_functions.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/qt_config.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/exclusive_builds.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/default_pre.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/default_pre.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/debug.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/debug_and_release.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/default_post.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/default_post.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/declarative_debug.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/rtti.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/exceptions.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/stl.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/shared.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/warn_on.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/qt.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/thread.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/moc.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/win32/windows.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/resources.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/uic.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/yacc.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/lex.prf \
		../../../../Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/mkspecs/features/include_source_dir.prf \
		e:/Database/Learning/Software/Qt_4.8/Desktop/Qt/4.8.0/mingw/lib/qtmaind.prl
	$(QMAKE) -spec ..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\win32-g++ CONFIG+=declarative_debug -o Makefile untitled.pro
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\qconfig.pri:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\modules\qt_webkit_version.pri:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\qt_functions.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\qt_config.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\exclusive_builds.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\default_pre.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\default_pre.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\debug.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\debug_and_release.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\default_post.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\default_post.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\declarative_debug.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\rtti.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\exceptions.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\stl.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\shared.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\warn_on.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\qt.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\thread.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\moc.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\win32\windows.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\resources.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\uic.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\yacc.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\lex.prf:
..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\features\include_source_dir.prf:
e:\Database\Learning\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ..\..\..\..\Software\Qt_4.8\Desktop\Qt\4.8.0\mingw\mkspecs\win32-g++ CONFIG+=declarative_debug -o Makefile untitled.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
